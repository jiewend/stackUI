#ifndef NODEITEM_H
#define NODEITEM_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>

#define ITEM_HEIGHT 45

class NodeItem : public QWidget
{
    Q_OBJECT
public:
    explicit NodeItem(int NodeID, QWidget *parent = 0);
    ~NodeItem();
        int getOnlineStatus();

signals:
    void sendshowchatwindowID(int);

protected:
    void mouseDoubleClickEvent(QMouseEvent*);
protected slots:
    void StatusOffline(int );
    void StatusOnline(int );


private :
    QGridLayout *layout;
    QLabel *label,*user;
    int onlineStatus = 3;
    int m_NodeID;

};

#endif // NODEITEM_H
