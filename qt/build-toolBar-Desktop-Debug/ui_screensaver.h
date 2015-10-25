/********************************************************************************
** Form generated from reading UI file 'screensaver.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREENSAVER_H
#define UI_SCREENSAVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screensaver
{
public:
    QLabel *label;

    void setupUi(QWidget *screensaver)
    {
        if (screensaver->objectName().isEmpty())
            screensaver->setObjectName(QStringLiteral("screensaver"));
        screensaver->resize(612, 344);
        label = new QLabel(screensaver);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 621, 351));
        label->setPixmap(QPixmap(QString::fromUtf8("../lab1/DanielSimon_TronLegacy_LightRunner_wallpaper1920.jpg")));
        label->setScaledContents(true);

        retranslateUi(screensaver);

        QMetaObject::connectSlotsByName(screensaver);
    } // setupUi

    void retranslateUi(QWidget *screensaver)
    {
        screensaver->setWindowTitle(QApplication::translate("screensaver", "Form", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class screensaver: public Ui_screensaver {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREENSAVER_H
