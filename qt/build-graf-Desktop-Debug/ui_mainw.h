/********************************************************************************
** Form generated from reading UI file 'mainw.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINW_H
#define UI_MAINW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "drawarea.h"
#include "setter.h"

QT_BEGIN_NAMESPACE

class Ui_Mainw
{
public:
    QWidget *centralWidget;
    drawArea *widget;
    setter *widget_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Mainw)
    {
        if (Mainw->objectName().isEmpty())
            Mainw->setObjectName(QStringLiteral("Mainw"));
        Mainw->resize(659, 428);
        centralWidget = new QWidget(Mainw);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new drawArea(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 431, 361));
        widget_2 = new setter(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(450, 0, 181, 241));
        Mainw->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Mainw);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 659, 25));
        Mainw->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Mainw);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Mainw->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Mainw);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Mainw->setStatusBar(statusBar);

        retranslateUi(Mainw);

        QMetaObject::connectSlotsByName(Mainw);
    } // setupUi

    void retranslateUi(QMainWindow *Mainw)
    {
        Mainw->setWindowTitle(QApplication::translate("Mainw", "Mainw", 0));
    } // retranslateUi

};

namespace Ui {
    class Mainw: public Ui_Mainw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINW_H
