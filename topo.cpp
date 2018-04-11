#include "topo.h"
#include "ui_topo.h"
#include "pcommunication.h"
#include <QPainter>
#include <math.h>
#include <QMessageBox>
#include <iostream>
#include <string>
#include <regex>
#include <time.h>
#include <cstdlib>
#include <QRegExp>
#include <QString>

extern int selfNodeID;

uint8_t topoTest[2][20] = {{2, 3, 4, 127}, {1, 0, 1, 127}};
uint8_t * test = &topoTest[0][0];
Topo::Topo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Topo)
{

    ui->setupUi(this);
    initGetTracefile();
    setWindowTitle(QString("node ") + QString::number(selfNodeID) + QString(" information"));
    setTopo(test);



    connect(ui->btn_changeTracefile, SIGNAL(clicked(bool)), this, SLOT(getTracefile()));
}

Topo::~Topo()
{
    delete ui;
}
void Topo::initGetTracefile(){
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;

    QString fileName("/home/ucc/WorkPlace/stack/tracefile/");
    if(tracefileName_ == QString("-1")){
        switch (selfNodeID){
            case 1:
                fileName += "A.log";
                break;
            case 2:
                fileName += "B.log";
                break;
            case 3:
                fileName += "C.log";
                break;
            case 4:
                fileName += "D.log";
                break;
            case 5:
                fileName += "E.log";
                break;
        }
    }

    QFile tracefile(fileName);
    if(!tracefile.open(QFile::ReadOnly))
    {
        QMessageBox::information(this,tr("Warning"),tr("Open tracefile falied"),QMessageBox::Ok);
        fileName = QFileDialog::getOpenFileName(this, tr("chose a tracefile"), QDir::currentPath());
    }
    tracefileName_ = fileName;
    getInfo(tracefileName_);
}

void Topo::getTracefile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("chose a tracefile"), QDir::currentPath());
    if(fileName.isEmpty()){
        QMessageBox::information(this,tr("Warning"),tr("no such file"),QMessageBox::Ok);
    }
    tracefileName_ = fileName;
    getInfo(tracefileName_);
}

void Topo::getInfo(QString tracefileName){
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;

    QByteArray readTemp;    
    cout<<tracefileName.toStdString().c_str()<<endl;
    QString fileName = tracefileName;
    QFile Log(fileName);
    if(!Log.open((QFile::ReadOnly))){
        QMessageBox::information(this,tr("Warning"),tr("No such file, chose a tracefile again "),QMessageBox::Ok);
    }    

    readTemp = Log.readAll();
    string allLogStr = readTemp.toStdString();

    int lastLoginPos = allLogStr.find_last_of("==========================");
    string lastLog = allLogStr.substr(lastLoginPos);

    string lastSendUpdate1 = lastLog, lastSendUpdate;

    int lastSendUpdatePos = lastLog.find("update:send");
    cout<<"1"<<endl;
    while(lastSendUpdatePos != -1){
            lastSendUpdate = lastSendUpdate1.substr(lastSendUpdatePos -60);
            lastSendUpdate1 = lastSendUpdate1.substr(lastSendUpdatePos + 1);
            lastSendUpdatePos = lastSendUpdate1.find("update:send");
    }
    cout<<"last update : "<<lastSendUpdate.c_str()<<endl;




    int lastRecordpos = lastLog.find_last_of("\n");
    cout<<"lastRecordpos : "<<lastRecordpos<<endl;
    string lastRecord;
    if(lastRecordpos > 60)// maybe all down here
        lastRecord = lastLog.substr(lastRecordpos - 60);

    cout<<"last record : "<<lastRecord.c_str()<<endl;
    cout<<"last update : "<<lastSendUpdate.c_str()<<endl;
    cout<<"last log : "<<lastLog.c_str()<<endl;
    string strLoginTime, strFirstActiveTime, strFirstSendHelloTime, strLastUpdateSendTime, strFirstUpdateTime, strSurviveTime;
    std::smatch matchLoginTime, matchFirstActiveTime, matchFirstSendHelloTime, matchHelloRspRecvTime, matchUpdataSendTime, matchLastUpdateSendTime, matchLastRecordTime;

    std::regex RegloginTime ("^(=)(.*)\n");
    std::regex RegFirstActiveTime("(\\d){10}.*\n");
    std::regex RegfirstSendHelloTime ("(\\d){10}.*hello:send\\n");
    std::regex RegUpdataSendTime("(\\d){10}.*update:send");
    std::regex RegLastUpdataSendTime("(\\d){10}.*pdate:send");
    std::regex RegLastRecordTime("(\\d){10}.*\\n");

    std::regex_search(lastLog, matchLoginTime, RegloginTime);
    std::regex_search(lastLog, matchFirstActiveTime, RegFirstActiveTime);
    std::regex_search(lastLog, matchFirstSendHelloTime, RegfirstSendHelloTime);
    std::regex_search(lastLog, matchUpdataSendTime, RegUpdataSendTime);
    std::regex_search(lastSendUpdate, matchLastUpdateSendTime, RegLastUpdataSendTime);
    std::regex_search(lastRecord, matchLastRecordTime, RegLastRecordTime);

    strLoginTime = (matchLoginTime.end()-1)->str();
    nodeStartTime = strLoginTime;

    time_t t = (time_t)atoi(matchFirstSendHelloTime.begin()->str().c_str());
    if((int)t != 0){
        strFirstSendHelloTime = ctime(&t);
        firstSendHelloTime= strFirstSendHelloTime;
    } else
        firstSendHelloTime = string("****");

    time_t t0 = (time_t)atoi(matchFirstActiveTime.begin()->str().c_str());
    if((int)t0 != 0){
        strFirstActiveTime = ctime(&t0);
        firstActiveTime = strFirstActiveTime;
    }


    time_t t1 = (time_t)atoi(matchLastUpdateSendTime.begin()->str().c_str());
    if((int)t1 != 0){
        strLastUpdateSendTime = ctime(&t1);
        routeLastUpdateTime = strLastUpdateSendTime;
    } else
        routeLastUpdateTime = string("****");

    time_t t2 = (time_t)atoi(matchUpdataSendTime.begin()->str().c_str());
    if((int)t2 != 0){
        strFirstUpdateTime = ctime(&t2);
        routeFistUpdateTime = strFirstUpdateTime;
    } else
        routeFistUpdateTime = string("****");

    time_t t3 = (time_t)atoi(matchLastRecordTime.begin()->str().c_str());
    if((int)t3 != 0){
        int t4 = t3 - t0;
        strSurviveTime = QString::number((int)t4).toStdString();
        surviveTime = strSurviveTime;
    } else
        surviveTime = string("****");

//    cout<<lastLog.c_str()<<endl;
/*    cout<<"------------------------"<<endl;
    cout<<"login time : "<<strLoginTime.c_str()<<endl;
    cout<<"first send hello time : "<<strFirstActiveTime.c_str()<<endl;
    cout<<"send hello time : "<<strFirstSendHelloTime.c_str()<<endl;
    cout<<"first send update time "<<strFirstUpdateTime.c_str()<<endl;
    cout<<"last send update time "<<strLastUpdateSendTime.c_str()<<endl;
    cout<<"last active time "<<ctime(&t3)<<endl;
    cout<<"------------------------"<<endl;
*/

}

