#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_3->setCurrentCell(0,0, QItemSelectionModel::SelectCurrent);
}

MainWindow::~MainWindow()
{
    delete ui;
}
