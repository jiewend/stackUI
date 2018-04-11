#include "nodeitem.h"
#include <QDebug>
#include "pcommunication.h"

NodeItem::NodeItem(int NodeID, QWidget *parent) : QWidget(parent)
{
    this->setFixedHeight(ITEM_HEIGHT);
    m_NodeID = NodeID;
    layout = new QGridLayout;
    label = new QLabel;

    QString  qNodeName = QString("节点:%1").arg(NodeID) + (QString("                  offline"));

    //QString qNodeName = QString("节点:%1").arg(NodeID) + (QString("                    offline"));
    user = new QLabel(qNodeName);
    layout->setMargin(5);
    label->setFixedSize(ITEM_HEIGHT,ITEM_HEIGHT);
    user->setStyleSheet("font:15pt");
    user->setLayoutDirection(Qt::LeftToRight);
    label->setStyleSheet("border-image: url(:/fig/earth);border-radius:5px");
    QWidget* qwid = new QWidget();
    layout->addWidget(qwid);
    layout->addWidget(label,0,0,2,2);
    layout->addWidget(user,0,1,2,4);
    layout->setContentsMargins(5,5,5,5);
    layout->setHorizontalSpacing(0);

    this->setLayout(layout);
    connect(PCommunication::getInstance()->p_UserMainWindow, SIGNAL(toChangeOnlineStat(int)), this, SLOT(StatusOnline(int)));
    connect(PCommunication::getInstance()->p_UserMainWindow, SIGNAL(toChangeOfflineStat(int)), this, SLOT(StatusOffline(int)));



}

void NodeItem::StatusOffline(int a)
{
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    using namespace std;
    if(a == m_NodeID){
    cout<<"nodeItem "<<m_NodeID<<" recv signal  offline"<<endl;
    onlineStatus = 0;
    QString  qNodeName = QString("节点:%1").arg(m_NodeID) + (QString("                  offline"));
    user -> setText(qNodeName);
    }
}

void NodeItem::StatusOnline(int a)
{
    QTextStream cin(stdin, QIODevice::ReadOnly);
    QTextStream cout(stdout, QIODevice::WriteOnly);
    using namespace std;
    if(a == m_NodeID){
//    cout<<"nodeItem "<<m_NodeID<<" recv signal  online"<<endl;
    onlineStatus = 1;
    QString  qNodeName = QString("节点:%1").arg(m_NodeID) + (QString("                  online"));
    user -> setText(qNodeName);
    }
}


int NodeItem::getOnlineStatus()
{
    return onlineStatus;
}

NodeItem::~NodeItem()
{

}

void NodeItem::mouseDoubleClickEvent(QMouseEvent *event)
{
    emit sendshowchatwindowID(m_NodeID);
}
