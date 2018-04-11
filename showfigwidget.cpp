#include "showfigwidget.h"
#include "ui_showfigwidget.h"
#include <QMessageBox>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include "app_datapackage.h"
#include "pcommunication.h"

ShowFigWidget::ShowFigWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowFigWidget)
{
//    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    connect(ui->pushButton_close,SIGNAL(clicked(bool)),this,SLOT(on_pushbuttonclose_clicked()));
    connect(ui->pushButton_open,SIGNAL(clicked(bool)),this,SLOT(on_pushbuttonopen_clicked()));
    connect(ui->pushButton_send, SIGNAL(clicked(bool)), this, SLOT(sendPicture()));    
}

ShowFigWidget::~ShowFigWidget()
{
    delete ui;
}

void ShowFigWidget::on_pushbuttonclose_clicked()
{
    this->close();
    this->~ShowFigWidget();
}

void ShowFigWidget::on_pushbuttonopen_clicked()
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;

    QString fileName=QFileDialog::getOpenFileName(this, tr("open file"), QDir::currentPath(), tr("jpegfile(*.jpg)"));//QDir::homePath()
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,tr("Warning"),tr("Open Image file failed! fileName is NULL."),QMessageBox::Ok);
        return;
    }
    image = QImage(fileName);
//    pix = QPixmap::fromImage(image);
    filename_ = fileName;
    if(image.height()>160)
        this->setGeometry(0, 0, image.width()+130, image.height()+20);
    else
        this->setGeometry(0, 0, image.width()+110, 170);
    ui->label->setGeometry(10, 10, image.width(), image.height());
    ui->pushButton_open->setGeometry(image.width()+20, 10, 100, 30);
    ui->pushButton_draw->setGeometry(image.width()+20, 50, 100, 30);
    ui->pushButton_send->setGeometry(image.width()+20, 90, 100, 30);
    ui->pushButton_close->setGeometry(image.width()+20, 130, 100, 30);

    pix = QPixmap(image.width(), image.height());
    pix = QPixmap::fromImage(image);
    ui->label->setPixmap(QPixmap::fromImage(image));

}

void ShowFigWidget::paintEvent(QPaintEvent *){
    QPainter pp(&pix);
    pp.drawLine(lastPoint, endPoint);
    lastPoint = endPoint;
    QPainter painter(this);
    painter.drawPixmap(10, 10, pix);

}

void ShowFigWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        lastPoint = event->pos();
//        ui->label->setPixmap(pix);
    }
}
void ShowFigWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton){
        endPoint = event->pos();
        update();
        ui->label->setPixmap(pix);
    }
}
void ShowFigWidget::mouseReleaseEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton){
        endPoint = event->pos();
        update();
        ui->label->setPixmap(pix);
    }

}

void ShowFigWidget::setOwerAndTarget(int ower, int target){
    owerChatwindows = ower;
    targetNode = target;
}
void ShowFigWidget::sendPicture(){
    drawImage = pix.toImage();
    drawImage.save(filename_+QString("draw.jpg"));
    filename_ = filename_+QString("draw.jpg");
    PCommunication::getInstance()->p_UserMainWindow->sendPicture(filename_, targetNode, owerChatwindows);
//    PCommunication::getInstance()->p_UserMainWindow->sendPixPicture(filename_, targetNode, owerChatwindows);
//    PCommunication::getInstance()->p_UserMainWindow->sendQimagePicture(filename_, targetNode, owerChatwindows);
}
