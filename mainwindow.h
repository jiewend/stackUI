#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include "usermainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void afterConnected();
protected slots:
    void On_ConfigID_Button();
    void ConfigIDConfirm(int package_type);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent * e);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void showUsermianwindow();
//    void doAfterConnected();

protected:
    void    keyPressEvent(QKeyEvent *event);


private:
    Ui::MainWindow *ui;
    QPoint position;
    QTcpSocket *tcpSocket;
};

#endif // MAINWINDOW_H
