/********************************************************************************
** Form generated from reading UI file 'setter.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTER_H
#define UI_SETTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_setter
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QLabel *label;
    QRadioButton *radioButton;

    void setupUi(QWidget *setter)
    {
        if (setter->objectName().isEmpty())
            setter->setObjectName(QStringLiteral("setter"));
        setter->resize(198, 185);
        pushButton = new QPushButton(setter);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(22, 110, 151, 27));
        pushButton_2 = new QPushButton(setter);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 70, 151, 27));
        comboBox = new QComboBox(setter);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(110, 30, 61, 27));
        label = new QLabel(setter);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 30, 81, 27));
        radioButton = new QRadioButton(setter);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(30, 150, 115, 22));

        retranslateUi(setter);

        QMetaObject::connectSlotsByName(setter);
    } // setupUi

    void retranslateUi(QWidget *setter)
    {
        setter->setWindowTitle(QApplication::translate("setter", "settings", 0));
        pushButton->setText(QApplication::translate("setter", "set back color...", 0));
        pushButton_2->setText(QApplication::translate("setter", "set line color...", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("setter", "x^3", 0)
         << QApplication::translate("setter", "(x-4)^3", 0)
         << QApplication::translate("setter", "(x+6)^3", 0)
        );
        label->setText(QApplication::translate("setter", "function", 0));
        radioButton->setText(QApplication::translate("setter", "Grid", 0));
    } // retranslateUi

};

namespace Ui {
    class setter: public Ui_setter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTER_H
