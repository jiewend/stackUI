#include "chatwindows.h"
#include "ui_chatwindows.h"
#include <QWebEnginePage>
#include <QDateTime>
#include "pcommunication.h"
#include "definefile.h"
#include <QDebug>
#include <QResource>
#include <QMessageBox>
#include <stdlib.h>
#include "showfigwidget.h"
#include <string>
#include <unistd.h>
#include <QProgressDialog>
#include <time.h>

extern int selfNodeID;
extern int targetNodeID;

ChatWindows::ChatWindows(int NodeID, QWidget *parent) : //
    QWidget(parent),
    ui(new Ui::ChatWindows)
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;

    setWindowFlags(Qt::FramelessWindowHint);
    ui->setupUi(this);
    m_NodeID = NodeID;
    m_TargetID = targetNodeID;
    cout<<"chatwindows No "<<m_NodeID<<endl;

    ui->label_name->setText(QString("节点%1").arg(selfNodeID) + QString("->节点%1").arg(m_NodeID) + QString("      offline"));
    m_pView = new QWebEngineView(this);
    m_pView->setGeometry(20,80,680,350);
    m_pView->setFixedSize(680,350);
    m_pView->setStyleSheet("background: transparent");
    QWebEnginePage *pPage = new QWebEnginePage(this);
    m_pView->setPage(pPage);
    pPage->setUrl(QUrl("qrc:/messageBox.html"));

    m_TextEdit = new QTextEdit(this);
    m_TextEdit->setGeometry(20,460,680,100);
    m_TextEdit->setStyleSheet("background-color: rgb(255, 255, 255);");

    //ui->lineEdit->setAlignment(Qt::AlignTop);

    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);
    ui->proTextLabel->setText(QString(" "));
//    ui->

    faceFormFlag = false;

    p_NewCamera = new Camera();
/////////////////////////////////////////////



 //////////////////////////////

    connect(ui->pushButton_send,SIGNAL(clicked(bool)),this,SLOT(newConnect()));
//    connect(ui->pushButton_send,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_send_click()));
    connect(ui->toolButton_mini,SIGNAL(clicked(bool)),this,SLOT(on_btn_mini_clicked()));
    connect(ui->toolButton_close,SIGNAL(clicked(bool)),this,SLOT(on_btn_close_clicked()));
    connect(ui->pushButton_close,SIGNAL(clicked(bool)),this,SLOT(on_btn_close_clicked()));
    connect(ui->toolButton_7,SIGNAL(clicked(bool)),this,SLOT(on_ToolButton7_clicked()));
    connect(ui->toolButton_8,SIGNAL(clicked(bool)),this,SLOT(on_ToolButton8_clicked()));
    connect(ui->toolButton_9,SIGNAL(clicked(bool)),this,SLOT(on_ToolButton9_clicked()));
    connect(p_NewCamera,SIGNAL(sendjpgfilename(QString, int, int)),this,SLOT(show_and_sendjpg(QString, int, int)));
    connect(PCommunication::getInstance()->p_UserMainWindow, SIGNAL(toChangeOnlineStat(int)), this, SLOT(changeOnlineStatus(int)));
    connect(PCommunication::getInstance()->p_UserMainWindow, SIGNAL(toChangeOfflineStat(int)), this, SLOT(changeOfflineStatus(int)));
    connect(PCommunication::getInstance()->p_UserMainWindow, SIGNAL(progressBarSet(int, int, int, int)), this, SLOT(handleProgressBar(int, int, int, int)));

}
//p_UserMainWindow
ChatWindows::~ChatWindows()
{
    delete ui;
}
////////////////////////////////
//void ChatWindows::connectStatusTure()
//{
//    QMessageBox::information(this,tr("Warning"),tr("Connected Successful!"),QMessageBox::Ok);
//    this->connectStatus = 1;
//}
//void ChatWindows::connectStatusFalse()
//{
//    QMessageBox::information(this,tr("Warning"),tr("Connected Failed! Please Check the Server"),QMessageBox::Ok);
//    this->connectStatus = 0;
//}



void ChatWindows::handleProgressBar(int Dest, int Sour, int LayerNum, int SerialNum)
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;   

    if(numInProgress == -1)
        numInProgress = SerialNum;
