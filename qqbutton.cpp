#include "qqbutton.h"

QQButton::QQButton(QWidget *parent) : QWidget(parent)
{


   // head->setText("▼");
}

QQButton::QQButton(QString *bt_title){
    this->title = new QLabel;
    title->setText(*bt_title);
    this->setFixedHeight(30);
    layout = new QHBoxLayout;
    head = new QLabel;
    head->setFixedWidth(40);
    head->setText("▶");
    head->setStyleSheet("font:12pt");
    title->setStyleSheet("font:12pt");
    layout->addWidget(head);
    layout->addWidget(title);
    layout->setSpacing(0);
    layout->setContentsMargins(5,5,5,5);
    layout->setMargin(5);
    setLayout(layout);
}
void QQButton::mousePressEvent(QMouseEvent *event){
    emit clicked();
    qDebug() << "clicked";
    if(head->text() == "▶")
        head->setText("▼");
    else
        head->setText("▶");
}
QQButton::~QQButton()
{

}