void Topo::paintEvent(QPaintEvent *)
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;


    QPainter painter(this);
    QPen pen, penText;
    pen.setColor(QColor(11, 45, 100));


    QBrush brush(QColor(11, 45, 100));
    painter.setPen(pen);
    painter.setBrush(brush);
    penText.setColor(QColor(255, 255, 255));


    painter.drawEllipse(QPoint(200, 200), 30, 30);
    painter.setPen(penText);
    painter.drawText(200 - 20, 200 + 0, QString("node ") + QString::number(selfNodeID));

    penText.setColor(QColor(0, 0, 0));
    painter.setPen(penText);

    painter.drawText(400, 20, QString("Start at : "));
    painter.drawText(400, 40, QString::fromStdString(nodeStartTime));

    painter.drawText(400, 80, QString("First Send Hello at : "));
    painter.drawText(400, 100, QString::fromStdString(firstSendHelloTime));

    painter.drawText(400, 140, QString("Join in Network at : "));
    painter.drawText(400, 160, QString::fromStdString(routeFistUpdateTime));

    painter.drawText(400, 200, QString("Route Table Last Change at : "));
    painter.drawText(400, 220, QString::fromStdString(routeLastUpdateTime));

    painter.drawText(400, 260, QString("Survive Time : ") + QString::fromStdString(surviveTime) + QString(" s"));


    //    QFont infoFont("宋体", 15);
//    painter.setFont(infoFont);


    uint8_t * foruse = getTopo();
//    for(int i = 0; i<14; i++)
//        cout<<foruse[i]<<", ";
    double * p = calElic();
    drawTopo(p);


}

uint8_t * Topo::getTopo()
{
    return topo;
}

void Topo::setTopo(uint8_t *a)
{
    memcpy(topo, a, PACKAGE_SIZE);
}

double * Topo::calElic()
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;
    int chore = 150;
    int len = 0;
    for(int i = 0; ; i++){
        if(topo[i] == 127)
            break;
        len++;

   }
   cout<<"len = "<<len<<endl;
   double angle = 3.14159 * 2 / len;
   double *point = new double[PACKAGE_SIZE];
   bzero(point, PACKAGE_SIZE);
   for(int i = 0; i<len; i++)
   {
       point[i] = 200 + chore * cos(angle*i);
       (point + PACKAGE_SIZE / 2)[i] = 200 + chore * sin(angle*i);
   }
   /*
   for(int i = 0; i < len; i++)
   {
       cout<<"("<<point[i]<<", "<<(point + PACKAGE_SIZE / 2)[i]<<")";
   }
   */
   return point;
}

void Topo::drawTopo(double *point)
{
    QTextStream cin(stdin,  QIODevice::ReadOnly);
    QTextStream cout(stdout,  QIODevice::WriteOnly);
    using namespace std;
    QPainter painter(this);
    QPen penElli, penSoil, penDash, penText;
    penElli.setColor(QColor(11, 45, 100));
    penSoil.setColor(QColor(11, 45, 100));
    penDash.setColor(QColor(11, 45, 100));
    penText.setColor(QColor(255, 255, 255));

    penSoil.setStyle(Qt::SolidLine);
    penDash.setStyle(Qt::DashLine);


    QBrush brush(QColor(11, 45, 100));

    int len = 0;
    for(int i = 0; ; i++){
        if(topo[i] == 127)
            break;
        len++;
   }
   for(int i = 0; i < len; i++){
       painter.setPen(penElli);
       painter.setBrush(brush);
       painter.drawEllipse(QPoint(point[i], (point + PACKAGE_SIZE / 2)[i]), 30, 30);
       if((topo + PACKAGE_SIZE / 2)[i])
           painter.setPen(penSoil);
       else
           painter.setPen(penDash);
       painter.drawLine(QPoint(200, 200), QPoint(point[i], (point + PACKAGE_SIZE / 2)[i]));
       painter.setPen(penText);
       painter.drawText(point[i] - 22, (point + PACKAGE_SIZE / 2)[i] + 2, QString("node ") + QString::number(topo[i]));
   }
   cout<<"drawTopo finish"<<endl;
}
