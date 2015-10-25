#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(get_num()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete h;
}
void MainWindow::get_pair(int_pair s){
    ui->label->setText(QString::number(s.a));
    ui->label_2->setText(QString::number(s.b));
    ui->label_7->setText(QString::number(s.a+s.b));
    ui->label_8->setText(QString::number(s.a*s.b));
}
void MainWindow::get_num(){
    h = new subw(this);
    connect(h, SIGNAL(send_pair(int_pair)), this, SLOT(get_pair(int_pair)));
    //h->setModal(true);
    h->exec();
}
