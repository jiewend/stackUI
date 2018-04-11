#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "pcommunication.h"
#include <string>
#include<QTextStream>
#include<stdio.h>
#include<QFile>
#include<QTextCodec>
#include <unistd.h>
int selfNodeID;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    QRegExp regExp("^[1-9][0-9]{1,8}$"); //^[1-9][0-9]*$ 任意位数正整数
    ui->lineEdit->setValidator(new QRegExpValidator(regExp, this));
    ui->lineEdit->setPlaceholderText(QString("ID of the node"));
    tcpSocket = new QTcpSocket(this);

    this->setWindowIcon(QIcon(":/fig/scutxh1"));

    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(On_ConfigID_Button()));
       // connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
    connect(PCommunication::getInstance()->p_UserMainWindow,SIGNAL(sendDatatoMainWindow(int)),this,SLOT(ConfigIDConfirm(int)));
    connect(this, SIGNAL(afterConnected()), this, SLOT(showUsermianwindow()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::On_ConfigID_Button()
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;

    QString LineEditStr = ui->lineEdit->text();
    if(!LineEditStr.isEmpty())
    {
        selfNodeID = LineEditStr.toInt();
        cout<<"selfNodeID = "<<selfNodeID<<endl;
        qDebug()<<LineEditStr;
        QByteArray ba = LineEditStr.toLatin1();
        char *p_Buffer = ba.data();


//        if(PCommunication::getInstance()->package_write(p_Buffer,LineEditStr.length(),0,0,0))
//        {
            PCommunication::getInstance()->Build_UserMainWindow();
            PCommunication::getInstance()->p_UserMainWindow->connectServer();
            PCommunication::getInstance()->start_listen();
            cout<<"conStatus = "<<PCommunication::getInstance()->p_UserMainWindow->getConStatus()<<endl;
            emit afterConnected();
//            while(PCommunication::getInstance()->p_UserMainWindow->getConStatus() == true){//for the right reaction ,use the wrong word
//                cout<<"conStatus = "<<PCommunication::getInstance()->p_UserMainWindow->getConStatus()<<endl;
//                PCommunication::getInstance()->p_UserMainWindow->show();
//                this->close();
//                break;
//            }
//        }


    }
    else
    {
        QMessageBox::information(this,tr("Warning"),tr("Please input a ID."),QMessageBox::Ok);
    }
}

void MainWindow::showUsermianwindow()
{
   PCommunication::getInstance()->p_UserMainWindow->show();
   this->close();

}


void MainWindow::ConfigIDConfirm(int package_type)
{
    if(package_type == 1)
    {
        this->close();
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        On_ConfigID_Button();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    position =e->globalPos() -  this->pos();

}


void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e->globalPos() - position);
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_pushButton_clicked()
{
    this->showMinimized();
}
