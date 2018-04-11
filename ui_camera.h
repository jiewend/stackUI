/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton_capture;
    QPushButton *pushButton_send;
    QPushButton *pushButton_close;

    void setupUi(QWidget *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QStringLiteral("Camera"));
        Camera->resize(944, 613);
        Camera->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalLayoutWidget = new QWidget(Camera);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 401, 401));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(Camera);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(420, 10, 202, 403));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(33);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 16777215));
        label->setSizeIncrement(QSize(0, 0));
        label->setBaseSize(QSize(0, 0));
        label->setStyleSheet(QLatin1String("QLabel{\n"
"     border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: rgb(0, 0, 0);\n"
"}"));

        verticalLayout->addWidget(label);

        pushButton_capture = new QPushButton(layoutWidget);
        pushButton_capture->setObjectName(QStringLiteral("pushButton_capture"));

        verticalLayout->addWidget(pushButton_capture);

        pushButton_send = new QPushButton(layoutWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));

        verticalLayout->addWidget(pushButton_send);

        pushButton_close = new QPushButton(layoutWidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));

        verticalLayout->addWidget(pushButton_close);


        retranslateUi(Camera);

        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QWidget *Camera)
    {
        Camera->setWindowTitle(QApplication::translate("Camera", "Form", 0));
        label->setText(QString());
        pushButton_capture->setText(QApplication::translate("Camera", "\346\213\215\347\205\247", 0));
        pushButton_send->setText(QApplication::translate("Camera", "\344\277\235\345\255\230\345\271\266\345\217\221\351\200\201", 0));
        pushButton_close->setText(QApplication::translate("Camera", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
