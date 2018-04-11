#ifndef QQBUTTON_H
#define QQBUTTON_H

#include <QWidget>
#include <QMouseEvent>
#include <QHBoxLayout>
#include <QLabel>
#include <QDebug>
class QQButton : public QWidget
{
    Q_OBJECT
public:
    explicit QQButton(QWidget *parent = 0);
    QQButton(QString *title = 0);
   void mousePressEvent(QMouseEvent *e);
    ~QQButton();

signals:
    void clicked();
public slots:
private:
    QHBoxLayout *layout;
    QLabel *head,*title;
};

#endif // QQBUTTON_H
