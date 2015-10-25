#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this, SIGNAL(sendInt(int)),ui->widget,SLOT(setTool(int)));
    ui->toolButton->clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_toolButton_clicked()
{
    emit sendInt( 1 );
    ui->toolButton->setEnabled(0);
    ui->toolButton_2->setEnabled(1);
}

void MainWindow::on_toolButton_2_clicked()
{
    emit sendInt(2);
    ui->toolButton_2->setEnabled(0);
    ui->toolButton->setEnabled(1);
}
