#ifndef _DEFINE_FILE  
#define _DEFINE_FILE  

#include <QTextStream>
#include <QDebug>

#define SHM_KEY_SEND 1234
#define SHM_KEY_RECV 5678
#define SEM_KEY_SEND 4001
#define SEM_KEY_RECV 4002

union semun {
    int val;
};

void outputMessage(QtMsgType type, const QMessageLogContext &context, QString const &msg); //log output function
QString str2qstr(const std::string str);
std::string qstr2str(const QString qstr);

#endif //_DEFINE_FILE  
