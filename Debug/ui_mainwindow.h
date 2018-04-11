/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *horizontalWidget;
    QLabel *label;
    QLabel *label_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;
    QLabel *pictureLabel;
    QLabel *label_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_1;
    QWidget *bottomwidget;
    QLabel *label_5;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(482, 348);
        MainWindow->setMaximumSize(QSize(482, 348));
        MainWindow->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalWidget = new QWidget(centralWidget);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(0, 0, 501, 151));
        horizontalWidget->setStyleSheet(QLatin1String("background-image: url(:/fig/water.jpg);\n"
"background-color: rgb(74, 153, 255);"));
        label = new QLabel(horizontalWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 101, 111));
        label->setStyleSheet(QLatin1String("image: url(:/fig/scutxh1.png);\n"
"background: transparent;\n"
""));
        label_2 = new QLabel(horizontalWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(170, 40, 261, 71));
        label_2->setMinimumSize(QSize(261, 71));
        label_2->setMaximumSize(QSize(261, 71));
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QLatin1String("font:50pt;\n"
"color: rgb(255, 255, 255);\n"
"background: transparent;"));
        horizontalLayoutWidget = new QWidget(horizontalWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(381, 0, 191, 40));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(30, 30));
        pushButton_3->setMaximumSize(QSize(30, 30));
        pushButton_3->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font:15pt;\n"
"background:transparent;"));
        pushButton_3->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(30, 30));
        pushButton->setMaximumSize(QSize(30, 30));
        pushButton->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font:15pt;\n"
"background:transparent;"));
        pushButton->setFlat(true);

        horizontalLayout_2->addWidget(pushButton);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(30, 30));
        pushButton_2->setMaximumSize(QSize(30, 30));
        pushButton_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font:15pt;\n"
"background:transparent;"));
        pushButton_2->setAutoDefault(false);
        pushButton_2->setFlat(true);

        horizontalLayout_2->addWidget(pushButton_2);

        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QStringLiteral("background: transparent;"));

        horizontalLayout_2->addWidget(label_3);

        label_3->raise();
        pushButton_3->raise();
        pushButton->raise();
        pushButton_2->raise();
        pictureLabel = new QLabel(centralWidget);
        pictureLabel->setObjectName(QStringLiteral("pictureLabel"));
        pictureLabel->setGeometry(QRect(60, 180, 81, 81));
        pictureLabel->setMinimumSize(QSize(81, 81));
        pictureLabel->setMaximumSize(QSize(81, 81));
        pictureLabel->setStyleSheet(QLatin1String("border-image: url(:/fig/earth.png);\n"
"border-radiu:20pt"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(440, 310, 31, 31));
        label_4->setStyleSheet(QStringLiteral("image: url(:/picture/check.png);"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(150, 180, 250, 78));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(30, 30));
        lineEdit->setStyleSheet(QStringLiteral("font:20pt;"));

        verticalLayout->addWidget(lineEdit);

        pushButton_1 = new QPushButton(layoutWidget);
        pushButton_1->setObjectName(QStringLiteral("pushButton_1"));
        pushButton_1->setMinimumSize(QSize(0, 30));
        pushButton_1->setStyleSheet(QLatin1String("background-color: rgb(74, 153, 255);\n"
"border-radius:px"));

        verticalLayout->addWidget(pushButton_1);

        bottomwidget = new QWidget(centralWidget);
        bottomwidget->setObjectName(QStringLiteral("bottomwidget"));
        bottomwidget->setGeometry(QRect(0, 288, 482, 60));
        bottomwidget->setStyleSheet(QLatin1String("background-image: url(:/fig/border-water.jpg);\n"
""));
        label_5 = new QLabel(bottomwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 10, 391, 41));
        label_5->setMinimumSize(QSize(391, 41));
        label_5->setMaximumSize(QSize(391, 41));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_5->setFont(font);
        label_5->setLayoutDirection(Qt::LeftToRight);
        label_5->setAutoFillBackground(false);
        label_5->setStyleSheet(QLatin1String("font: 20pt;\n"
"color: rgb(255, 255, 255);\n"
"background: transparent;"));
        label_5->setTextFormat(Qt::AutoText);
        label_5->setWordWrap(false);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        pushButton_2->setDefault(false);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "UWAN", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "UWAN", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "\342\226\274", 0));
        pushButton->setText(QApplication::translate("MainWindow", "-", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "X", 0));
        label_3->setText(QString());
        pictureLabel->setText(QString());
        label_4->setText(QString());
        pushButton_1->setText(QApplication::translate("MainWindow", "\347\241\256                \350\256\244", 0));
        label_5->setText(QApplication::translate("MainWindow", "\346\227\240\347\272\277\345\243\260\347\224\265\345\215\217\345\220\214\351\200\232\344\277\241\344\270\216\345\272\224\347\224\250\345\256\236\351\252\214\345\256\244", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