//    cout<<"SelfNodeID = "<<PCommunication::getInstance()->p_UserMainWindow->GetSelfNodeID()<<endl;
//    cout<<"Dest = "<<Dest<<endl;
//    cout<<"Sour = "<<Sour<<endl;
//    cout<<"LayerNum = "<<LayerNum<<endl;
//    cout<<"SerialNum = "<<SerialNum<<endl;
    if(Sour == PCommunication::getInstance()->p_UserMainWindow->GetSelfNodeID()){
//       package going down
//        cout<<"going down"<<endl;

        if(Dest == m_NodeID){
//            cout<<"layerNum = "<<LayerNum<<endl;
            switch(LayerNum)
            {
            case 4 :
//                cout<<"tra send"<<endl;
                ui->progressBar->setValue(25);
                ui->proTextLabel->setText(QString("tra send"));
                break;
            case 3 :
//                cout<<"net send"<<endl;
                ui->progressBar->setValue(50);
                ui->proTextLabel->setText(QString("net send"));
                break;
            case 2 :
                if(ui->progressBar->value() == 50){
//                    cout<<"mac send"<<endl;
                    ui->progressBar->setValue(75);
                    ui->proTextLabel->setText(QString("mac send"));
                    break;
                }
            case 1 :
                if(ui->progressBar->value() == 75){
//                    cout<<"mac ack"<<endl;
                    ui->progressBar->setValue(100);
                    ui->proTextLabel->setText(QString("mac recv ack"));
                    break;
                }
            }
        }
    }else{
//       package going up
//        cout<<"going up"<<endl;
        if(Sour == m_NodeID){
            switch(LayerNum){
                case 4 :
                    ui->progressBar->setValue(100);
                    ui->proTextLabel->setText(QString("tra recv"));
                    break;
                case 3 :
                    ui->progressBar->setValue(75);
                    ui->proTextLabel->setText(QString("net recv"));
                    break;
                case 2 :
                    ui->progressBar->setValue(50);
                    ui->proTextLabel->setText(QString("mac recv"));
                    break;
                case 1 :
                    ui->progressBar->setValue(25);
                    ui->proTextLabel->setText(QString("phy recv"));
                    break;
            }
        }

    }
}

void ChatWindows::newConnect()
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;

    QString qstr = m_TextEdit->toPlainText();
    std::string str =  qstr2str(qstr);
    int len = str.length();
    char *p_Buffer = (char *)malloc((len+1)*sizeof(char));
    str.copy(p_Buffer,len,0);

    char buff[128];
    bzero(buff, sizeof(buff));
    uint8_t serial = PCommunication::getInstance()->p_UserMainWindow->getSerial();
    struct App_DataPackage sendBuff;
    sendBuff.Package_type = 4;
    sendBuff.SourceID = selfNodeID;
    sendBuff.DestinationID = m_NodeID;
    sendBuff.SerialNum = serial;
    sendBuff.data_size = len;
    //= {len, 4, m_NodeID, selfNodeID, serial, {"0"}};
    PCommunication::getInstance()->p_UserMainWindow->addSerial();

    memcpy(sendBuff.data_buffer, p_Buffer, len);
    memcpy(buff, &sendBuff, sizeof(sendBuff));

    //if(this->getIsOnline()){
        cout<<"data = "<<sendBuff.data_buffer<<endl;
        PCommunication::getInstance()->p_UserMainWindow->writeData(buff, sizeof(sendBuff));
        show_my_sendmessage(qstr);
        m_TextEdit->clear();
//    }
//    else{
//        QMessageBox::information(this,tr("Warning"),tr("can't send message while offline"),QMessageBox::Ok);
//    }
}



void ChatWindows::changeOnlineStatus(int id)
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;

    if(m_NodeID == id){
//        cout<<"chatwind "<<m_NodeID <<"recv online signal"<<endl;
        ui->label_name->setText(QString("节点%1").arg(selfNodeID) + QString("->节点%1").arg(m_NodeID) + QString("              online"));
        this->onlineTrue();
    }
}

void ChatWindows::changeOfflineStatus(int id)
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;
    if(m_NodeID == id){
//        cout<<"chatwind "<<m_NodeID <<"recv offline signal"<<endl;
        ui->label_name->setText(QString("节点%1").arg(selfNodeID) + QString("->节点%1").arg(m_NodeID) + QString("              offline"));
        this->onlineFalse();
    }
}
bool ChatWindows::getIsOnline()
{
    return (this->isOnline);
}

void ChatWindows::onlineTrue()
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;

    this->isOnline = 1;
//    cout<<"node"<<m_NodeID<<"  online"<<endl;

}

void ChatWindows::onlineFalse()
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;

    this->isOnline = 0;
    cout<<"node"<<m_NodeID<<"  offline"<<endl;
}

void ChatWindows::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
        emit ui->pushButton_send->clicked(true);
}
////////////////////////////////////
void ChatWindows::on_pushButton_send_click()
{
    //QString qstr = ui->lineEdit->text();
    QString qstr = m_TextEdit->toPlainText();
    if(!qstr.isEmpty())
    {
        show_my_sendmessage(qstr);
        //ui->lineEdit->clear();
        m_TextEdit->clear();
    }
    //else
      //  show_and_sendjpg(qstr);
}

void ChatWindows::show_my_sendmessage(QString qstr)
{

    std::string str =  qstr2str(qstr);
    int len = str.length();
    char *p_Buffer = (char *)malloc((len+1)*sizeof(char));
    str.copy(p_Buffer,len,0);
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString tstr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    qstr = bqFromStrToHtml(qstr);
    //////////////

    //////////////////
    QString html = QString("appendMyMessage(%1, %2);scrollBottom();").arg("'["+QString("节点:%1").arg(selfNodeID)+"]  "+tstr+"'").arg("'"+qstr+"'");
    m_pView->page()->runJavaScript(html);
    qDebug()<<html;

    //PCommunication::getInstance()->package_write(p_Buffer,len,4,m_NodeID,PCommunication::getInstance()->p_UserMainWindow->GetSelfNodeID());//useless now
}

