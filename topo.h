#ifndef TOPO_H
#define TOPO_H

#include <QDialog>
#include "app_datapackage.h"
#include <string>
//#include <>

namespace Ui {
class Topo;
}

class Topo : public QDialog
{
    Q_OBJECT

public:
    explicit Topo(QWidget *parent = 0);
    ~Topo();

private:
    Ui::Topo *ui;
protected:
    void paintEvent(QPaintEvent *);

protected slots:
      void getTracefile();

private:
    uint8_t topo[PACKAGE_SIZE];
    std::string nodeStartTime, firstActiveTime, firstSendHelloTime, routeFistUpdateTime, routeLastUpdateTime, surviveTime;
    QString tracefileName_ = QString("-1");
    time_t nodeStartTimeS;
public:
    uint8_t * getTopo();
    void setTopo(uint8_t * a);
    double * calElic();
    void drawTopo(double* point);
    void getInfo(QString tracefileName = QString("-1"));
    void initGetTracefile();

};

#endif // TOPO_H
