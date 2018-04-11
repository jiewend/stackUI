#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QDialog>
#include "app_datapackage.h"
#include <QMouseEvent>
#include <QScrollArea>
#include "imtoolbox.h"
#include <QMutex>
#include "imtoolitem.h"
#include "chatwindows.h"
#include <map>
#include "mainwindow.h"
#include<QtNetwork>
#include "recv_image.h"
#include "topo.h"


#define ChatWindowsMap std::map<int,ChatWindows*>

namespace Ui {
class UserMainWindow;
}

class UserMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserMainWindow(QWidget *parent = 0);
    ~UserMainWindow();

signals:
    void  sendDatatoMainWindow(int);
    void  sendNewNodeID(int);
    void  send_recvmessage_to_handler(QString, int);
    void  toChangeOnlineStat(int);
    void  toChangeOfflineStat(int);
    void  showTopo();
    void  progressBarSet(int, int, int, int);


public:
    void  DosendDatatoMainWindow(struct App_DataPackage *p_package_recv);
    int   GetSelfNodeID();
    void  SendSelfNodeID(struct App_DataPackage *p_package_recv);
    void  AddNewNode(char* table);
    void  message_recvhandler(struct App_DataPackage *p_package_recv);
    void  fig_recvhandler(PicturePackage *p_package_recv);
    void  picture_recvhandler(PicturePackage *p_package_recv);
    void  picPix_recvhandler(PicturePackage *p_package_recv);
    void  handleRoutTable(char* table);
    bool  getConStatus();
    bool  dataAvailable();
    void  setProgress(App_DataPackage *p_package_recv);
    void  addSerial();
    uint8_t getSerial();
    QTcpSocket *getSocket();
    recv_image *getRecvImage();
    void emptyTemp();
    void handleImageHeaderACK(struct ImageHeader *p_package_recv);


protected slots:
    void on_btn_mini_clicked();
    void on_btn_close_clicked();
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent * e);
    void AddNewNodeHandler(int NewNodeID);
    void ShowChatWindows(int ChatWID);

    void on_Pushbutton_clicked();
    void testSgnal(int);
    void conStatusTure();
    void conStatusFalse();
    void readData();

public slots:
    void connectServer();
    void disconnectServer();
    void writeData(char* data, int len);
    void  switchBtn();
    void sendPicture(QString filename, int targetNode, int owerChatwindows);
    void sendPixPicture(QString filename, int targetNode, int owerChatwindows);
    void RecvMessageHandler(QString qstr, int SourceID);
    void sendQimagePicture(QString filename, int targetNode, int owerChatwindows);
    void sendPictureTimer();
    void sendPictureHeaderTimer();


private slots:
    void on_pushButton_clicked();

    void on_connect_btn_clicked();

    void on_btn_topo_clicked();

private:
    Ui::UserMainWindow *ui;
    QPoint position;
    QScrollArea *m_NodeScrollArea;
    ImToolBox *ib;
    QMutex  *AddNodeMutex;
    ImToolItem *item;
    bool connectStatus = 0;
    int SelfNodeID;
    ChatWindowsMap  m_ChatWindowsMap;
    QTcpSocket *tcpSocket;
    char recvBuff[sizeof(App_DataPackage)];
    uint8_t serial;
    int i = 0;
    QByteArray pictRecvTemp, pictSendTemp;
    recv_image* recvImage;
    Topo *topo;

    uint fileSize;
    QTimer *dataTimer;
    QTimer *headerTimer;
    QByteArray fileTemp;
    char can[sizeof(ImageData)];
    int byteToSend;
    uint8_t* p;
    struct ImageHeader sendImageHeader;
    struct ImageData sendImageData;
    uint32_t imageHeaderSize;
    uint offset = 0;
    bool isImageHeaderRecv = false;
    uint8_t waitACKImageID;


};

#endif // USERMAINWINDOW_H