void ChatWindows::show_recvmessage(QString qstr)
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString tstr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    qstr = bqFromStrToHtml(qstr);

    QString html = QString("appendOtherMessage(%1, %2);scrollBottom();").arg("'["+QString("节点:%1").arg(m_NodeID)+"]  "+tstr+"'").arg("'"+qstr+"'");
    m_pView->page()->runJavaScript(html);
}

void ChatWindows::on_btn_mini_clicked()
{
    this->showMinimized();
}

void ChatWindows::on_btn_close_clicked()
{
    this->close();
}

void ChatWindows::mousePressEvent(QMouseEvent *e)
{
    if(faceFormFlag)
        on_ToolButton8_clicked();
    position =e->globalPos() -  this->pos();

}

void ChatWindows::on_ToolButton7_clicked()
{
    ShowFigWidget* p_figshow = new ShowFigWidget();
    p_figshow->setOwerAndTarget(selfNodeID, m_NodeID);
    p_figshow->setGeometry(this->pos().rx()+185,this->pos().ry()+190,350,220);
    p_figshow->show();
}

void ChatWindows::mouseMoveEvent(QMouseEvent *e)
{
    this->move(e->globalPos() - position);
}

void ChatWindows::showwidget()
{
    ui->widget->show();
}

void ChatWindows::on_ToolButton8_clicked()
{
    if(faceFormFlag){
        disconnect(m_faceForm, SIGNAL(faceClicked(QString)), this, SLOT(add_bq(QString)));
        m_faceForm->deleteLater();
        faceFormFlag = false;
    }
    else
    {
        m_faceForm = new faceForm();
        faceFormFlag = true;
        m_faceForm->setGeometry(this->pos().rx()+20,this->pos().ry()+310,400,120);
        m_faceForm->show();
        connect(m_faceForm, SIGNAL(faceClicked(QString)), this, SLOT(add_bq(QString)));
    }

}

void ChatWindows::add_bq(QString qstr)
{
    //ui->lineEdit->setText(ui->lineEdit->text()+qstr);
    //ui->lineEdit->setFocus();
    m_TextEdit->setPlainText(m_TextEdit->toPlainText()+qstr);
    m_TextEdit->setFocus();
    disconnect(m_faceForm, SIGNAL(faceClicked(QString)), this, SLOT(add_bq(QString)));
    m_faceForm->deleteLater();
    faceFormFlag = false;
}

QString ChatWindows::bqFromStrToHtml(QString qstr)
{
    qstr.replace("\n", "<br/>");
    qstr.replace( "/[/", "<img src=qrc:/fig/bq/" );
    qstr.replace( "/]/", "/>" );
    return qstr;
}
//camera button
void ChatWindows::on_ToolButton9_clicked()
{
    p_NewCamera->setGeometry(this->pos().rx()+46,this->pos().ry()+90,630,420);
    p_NewCamera->show();
    p_NewCamera->setTargetAndSource(selfNodeID, m_NodeID);
    p_NewCamera->start_camera();
}


void ChatWindows::show_and_sendjpg(QString qstr, int selfNode, int targetNode)
{
    QDateTime time = QDateTime::currentDateTime();//获取系统现在的时间
    QString tstr = time.toString("yyyy-MM-dd hh:mm:ss ddd"); //设置显示格式
    FILE* fp; 
    int	readnum;
    fp = fopen(qstr2str(qstr).c_str(), "rb");
    if (!fp)
    {
        QMessageBox::information(this,tr("Error"),QString("open %1 fail.").arg(qstr),QMessageBox::Ok);
        return;
    }
    char* p_buffer = new char[PACKAGE_SIZE];
    readnum = fread(p_buffer, 1, PACKAGE_SIZE, fp);
    fclose(fp);
//    PCommunication::getInstance()->package_write(p_buffer,readnum,5,m_NodeID,PCommunication::getInstance()->p_UserMainWindow->GetSelfNodeID());
    PCommunication::getInstance()->p_UserMainWindow->sendPicture(qstr, targetNode, selfNode);
    delete[] p_buffer;
    p_buffer = NULL;
    QString qstrimg = QString("您发送了一张图片") + qstr;
    //QString qstrimg = QString("<img src=") + qstr + QString("/>");
    QString qstrimg1 = "<img src=\"/home/hj/UWAN/fig/chat1.jpg\" width=\"200\" height=\"200\"/>";
    //QString qstrimg = "<img src=/home/hj/UWAN/fig/bq/08.gif/>";
    //QString qstrimg = "<img src=\"qrc:fig/11.jpg\"/>";
    //qDebug()<<qstrimg;
    //ui->lineEdit->setText(qstrimg);
    QString html = QString("appendMyMessage(%1, %2);scrollBottom();").arg("'["+QString("节点:%1").arg(PCommunication::getInstance()->p_UserMainWindow->GetSelfNodeID())+"]  "+tstr+"'").arg("'"+qstrimg+"'");
    //QString html = QString("img(%1);").arg(qstrimg);
    qDebug()<<html;
    m_pView->page()->runJavaScript(html);
}
