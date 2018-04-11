#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <stdlib.h>

#include <QDateTime>
#include <QFile>
#include <qmutex.h>
#include <qdir.h>
#include "definefile.h"
#include "pcommunication.h"
#include <QTextCodec>
#include <string>

#pragma execution_character_set("utf-8")

#define LOGFILEMAX 10000



QString str2qstr(const std::string str)
{
    return QString::fromLocal8Bit(str.data());
}

std::string qstr2str(const QString qstr)
{
    QByteArray cdata = qstr.toLocal8Bit();
    return std::string(cdata);
}


void outputMessage(QtMsgType type, const QMessageLogContext &context, QString const &msg)
{
    static QMutex mutex;
    mutex.lock();

    QString text;
    switch(type)
    {
    case QtDebugMsg:
        text = QString("Debug:");
        break;

    case QtWarningMsg:
        text = QString("Warning:");
        break;

    case QtCriticalMsg:
        text = QString("Critical:");
        break;

    case QtFatalMsg:
        text = QString("Fatal:");
    }

    QString context_info = QString("File:(%1) Line:(%2)").arg(QString(context.file)).arg(context.line);
    QString current_date_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd");
    QString current_date = QString("(%1)").arg(current_date_time);
    QString message = QString("%1 %2 %3 %4").arg(text).arg(context_info).arg(msg).arg(current_date);

    //QString path;
   // QDir dir;
    //path=dir.currentPath();
   // path.append(QString("/LOG/log.txt"));
    //QFile file(path);
    QFile file("log.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Append);
    QTextStream text_stream(&file);
    text_stream << message << "\r\n";
    file.flush();
    file.close();

    mutex.unlock();
}


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    a.connect(&a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()));
//    PCommunication::getInstance()->Build_UserMainWindow();

    MainWindow w;
    w.show();

    //注册MessageHandler
    qInstallMessageHandler(outputMessage);

    //打印日志到文件中
    qDebug("This is a debug message,%d",1);
    qWarning("This is a warning message");
    qCritical("This is a critical message");

    //启动侦听线程
    PCommunication::getInstance()->start_listen();


    return a.exec();
}
