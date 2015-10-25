/********************************************************************************
** Form generated from reading UI file 'imagesettings.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESETTINGS_H
#define UI_IMAGESETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_ImageSettingsUi
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QComboBox *imageResolutionBox;
    QLabel *label_6;
    QComboBox *imageCodecBox;
    QLabel *label_7;
    QSlider *imageQualitySlider;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImageSettingsUi)
    {
        if (ImageSettingsUi->objectName().isEmpty())
            ImageSettingsUi->setObjectName(QStringLiteral("ImageSettingsUi"));
        ImageSettingsUi->resize(332, 270);
        gridLayout = new QGridLayout(ImageSettingsUi);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(ImageSettingsUi);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 0, 0, 1, 2);

        imageResolutionBox = new QComboBox(groupBox_2);
        imageResolutionBox->setObjectName(QStringLiteral("imageResolutionBox"));

        gridLayout_2->addWidget(imageResolutionBox, 1, 0, 1, 2);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_2->addWidget(label_6, 2, 0, 1, 2);

        imageCodecBox = new QComboBox(groupBox_2);
        imageCodecBox->setObjectName(QStringLiteral("imageCodecBox"));

        gridLayout_2->addWidget(imageCodecBox, 3, 0, 1, 2);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        imageQualitySlider = new QSlider(groupBox_2);
        imageQualitySlider->setObjectName(QStringLiteral("imageQualitySlider"));
        imageQualitySlider->setMaximum(4);
        imageQualitySlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(imageQualitySlider, 4, 1, 1, 1);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 14, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(ImageSettingsUi);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 1);


        retranslateUi(ImageSettingsUi);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImageSettingsUi, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImageSettingsUi, SLOT(reject()));

        QMetaObject::connectSlotsByName(ImageSettingsUi);
    } // setupUi

    void retranslateUi(QDialog *ImageSettingsUi)
    {
        ImageSettingsUi->setWindowTitle(QApplication::translate("ImageSettingsUi", "Dialog", 0));
        groupBox_2->setTitle(QApplication::translate("ImageSettingsUi", "Image", 0));
        label_8->setText(QApplication::translate("ImageSettingsUi", "Resolution:", 0));
        label_6->setText(QApplication::translate("ImageSettingsUi", "Image Format:", 0));
        label_7->setText(QApplication::translate("ImageSettingsUi", "Quality:", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageSettingsUi: public Ui_ImageSettingsUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESETTINGS_H
