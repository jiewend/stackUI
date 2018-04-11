#ifndef IMTOOLITEM_H
#define IMTOOLITEM_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QMouseEvent>
#include <QDebug>
#include <QPushButton>
#include "qqbutton.h"
class ImToolItem : public QWidget
{
    Q_OBJECT
public:
    explicit ImToolItem(QWidget *parent = 0);
    ImToolItem(QString title);
    void intiaView();
    void addItem(QWidget *item);
    bool GetIsShowList();

    ~ImToolItem();

signals:

public slots:
    void show_or_hide_list();
private:
    QQButton *btn;
    QString title;
     QVBoxLayout *layout;
     QList<QWidget *> *item_list;

     bool isShowList;
};

#endif // IMTOOLITEM_H
