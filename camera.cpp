#include "camera.h"
#include "ui_camera.h"
#include <QMessageBox>
#include <QSize>
#include <QDebug>
#include "pcommunication.h"


Camera::Camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);

    camera=new QCamera(this);
    viewfinder=new QCameraViewfinder(this);
    imageCapture=new QCameraImageCapture(camera);

    ui->horizontalLayout->addWidget(viewfinder);
    //ui->label->setScaledContents(true);

    camera->setViewfinder(viewfinder);
    //camera->start();

    connect(ui->pushButton_close,SIGNAL(clicked(bool)),this,SLOT(on_pushbutton_close_clicked()));
    connect(ui->pushButton_capture,SIGNAL(clicked(bool)),this,SLOT(captureImage()));
    connect(ui->pushButton_send,SIGNAL(clicked(bool)),this,SLOT(saveImage()));
    connect(imageCapture, SIGNAL(imageCaptured(int,QImage)), this, SLOT(displayImage(int,QImage)));
    connect(this->camera, SIGNAL(error(QCamera::Error)), this, SLOT(isOpenCamera()));
//    connect(this, SIGNAL(sendjpgfilename(QString,int,int)), PCommunication::getInstance()->p_UserMainWindow, SLOT(sendPicture(QString,int,int)));
    connect(this, SIGNAL(sendjpgfilename(QString,int,int)), PCommunication::getInstance()->p_UserMainWindow, SLOT(sendQimagePicture(QString,int,int)));
}

Camera::~Camera()
{
    delete ui;
}

void Camera::on_pushbutton_close_clicked()
{
    camera->stop();
    camera->unload();
    this->close();
}

void Camera::captureImage()
{
    imageCapture->capture();
}

void Camera::displayImage(int testint,QImage image)
{
    QSize picSize(200,200);
    QPixmap pixmap = QPixmap::fromImage(image);
    //将pixmap缩放成picSize大小然后保存在scaledPixmap中 按比例缩放:
    QPixmap scaledPixmap = pixmap.scaled(picSize, Qt::KeepAspectRatio);
    ui->label->setPixmap(scaledPixmap);
}

void Camera::saveImage()
{
    QString fileName=QFileDialog::getSaveFileName(this, tr("save file"), QDir::currentPath(), tr("jpegfile(*.jpg)"));//QDir::homePath()
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,tr("Warning"),tr("SaveImage file failed! fileName is NULL."),QMessageBox::Ok);
        return;
    }
    const QPixmap* pixmap=ui->label->pixmap();
    fileName = fileName+QString(".jpg");
    if(pixmap)
    {
        pixmap->save(fileName);
        qDebug()<<fileName;
        QMessageBox::information(this,tr("Information"),QString("save image as")+fileName,QMessageBox::Ok);
    }
    emit sendjpgfilename(fileName, targetNode, selfNode);
}

void Camera::start_camera()
{
    camera->load();
    camera->start();
}
void Camera::isOpenCamera(){

    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;
    cout<<"open camera fail"<<endl;
}

int Camera::getTargetID(){
    return targetNode;
}
void Camera::setTargetAndSource(int self, int target){
    targetNode = target;
    selfNode = self;
}
