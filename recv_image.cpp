#include "recv_image.h"
#include "ui_recv_image.h"
#include "app_datapackage.h"
#include <QDebug>
#include <QPainter>
#include <QImage>
#include "pcommunication.h"
#include "time.h"
#include <QMessageBox>
#include "rs.h"

extern int selfNodeID;

recv_image::recv_image(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recv_image)
{
    ui->setupUi(this);
//    imageTemp = new QImage;
    setWindowTitle(QString("node") + QString::number(selfNodeID) + QString("recv image"));
    connect(ui->btn_save, SIGNAL(clicked(bool)), this, SLOT(saveImage()));
    connect(ui->btn_SaveAs, SIGNAL(clicked(bool)), this, SLOT(saveImageAS()));
    connect(ui->btn_emptyTemp, SIGNAL(clicked(bool)), this, SLOT(emptyTemp()));
}

recv_image::~recv_image()
{
    delete ui;
}
void recv_image::emptyTemp(){
    delete imageTemp;
    imageTemp = NULL;
    Code_K = 0;
}

void recv_image::handleImageHeader(ImageHeader *p_package_recv){
//*********************recv image as a file **********************
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    using namespace std;
//    cout<<"recv header "<<endl;
    QFile file(QString::number((p_package_recv->PictureID)));
    QString qstr = QString::number(p_package_recv->PictureID);
    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(this,tr("Error"),QString("open %1 fail.").arg(qstr),QMessageBox::Ok);
        return;
    }
    uint8_t *p = (uint8_t*)p_package_recv->data_buffer;
    pictureIDTemp = p_package_recv->PictureID;
    uint width, height;
    for(int i = 0; i < PICTUERHEADER_PACKAGE_SIZE;i++){
        if(*(p + i) == 255 && *(p + i + 1) == 192){
            cout<<"i  "<<i<<endl;
            cout<<*(p + i +1)<<" "<<*(p + i + 2)<<" "<<*(p + i +3)<<" "<<*(p + i +4)<<" "<<*(p + i +5)<<" "<<*(p + i +6)<<" "<<*(p + i +7)<<" "<<*(p + i +8)<<" "<<endl;
            height = (*(p + i + 5)) * 256 + *(p + i + 6);
            width = (*(p + i + 7)) * 256 + *(p + i + 8);
            break;
        }
    }
    this->setGeometry(0 , 0, width + 100, height);
    ui->label->setGeometry(0, 0, width, height);
    ui->btn_save->setGeometry(width + 10, 0, 90, 30);
    ui->btn_SaveAs->setGeometry(width + 10, 60, 90, 30);
    ui->btn_emptyTemp->setGeometry(width + 10, 120, 90, 30);
    ui->label->resize(width, height);
    cout<<"height : "<<height<<" width : "<<width<<endl;

    QByteArray writeBuff;
    writeBuff.append(p_package_recv->data_buffer, p_package_recv->DataSize);
    file.seek(p_package_recv->OffSet);
    file.write(writeBuff, p_package_recv->DataSize);
    file.close();
    ui->label->setPixmap(QString::number(p_package_recv->PictureID));
    this->show();
    cout<<"write "<<p_package_recv->DataSize<<" Byte at"<<p_package_recv->OffSet<<" into file"<<endl;
}

void recv_image::handleImageData(ImageData *p_package_recv){
//*********************recv image as a file **********************
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    using namespace std;

//    cout<<"recv header "<<endl;
    QFile file(QString::number((p_package_recv->PictureID)));
    QString qstr = QString::number(p_package_recv->PictureID);
    if(!file.open(QIODevice::ReadWrite)){
        QMessageBox::information(this,tr("Error"),QString("open %1 fail.").arg(qstr),QMessageBox::Ok);
        return;
    }
    uint8_t *p = (uint8_t*)p_package_recv->data_buffer;


    for(int i = 0; i < PICTUERDATA_PACKAGE_SIZE ; i++){
        if(*(p + i) == 0xff && *(p + i + 1) == 0xd9){ // ffd9
            Code_K = ceil(p_package_recv->OffSet / float(PICTUERDATA_PACKAGE_SIZE));
            cout<<"code_k = "<<Code_K<<endl;
            break;
        }
    }



    QByteArray writeBuff;
    writeBuff.append(p_package_recv->data_buffer, p_package_recv->DataSize);
    file.seek(p_package_recv->OffSet);
    file.write(writeBuff, p_package_recv->DataSize);
    file.close();

    ui->label->setPixmap(QString::number(p_package_recv->PictureID));
    this->show();
    cout<<"write "<<p_package_recv->DataSize<<" Byte at"<<p_package_recv->OffSet<<" into file "<<QString::number(p_package_recv->PictureID)<<endl;
}

