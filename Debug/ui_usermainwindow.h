/********************************************************************************
** Form generated from reading UI file 'usermainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMAINWINDOW_H
#define UI_USERMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserMainWindow
{
public:
    QLabel *label_5;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_mini;
    QPushButton *btn_close;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_8;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_15;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_10;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_30;
    QLabel *label_29;
    QLabel *label_28;
    QLabel *label_27;
    QLabel *label_26;
    QLabel *label_25;
    QLabel *label_24;
    QLabel *label_31;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *btn_topo;

    void setupUi(QDialog *UserMainWindow)
    {
        if (UserMainWindow->objectName().isEmpty())
            UserMainWindow->setObjectName(QStringLiteral("UserMainWindow"));
        UserMainWindow->resize(279, 691);
        UserMainWindow->setMinimumSize(QSize(0, 0));
        UserMainWindow->setMaximumSize(QSize(279, 691));
        UserMainWindow->setStyleSheet(QStringLiteral(""));
        label_5 = new QLabel(UserMainWindow);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 0, 281, 170));
        label_5->setStyleSheet(QStringLiteral("background-image: url(:/fig/back.jpg);"));
        horizontalLayoutWidget_2 = new QWidget(UserMainWindow);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 128, 40));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(20, 38));
        label_2->setMaximumSize(QSize(20, 38));
        label_2->setStyleSheet(QStringLiteral("image: url(:/fig/scutxh1.png);"));

        horizontalLayout_2->addWidget(label_2);

        label_3 = new QLabel(horizontalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("font:20pt;\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(label_3);

        horizontalLayoutWidget = new QWidget(UserMainWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(210, 0, 69, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_mini = new QPushButton(horizontalLayoutWidget);
        btn_mini->setObjectName(QStringLiteral("btn_mini"));
        btn_mini->setMinimumSize(QSize(30, 30));
        btn_mini->setMaximumSize(QSize(30, 30));
        btn_mini->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font:bold 20pt;\n"
"background:transparent;\n"
""));

        horizontalLayout->addWidget(btn_mini);

        btn_close = new QPushButton(horizontalLayoutWidget);
        btn_close->setObjectName(QStringLiteral("btn_close"));
        btn_close->setMinimumSize(QSize(30, 30));
        btn_close->setMaximumSize(QSize(30, 30));
        btn_close->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font:20pt;\n"
"background:transparent;"));

        horizontalLayout->addWidget(btn_close);

        horizontalLayoutWidget_3 = new QWidget(UserMainWindow);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 40, 217, 91));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(horizontalLayoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMaximumSize(QSize(20, 89));

        horizontalLayout_3->addWidget(label_4);

        label = new QLabel(horizontalLayoutWidget_3);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font:20pt;"));

        horizontalLayout_3->addWidget(label);

        stackedWidget = new QStackedWidget(UserMainWindow);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 170, 281, 451));
        stackedWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        page->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayoutWidget = new QWidget(page);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 20, 281, 461));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        stackedWidget->addWidget(page);
        label_8 = new QLabel(UserMainWindow);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 630, 281, 61));
        label_8->setStyleSheet(QStringLiteral("background-image: url(:/fig/back.jpg);"));
        horizontalLayoutWidget_6 = new QWidget(UserMainWindow);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(0, 630, 281, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(horizontalLayoutWidget_6);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMaximumSize(QSize(30, 16777215));
        label_14->setStyleSheet(QLatin1String("\n"
"image: url(:/little_log/1.png);"));

        horizontalLayout_6->addWidget(label_14);

        label_13 = new QLabel(horizontalLayoutWidget_6);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setMaximumSize(QSize(30, 16777215));
        label_13->setStyleSheet(QStringLiteral("image: url(:/little_log/2.png);"));

        horizontalLayout_6->addWidget(label_13);

        label_12 = new QLabel(horizontalLayoutWidget_6);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setMaximumSize(QSize(30, 16777215));
        label_12->setStyleSheet(QStringLiteral("image: url(:/little_log/3.png);"));

        horizontalLayout_6->addWidget(label_12);

        label_15 = new QLabel(horizontalLayoutWidget_6);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMaximumSize(QSize(30, 16777215));
        label_15->setStyleSheet(QStringLiteral("image: url(:/little_log/4.png);"));

        horizontalLayout_6->addWidget(label_15);

        label_21 = new QLabel(horizontalLayoutWidget_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMaximumSize(QSize(30, 16777215));
        label_21->setStyleSheet(QStringLiteral("image: url(:/little_log/5.png);"));

        horizontalLayout_6->addWidget(label_21);

        label_22 = new QLabel(horizontalLayoutWidget_6);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMaximumSize(QSize(30, 16777215));
        label_22->setStyleSheet(QStringLiteral("image: url(:/little_log/6.png);"));

        horizontalLayout_6->addWidget(label_22);

        label_23 = new QLabel(horizontalLayoutWidget_6);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMaximumSize(QSize(30, 16777215));
        label_23->setStyleSheet(QStringLiteral("image: url(:/little_log/7.png);"));

        horizontalLayout_6->addWidget(label_23);

        label_10 = new QLabel(horizontalLayoutWidget_6);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setMaximumSize(QSize(30, 16777215));
        label_10->setStyleSheet(QStringLiteral("image: url(:/little_log/8.png);"));

        horizontalLayout_6->addWidget(label_10);

        horizontalLayoutWidget_7 = new QWidget(UserMainWindow);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(0, 660, 281, 31));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_30 = new QLabel(horizontalLayoutWidget_7);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMaximumSize(QSize(30, 16777215));
        label_30->setStyleSheet(QStringLiteral("image: url(:/little_log/10.png);"));

        horizontalLayout_7->addWidget(label_30);

        label_29 = new QLabel(horizontalLayoutWidget_7);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setMaximumSize(QSize(30, 16777215));
        label_29->setStyleSheet(QStringLiteral("image: url(:/little_log/12.png);"));

        horizontalLayout_7->addWidget(label_29);

        label_28 = new QLabel(horizontalLayoutWidget_7);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setMaximumSize(QSize(30, 16777215));
        label_28->setStyleSheet(QStringLiteral("image: url(:/little_log/13.png);"));

        horizontalLayout_7->addWidget(label_28);

        label_27 = new QLabel(horizontalLayoutWidget_7);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setMaximumSize(QSize(30, 16777215));
        label_27->setStyleSheet(QStringLiteral("image: url(:/little_log/14.png);"));

        horizontalLayout_7->addWidget(label_27);

        label_26 = new QLabel(horizontalLayoutWidget_7);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMaximumSize(QSize(30, 16777215));
        label_26->setStyleSheet(QStringLiteral("image: url(:/little_log/15.png);"));

        horizontalLayout_7->addWidget(label_26);

        label_25 = new QLabel(horizontalLayoutWidget_7);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMaximumSize(QSize(30, 16777215));
        label_25->setStyleSheet(QStringLiteral("image: url(:/little_log/16.png);"));

        horizontalLayout_7->addWidget(label_25);

        label_24 = new QLabel(horizontalLayoutWidget_7);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMaximumSize(QSize(30, 16777215));
        label_24->setStyleSheet(QStringLiteral(""));

        horizontalLayout_7->addWidget(label_24);

        label_31 = new QLabel(horizontalLayoutWidget_7);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setMaximumSize(QSize(30, 16777215));
        label_31->setStyleSheet(QStringLiteral("image: url(:/little_log/9.png);"));

        horizontalLayout_7->addWidget(label_31);

        lineEdit = new QLineEdit(UserMainWindow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(0, 143, 140, 27));
        pushButton = new QPushButton(UserMainWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 143, 141, 27));
        btn_topo = new QPushButton(UserMainWindow);
        btn_topo->setObjectName(QStringLiteral("btn_topo"));
        btn_topo->setGeometry(QRect(220, 110, 51, 27));
        label_5->raise();
        horizontalLayoutWidget_2->raise();
        horizontalLayoutWidget->raise();
        horizontalLayoutWidget_3->raise();
        stackedWidget->raise();
        horizontalLayoutWidget_6->raise();
        horizontalLayoutWidget_7->raise();
        label_8->raise();
        lineEdit->raise();
        pushButton->raise();
        btn_topo->raise();

        retranslateUi(UserMainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UserMainWindow);
    } // setupUi

    void retranslateUi(QDialog *UserMainWindow)
    {
        UserMainWindow->setWindowTitle(QApplication::translate("UserMainWindow", "Dialog", 0));
        label_5->setText(QString());
        label_2->setText(QString());
        label_3->setText(QApplication::translate("UserMainWindow", "UWAN", 0));
        btn_mini->setText(QApplication::translate("UserMainWindow", "-", 0));
        btn_close->setText(QApplication::translate("UserMainWindow", "\303\227", 0));
        label_4->setText(QApplication::translate("UserMainWindow", "TextLabel", 0));
        label->setText(QApplication::translate("UserMainWindow", "node", 0));
        label_8->setText(QString());
        label_14->setText(QString());
        label_13->setText(QString());
        label_12->setText(QString());
        label_15->setText(QString());
        label_21->setText(QString());
        label_22->setText(QString());
        label_23->setText(QString());
        label_10->setText(QString());
        label_30->setText(QString());
        label_29->setText(QString());
        label_28->setText(QString());
        label_27->setText(QString());
        label_26->setText(QString());
        label_25->setText(QString());
        label_24->setText(QString());
        label_31->setText(QString());
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("UserMainWindow", "\346\267\273\345\212\240\350\212\202\347\202\271", 0));
        btn_topo->setText(QApplication::translate("UserMainWindow", "topo", 0));
    } // retranslateUi

};

namespace Ui {
    class UserMainWindow: public Ui_UserMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMAINWINDOW_H
