/********************************************************************************
** Form generated from reading UI file 'node_info.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NODE_INFO_H
#define UI_NODE_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_node_info
{
public:

    void setupUi(QDialog *node_info)
    {
        if (node_info->objectName().isEmpty())
            node_info->setObjectName(QStringLiteral("node_info"));
        node_info->resize(400, 300);

        retranslateUi(node_info);

        QMetaObject::connectSlotsByName(node_info);
    } // setupUi

    void retranslateUi(QDialog *node_info)
    {
        node_info->setWindowTitle(QApplication::translate("node_info", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class node_info: public Ui_node_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NODE_INFO_H
