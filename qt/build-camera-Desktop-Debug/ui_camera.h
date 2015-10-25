/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include "qcameraviewfinder.h"

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QAction *actionExit;
    QAction *actionStartCamera;
    QAction *actionStopCamera;
    QAction *actionSettings;
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *viewfinderPage;
    QGridLayout *gridLayout_5;
    QCameraViewfinder *viewfinder;
    QWidget *previewPage;
    QGridLayout *gridLayout_4;
    QLabel *lastImagePreviewLabel;
    QPushButton *lockButton;
    QTabWidget *captureWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QPushButton *takeImageButton;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSlider *exposureCompensation;
    QWidget *tab;
    QGridLayout *gridLayout_2;
    QPushButton *recordButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QSpacerItem *verticalSpacer;
    QPushButton *muteButton;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuDevices;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QStringLiteral("Camera"));
        Camera->resize(668, 422);
        actionExit = new QAction(Camera);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionStartCamera = new QAction(Camera);
        actionStartCamera->setObjectName(QStringLiteral("actionStartCamera"));
        actionStopCamera = new QAction(Camera);
        actionStopCamera->setObjectName(QStringLiteral("actionStopCamera"));
        actionSettings = new QAction(Camera);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        centralwidget = new QWidget(Camera);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(145, 145, 145, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        stackedWidget->setPalette(palette);
        viewfinderPage = new QWidget();
        viewfinderPage->setObjectName(QStringLiteral("viewfinderPage"));
        gridLayout_5 = new QGridLayout(viewfinderPage);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        viewfinder = new QCameraViewfinder(viewfinderPage);
        viewfinder->setObjectName(QStringLiteral("viewfinder"));

        gridLayout_5->addWidget(viewfinder, 0, 0, 1, 1);

        stackedWidget->addWidget(viewfinderPage);
        previewPage = new QWidget();
        previewPage->setObjectName(QStringLiteral("previewPage"));
        gridLayout_4 = new QGridLayout(previewPage);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        lastImagePreviewLabel = new QLabel(previewPage);
        lastImagePreviewLabel->setObjectName(QStringLiteral("lastImagePreviewLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lastImagePreviewLabel->sizePolicy().hasHeightForWidth());
        lastImagePreviewLabel->setSizePolicy(sizePolicy1);
        lastImagePreviewLabel->setFrameShape(QFrame::Box);

        gridLayout_4->addWidget(lastImagePreviewLabel, 0, 0, 1, 1);

        stackedWidget->addWidget(previewPage);

        gridLayout_3->addWidget(stackedWidget, 0, 0, 3, 1);

        lockButton = new QPushButton(centralwidget);
        lockButton->setObjectName(QStringLiteral("lockButton"));

        gridLayout_3->addWidget(lockButton, 1, 1, 1, 2);

        captureWidget = new QTabWidget(centralwidget);
        captureWidget->setObjectName(QStringLiteral("captureWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        takeImageButton = new QPushButton(tab_2);
        takeImageButton->setObjectName(QStringLiteral("takeImageButton"));
        takeImageButton->setEnabled(false);

        gridLayout->addWidget(takeImageButton, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 161, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        exposureCompensation = new QSlider(tab_2);
        exposureCompensation->setObjectName(QStringLiteral("exposureCompensation"));
        exposureCompensation->setMinimum(-4);
        exposureCompensation->setMaximum(4);
        exposureCompensation->setPageStep(2);
        exposureCompensation->setOrientation(Qt::Horizontal);
        exposureCompensation->setTickPosition(QSlider::TicksAbove);

        gridLayout->addWidget(exposureCompensation, 3, 0, 1, 1);

        captureWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        gridLayout_2 = new QGridLayout(tab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        recordButton = new QPushButton(tab);
        recordButton->setObjectName(QStringLiteral("recordButton"));

        gridLayout_2->addWidget(recordButton, 0, 0, 1, 1);

        pauseButton = new QPushButton(tab);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        gridLayout_2->addWidget(pauseButton, 1, 0, 1, 1);

        stopButton = new QPushButton(tab);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        gridLayout_2->addWidget(stopButton, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 76, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 3, 0, 1, 1);

        muteButton = new QPushButton(tab);
        muteButton->setObjectName(QStringLiteral("muteButton"));
        muteButton->setCheckable(true);

        gridLayout_2->addWidget(muteButton, 4, 0, 1, 1);

        captureWidget->addTab(tab, QString());

        gridLayout_3->addWidget(captureWidget, 2, 1, 1, 2);

        Camera->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Camera);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 668, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDevices = new QMenu(menubar);
        menuDevices->setObjectName(QStringLiteral("menuDevices"));
        Camera->setMenuBar(menubar);
        statusbar = new QStatusBar(Camera);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Camera->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuDevices->menuAction());
        menuFile->addAction(actionStartCamera);
        menuFile->addAction(actionStopCamera);
        menuFile->addSeparator();
        menuFile->addAction(actionSettings);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(Camera);
        QObject::connect(recordButton, SIGNAL(clicked()), Camera, SLOT(record()));
        QObject::connect(stopButton, SIGNAL(clicked()), Camera, SLOT(stop()));
        QObject::connect(pauseButton, SIGNAL(clicked()), Camera, SLOT(pause()));
        QObject::connect(actionExit, SIGNAL(triggered()), Camera, SLOT(close()));
        QObject::connect(takeImageButton, SIGNAL(clicked()), Camera, SLOT(takeImage()));
        QObject::connect(lockButton, SIGNAL(clicked()), Camera, SLOT(toggleLock()));
        QObject::connect(muteButton, SIGNAL(toggled(bool)), Camera, SLOT(setMuted(bool)));
        QObject::connect(exposureCompensation, SIGNAL(valueChanged(int)), Camera, SLOT(setExposureCompensation(int)));
        QObject::connect(actionSettings, SIGNAL(triggered()), Camera, SLOT(configureCaptureSettings()));
        QObject::connect(actionStartCamera, SIGNAL(triggered()), Camera, SLOT(startCamera()));
        QObject::connect(actionStopCamera, SIGNAL(triggered()), Camera, SLOT(stopCamera()));

        stackedWidget->setCurrentIndex(0);
        captureWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QMainWindow *Camera)
    {
        Camera->setWindowTitle(QApplication::translate("Camera", "Camera", 0));
        actionExit->setText(QApplication::translate("Camera", "Exit", 0));
        actionStartCamera->setText(QApplication::translate("Camera", "Start Camera", 0));
        actionStopCamera->setText(QApplication::translate("Camera", "Stop Camera", 0));
        actionSettings->setText(QApplication::translate("Camera", "Settings", 0));
        lastImagePreviewLabel->setText(QString());
        lockButton->setText(QApplication::translate("Camera", "Focus", 0));
        takeImageButton->setText(QApplication::translate("Camera", "Capture Photo", 0));
        label->setText(QApplication::translate("Camera", "Exposure Compensation:", 0));
        captureWidget->setTabText(captureWidget->indexOf(tab_2), QApplication::translate("Camera", "Image", 0));
        recordButton->setText(QApplication::translate("Camera", "Record", 0));
        pauseButton->setText(QApplication::translate("Camera", "Pause", 0));
        stopButton->setText(QApplication::translate("Camera", "Stop", 0));
        muteButton->setText(QApplication::translate("Camera", "Mute", 0));
        captureWidget->setTabText(captureWidget->indexOf(tab), QApplication::translate("Camera", "Video", 0));
        menuFile->setTitle(QApplication::translate("Camera", "File", 0));
        menuDevices->setTitle(QApplication::translate("Camera", "Devices", 0));
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
