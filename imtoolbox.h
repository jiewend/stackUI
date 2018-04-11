#ifndef IMTOOLBOX_H
#define IMTOOLBOX_H

#include <QWidget>
#include <QVBoxLayout>
#include "imtoolitem.h"
#include <QSpacerItem>
class ImToolBox : public QWidget
{
    Q_OBJECT
public:
    explicit ImToolBox(QWidget *parent = 0);
    ~ImToolBox();
    void addItem(ImToolItem *item);
      void addItem(QWidget *item);
signals:

public slots:

private:
   // QSpacerItem *spacer;
    QVBoxLayout *layout;
};

#endif // IMTOOLBOX_H
