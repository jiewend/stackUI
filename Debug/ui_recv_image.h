/********************************************************************************
** Form generated from reading UI file 'recv_image.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECV_IMAGE_H
#define UI_RECV_IMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_recv_image
{
public:
    QLabel *label;
    QPushButton *btn_SaveAs;
    QPushButton *btn_save;
    QPushButton *btn_emptyTemp;

    void setupUi(QDialog *recv_image)
    {
        if (recv_image->objectName().isEmpty())
            recv_image->setObjectName(QStringLiteral("recv_image"));
        recv_image->resize(400, 300);
        label = new QLabel(recv_image);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 250, 300));
        btn_SaveAs = new QPushButton(recv_image);
        btn_SaveAs->setObjectName(QStringLiteral("btn_SaveAs"));
        btn_SaveAs->setGeometry(QRect(290, 80, 100, 30));
        btn_save = new QPushButton(recv_image);
        btn_save->setObjectName(QStringLiteral("btn_save"));
        btn_save->setGeometry(QRect(290, 0, 100, 30));
        btn_emptyTemp = new QPushButton(recv_image);
        btn_emptyTemp->setObjectName(QStringLiteral("btn_emptyTemp"));
        btn_emptyTemp->setGeometry(QRect(290, 120, 100, 30));

        retranslateUi(recv_image);

        QMetaObject::connectSlotsByName(recv_image);
    } // setupUi

    void retranslateUi(QDialog *recv_image)
    {
        recv_image->setWindowTitle(QApplication::translate("recv_image", "Dialog", 0));
        label->setText(QString());
        btn_SaveAs->setText(QApplication::translate("recv_image", "\345\217\246\345\255\230\344\270\272", 0));
        btn_save->setText(QApplication::translate("recv_image", "\344\277\235\345\255\230", 0));
        btn_emptyTemp->setText(QApplication::translate("recv_image", "\351\207\215\346\226\260\346\216\245\346\224\266", 0));
    } // retranslateUi

};

namespace Ui {
    class recv_image: public Ui_recv_image {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECV_IMAGE_H
