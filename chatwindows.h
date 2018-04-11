#ifndef CHATWINDOWS_H
#define CHATWINDOWS_H

#include <QWidget>
#include <QWebEngineView>
#include <QMouseEvent>
#include "faceform.h"
#include "camera.h"
#include <QTextEdit>
#include <QtNetwork>
#include <QKeyEvent>
#include "app_datapackage.h"

namespace Ui {
class ChatWindows;
}

class ChatWindows : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWindows(int NodeID, QWidget *parent = 0);
    ~ChatWindows();

protected slots:
    void    on_pushButton_send_click();
    void    on_btn_mini_clicked();
    void    on_btn_close_clicked();
    void    mousePressEvent(QMouseEvent *e);
    void    mouseMoveEvent(QMouseEvent * e);
    void    on_ToolButton8_clicked();
    void    add_bq(QString qstr);
    void    on_ToolButton9_clicked();
    void    show_and_sendjpg(QString qstr, int selfNode, int targetNode);
    void    on_ToolButton7_clicked();
    void    changeOnlineStatus(int);
    void    changeOfflineStatus(int);
    void    handleProgressBar(int, int, int, int);

protected:
    void    keyPressEvent(QKeyEvent *event);

private:
    void    show_my_sendmessage(QString qstr);
    QString bqFromStrToHtml(QString qstr);
//    bool connectStatus = 0;

private slots:
    void newConnect();
    void readMessage();


public slots:
    void on_pushButton_clicked();


public:
    void    show_recvmessage(QString qstr);
    void    showwidget();
    bool    getIsOnline();
    void    onlineTrue();
    void    onlineFalse();


private:
    Ui::ChatWindows *ui;
    QPoint position;
    int m_NodeID;
    int m_TargetID;
    QWebEngineView *m_pView;
    QTextEdit* m_TextEdit;
    faceForm *m_faceForm;
    bool faceFormFlag;
    Camera* p_NewCamera;
    bool isOnline = 0;
    int numInProgress = -1;

};

#endif // CHATWINDOWS_H
