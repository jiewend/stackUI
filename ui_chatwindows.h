/********************************************************************************
** Form generated from reading UI file 'chatwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOWS_H
#define UI_CHATWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindows
{
public:
    QWidget *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton_8;
    QToolButton *toolButton_7;
    QToolButton *toolButton_9;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_close;
    QPushButton *pushButton_send;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_name;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton;
    QToolButton *toolButton_mini;
    QToolButton *toolButton_close;
    QProgressBar *progressBar;
    QLabel *proTextLabel;

    void setupUi(QWidget *ChatWindows)
    {
        if (ChatWindows->objectName().isEmpty())
            ChatWindows->setObjectName(QStringLiteral("ChatWindows"));
        ChatWindows->resize(722, 600);
        ChatWindows->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        widget = new QWidget(ChatWindows);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 0, 722, 600));
        widget->setMinimumSize(QSize(722, 600));
        widget->setMaximumSize(QSize(722, 600));
        widget->setStyleSheet(QStringLiteral("background-image: url(:/fig/chat2.jpg);"));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 430, 104, 32));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        toolButton_8 = new QToolButton(layoutWidget);
        toolButton_8->setObjectName(QStringLiteral("toolButton_8"));
        toolButton_8->setMinimumSize(QSize(30, 30));
        toolButton_8->setMaximumSize(QSize(30, 30));
        toolButton_8->setStyleSheet(QLatin1String("background: transparent;\n"
"border-image: url(:/fig/anbq.png);"));
        toolButton_8->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_8);

        toolButton_7 = new QToolButton(layoutWidget);
        toolButton_7->setObjectName(QStringLiteral("toolButton_7"));
        toolButton_7->setMinimumSize(QSize(30, 30));
        toolButton_7->setMaximumSize(QSize(30, 30));
        toolButton_7->setStyleSheet(QLatin1String("background: transparent;\n"
"border-image: url(:/fig/openfig.png);"));
        toolButton_7->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_7);

        toolButton_9 = new QToolButton(layoutWidget);
        toolButton_9->setObjectName(QStringLiteral("toolButton_9"));
        toolButton_9->setMinimumSize(QSize(30, 30));
        toolButton_9->setMaximumSize(QSize(30, 30));
        toolButton_9->setStyleSheet(QLatin1String("border-image: url(:/fig/anxj.png);\n"
"background: transparent;"));
        toolButton_9->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton_9);

        layoutWidget1 = new QWidget(widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(530, 560, 168, 32));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_close = new QPushButton(layoutWidget1);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setMinimumSize(QSize(80, 30));
        pushButton_close->setMaximumSize(QSize(80, 30));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 0));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush1);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        QBrush brush2(QColor(159, 158, 158, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_close->setPalette(palette);
        pushButton_close->setStyleSheet(QStringLiteral("background: transparent;"));
        pushButton_close->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_close);

        pushButton_send = new QPushButton(layoutWidget1);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setMinimumSize(QSize(80, 30));
        pushButton_send->setMaximumSize(QSize(80, 30));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Button, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush);
        QBrush brush3(QColor(76, 76, 76, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush);
        pushButton_send->setPalette(palette1);
        pushButton_send->setStyleSheet(QStringLiteral("background: transparent;"));
        pushButton_send->setFlat(true);

        horizontalLayout_4->addWidget(pushButton_send);

        pushButton_send->raise();
        pushButton_close->raise();
        layoutWidget2 = new QWidget(widget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 10, 667, 52));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget2);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(50, 50));
        label->setMaximumSize(QSize(50, 50));
        label->setStyleSheet(QStringLiteral("image: url(:/fig/earth.png);"));

        horizontalLayout_2->addWidget(label);

        label_name = new QLabel(layoutWidget2);
        label_name->setObjectName(QStringLiteral("label_name"));
        label_name->setMinimumSize(QSize(500, 50));
        label_name->setMaximumSize(QSize(500, 50));
        label_name->setStyleSheet(QLatin1String("background: transparent;\n"
"font: 20pt;\n"
"color: rgb(25, 11, 11);"));

        horizontalLayout_2->addWidget(label_name);

        layoutWidget3 = new QWidget(widget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(620, 0, 104, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        toolButton = new QToolButton(layoutWidget3);
        toolButton->setObjectName(QStringLiteral("toolButton"));
        toolButton->setMinimumSize(QSize(30, 30));
        toolButton->setMaximumSize(QSize(30, 30));
        toolButton->setStyleSheet(QStringLiteral("background: transparent;"));
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_mini = new QToolButton(layoutWidget3);
        toolButton_mini->setObjectName(QStringLiteral("toolButton_mini"));
        toolButton_mini->setMinimumSize(QSize(30, 30));
        toolButton_mini->setMaximumSize(QSize(30, 30));
        toolButton_mini->setStyleSheet(QLatin1String("font: 20pt;\n"
"background: transparent;"));
        toolButton_mini->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_mini);

        toolButton_close = new QToolButton(layoutWidget3);
        toolButton_close->setObjectName(QStringLiteral("toolButton_close"));
        toolButton_close->setMinimumSize(QSize(30, 30));
        toolButton_close->setMaximumSize(QSize(30, 30));
        toolButton_close->setStyleSheet(QStringLiteral("background: transparent;"));
        toolButton_close->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_close);

        progressBar = new QProgressBar(widget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(130, 440, 118, 23));
        progressBar->setValue(24);
        proTextLabel = new QLabel(widget);
        proTextLabel->setObjectName(QStringLiteral("proTextLabel"));
        proTextLabel->setGeometry(QRect(250, 440, 101, 17));

        retranslateUi(ChatWindows);

        QMetaObject::connectSlotsByName(ChatWindows);
    } // setupUi

    void retranslateUi(QWidget *ChatWindows)
    {
        ChatWindows->setWindowTitle(QApplication::translate("ChatWindows", "Form", 0));
        toolButton_8->setText(QString());
        toolButton_7->setText(QString());
        toolButton_9->setText(QString());
        pushButton_close->setText(QApplication::translate("ChatWindows", "\345\205\263\351\227\255(c)", 0));
        pushButton_send->setText(QApplication::translate("ChatWindows", "\345\217\221\351\200\201(s)", 0));
        label->setText(QString());
        label_name->setText(QApplication::translate("ChatWindows", "TextLabel", 0));
        toolButton->setText(QApplication::translate("ChatWindows", "\342\226\274", 0));
        toolButton_mini->setText(QApplication::translate("ChatWindows", "-", 0));
        toolButton_close->setText(QApplication::translate("ChatWindows", "X", 0));
        proTextLabel->setText(QApplication::translate("ChatWindows", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ChatWindows: public Ui_ChatWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOWS_H
