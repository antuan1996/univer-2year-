/********************************************************************************
** Form generated from reading UI file 'subw.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBW_H
#define UI_SUBW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_subw
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *subw)
    {
        if (subw->objectName().isEmpty())
            subw->setObjectName(QStringLiteral("subw"));
        subw->resize(330, 144);
        horizontalLayout = new QHBoxLayout(subw);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(subw);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(subw);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(subw);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaxLength(6);

        gridLayout_2->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_2 = new QLineEdit(subw);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMaxLength(6);

        gridLayout_2->addWidget(lineEdit_2, 1, 1, 1, 1);


        horizontalLayout->addLayout(gridLayout_2);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        pushButton = new QPushButton(subw);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(subw);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_3->addWidget(pushButton_2, 1, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_3);


        retranslateUi(subw);

        QMetaObject::connectSlotsByName(subw);
    } // setupUi

    void retranslateUi(QWidget *subw)
    {
        subw->setWindowTitle(QApplication::translate("subw", "getting values", 0));
        label->setText(QApplication::translate("subw", "\320\237\320\265\321\200\320\262\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", 0));
        label_2->setText(QApplication::translate("subw", "\320\222\321\202\320\276\321\200\320\276\320\265 \321\207\320\270\321\201\320\273\320\276", 0));
        pushButton->setText(QApplication::translate("subw", "Okay", 0));
        pushButton_2->setText(QApplication::translate("subw", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class subw: public Ui_subw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBW_H