void recv_image::saveImage(){
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    using namespace std;
// use as decode
    decodeFile(QString::number(pictureIDTemp).toStdString(), PICTUERDATA_PACKAGE_SIZE, Code_K);



    ui->label->setPixmap(QString::number(pictureIDTemp) + QString(".repair"));
    if(pictureIDTemp == 256){
    time_t t;
    t = time(NULL);
    QString fileName =QString::number(tmpSourceID) + " to " +
            QString::number(PCommunication::getInstance()->p_UserMainWindow->GetSelfNodeID()) + ctime(&t);
    imageTemp->save(fileName + ".jpg");
    PCommunication::getInstance()->p_UserMainWindow->RecvMessageHandler(fileName + "jpg", tmpSourceID);
    cout<<"save "<<fileName.toStdString().c_str() <<endl;


    } else {
        QMessageBox::information(this,tr("Warning"),tr("保存成功"),QMessageBox::Ok);
    }
}

void recv_image::saveImageAS(){
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    using namespace std;

    QString fileName = QFileDialog::getSaveFileName(this, tr("save as "), "", "");

    if(!fileName.isEmpty()){
        if(pictureIDTemp != 256){
            QDir dir;
            QString oldFileName = /*dir.currentPath() +  QString("/") +*/QString::number(pictureIDTemp);
            QFile file(oldFileName);
            if(!file.open(QIODevice::ReadOnly)){
                QMessageBox::information(this,tr("Warning"),tr("Open file failed!"),QMessageBox::Ok);
                return;
            }
            cout<<"old file "<<oldFileName.toStdString().c_str()<<endl;
            QByteArray temp = file.readAll();

            QFile newFile(fileName);
            if(!newFile.open(QIODevice::ReadWrite)){
                QMessageBox::information(this,tr("Warning"),tr("Open file failed!"),QMessageBox::Ok);
                return;
            }
            newFile.seek(0);
            newFile.write(temp, file.size());
            newFile.close();

            cout<<"save new file!"<<fileName.toStdString().c_str()<<"old size "<<file.size()<<"temp size : "<<temp.size()<<" new size : "<<newFile.size()<<endl;
        } else {
        imageTemp->save(fileName + ".jpg");
        PCommunication::getInstance()->p_UserMainWindow->RecvMessageHandler(fileName + "jpg", tmpSourceID);
        }
    } else {
        QMessageBox::information(this,tr("Warning"),tr("文件名不能为空 !"),QMessageBox::Ok);
    }
}

void recv_image::recvimage(ImagePackage *p_package_recv){
//*****************************use pix to fill the image, useless now******************************
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    using namespace std;

    int width = p_package_recv->ImageWidth;
    int height = p_package_recv->ImageHeight;

    QImage white(width, height, QImage::Format_RGB32);
    white.fill(Qt::black);

    if(imageTemp == NULL){
        tmpSourceID = p_package_recv->SourceID;
        imageTemp = new QImage(width, height, QImage::Format_ARGB32);
        imageTemp->fill(Qt::white);
        this->setGeometry(0 , 0, width + 100, height);
        ui->label->setGeometry(0, 0, width, height);
        ui->btn_save->setGeometry(width + 10, 0, 90, 30);
        ui->btn_SaveAs->setGeometry(width + 10, 60, 90, 30);
        ui->btn_emptyTemp->setGeometry(width + 10, 120, 90, 30);

        cout<<"width : "<<imageTemp->width()<<" height : "<<imageTemp->height()<<endl;
        ui->label->resize(p_package_recv->ImageWidth, p_package_recv->ImageHeight);

    }

    unsigned int *rgb = (unsigned int*)p_package_recv->data_buffer;
    int pixTab = p_package_recv->SerialNum * PICTUER_PACKAGE_SIZE / sizeof(int);
    cout<<"handle Num : "<<(int)p_package_recv->SerialNum<<endl;

    for(int i = 0; i < PICTUER_PACKAGE_SIZE /sizeof(int); i++){
        imageTemp->setPixel((pixTab + i) % width, (pixTab + i) / width, qRgb(qRed( *(rgb + i)), qGreen( *(rgb + i)), qBlue( *(rgb + i))));

    }

    ui->label->setPixmap(QPixmap::fromImage(*imageTemp));
    this->show();
    if(p_package_recv->SerialNum == ceil(height * width / (PICTUER_PACKAGE_SIZE / sizeof(int)))){
        saveImage();
        QMessageBox::information(this,tr("Warning"),tr("自动保存"),QMessageBox::Ok);
    }

}

void recv_image::showTestPicture(){
//************only for test, useless now***************
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    using namespace std;
    cout<<"show begin "<<endl;
    QImage white(210, 173, QImage::Format_Indexed8);
    white.fill(Qt::black);
    ui->label->setPixmap(QPixmap::fromImage(white));
}
