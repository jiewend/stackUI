/********************************************************************************
** Form generated from reading UI file 'topo.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOPO_H
#define UI_TOPO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Topo
{
public:
    QPushButton *btn_changeTracefile;

    void setupUi(QDialog *Topo)
    {
        if (Topo->objectName().isEmpty())
            Topo->setObjectName(QStringLiteral("Topo"));
        Topo->resize(600, 400);
        btn_changeTracefile = new QPushButton(Topo);
        btn_changeTracefile->setObjectName(QStringLiteral("btn_changeTracefile"));
        btn_changeTracefile->setGeometry(QRect(470, 365, 115, 30));

        retranslateUi(Topo);

        QMetaObject::connectSlotsByName(Topo);
    } // setupUi

    void retranslateUi(QDialog *Topo)
    {
        Topo->setWindowTitle(QApplication::translate("Topo", "Dialog", 0));
        btn_changeTracefile->setText(QApplication::translate("Topo", "change tracefile", 0));
    } // retranslateUi

};

namespace Ui {
    class Topo: public Ui_Topo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOPO_H
