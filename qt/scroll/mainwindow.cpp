#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProgressBar>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QProgressBar * pr = new QProgressBar;
    pr->setFixedSize(200,1000);
    ui->scrollArea->setWidget(pr);
    //ui->scrollArea->setWidget(ui->horizontalSlider);
}

MainWindow::~MainWindow()
{
    delete ui;
}
