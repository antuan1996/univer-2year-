#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "iostream"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(add_event()) );
    connect(ui->toolButton_2, SIGNAL(clicked()), this, SLOT(add_event_back()) );
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::add_event(){
    if(ui->listWidget->count() == 0) return;
    int r = ui->listWidget->currentRow();
    QListWidgetItem* curw = ui->listWidget->takeItem(r);
    if(curw == 0) return;
    ui->listWidget_2->insertItem(0, curw->text());
    //ui->listWidget->removeItemWidget(curw);
    //ui->listWidget_2->show();
    //std::cout << curw->text().toStdString() << std::endl;
}
void MainWindow::add_event_back(){
    if(ui->listWidget_2->count() == 0) return;
    int r = ui->listWidget_2->currentRow();
    QListWidgetItem* curw = ui->listWidget_2->takeItem(r);
    if(curw == 0) return;
    QString buf = curw->text();
    ui->listWidget->insertItem(0, buf);
    //ui->listWidget->removeItemWidget(curw);
    //ui->listWidget_2->show();
    //std::cout << curw->text().toStdString() << std::endl;
}
