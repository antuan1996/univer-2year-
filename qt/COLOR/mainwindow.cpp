#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPalette pal = this->palette();
    pal.setColor(QPalette::Window,QColorDialog::getColor());
    this->setPalette( pal);
}

MainWindow::~MainWindow()
{
    delete ui;
}
