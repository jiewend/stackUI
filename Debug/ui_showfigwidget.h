/********************************************************************************
** Form generated from reading UI file 'showfigwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWFIGWIDGET_H
#define UI_SHOWFIGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ShowFigWidget
{
public:
    QLabel *label;
    QPushButton *pushButton_open;
    QPushButton *pushButton_draw;
    QPushButton *pushButton_send;
    QPushButton *pushButton_close;

    void setupUi(QWidget *ShowFigWidget)
    {
        if (ShowFigWidget->objectName().isEmpty())
            ShowFigWidget->setObjectName(QStringLiteral("ShowFigWidget"));
        ShowFigWidget->resize(350, 220);
        ShowFigWidget->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label = new QLabel(ShowFigWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 200, 200));
        label->setStyleSheet(QLatin1String("QLabel{\n"
"     border-width: 1px;\n"
"     border-style: solid;\n"
"     border-color: rgb(0, 0, 0);\n"
"}"));
        pushButton_open = new QPushButton(ShowFigWidget);
        pushButton_open->setObjectName(QStringLiteral("pushButton_open"));
        pushButton_open->setGeometry(QRect(220, 10, 119, 33));
        pushButton_draw = new QPushButton(ShowFigWidget);
        pushButton_draw->setObjectName(QStringLiteral("pushButton_draw"));
        pushButton_draw->setGeometry(QRect(220, 60, 119, 33));
        pushButton_send = new QPushButton(ShowFigWidget);
        pushButton_send->setObjectName(QStringLiteral("pushButton_send"));
        pushButton_send->setGeometry(QRect(220, 120, 119, 33));
        pushButton_close = new QPushButton(ShowFigWidget);
        pushButton_close->setObjectName(QStringLiteral("pushButton_close"));
        pushButton_close->setGeometry(QRect(220, 170, 119, 33));

        retranslateUi(ShowFigWidget);

        QMetaObject::connectSlotsByName(ShowFigWidget);
    } // setupUi

    void retranslateUi(QWidget *ShowFigWidget)
    {
        ShowFigWidget->setWindowTitle(QApplication::translate("ShowFigWidget", "Form", 0));
        label->setText(QString());
        pushButton_open->setText(QApplication::translate("ShowFigWidget", "\346\211\223\345\274\200", 0));
        pushButton_draw->setText(QApplication::translate("ShowFigWidget", "\346\266\202\351\270\246", 0));
        pushButton_send->setText(QApplication::translate("ShowFigWidget", "\345\217\221\351\200\201", 0));
        pushButton_close->setText(QApplication::translate("ShowFigWidget", "\345\205\263\351\227\255", 0));
    } // retranslateUi

};

namespace Ui {
    class ShowFigWidget: public Ui_ShowFigWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWFIGWIDGET_H
