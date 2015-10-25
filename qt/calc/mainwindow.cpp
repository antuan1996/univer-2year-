#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string"
#include <cstdio>
#include <cstring>
#include <QIntValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QIntValidator  *v = new QIntValidator(100, 999, this);
    ui->val1->setValidator(v);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(get_sum()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}
void MainWindow::get_sum(){
    std::string buf = ui->val1->text().toStdString();
    const char * val1 = buf.c_str();
    buf = ui->val2->text().toStdString();
    const char * val2 = buf.c_str();
    long long op1, op2;
    if(strlen(val1) > 10 || strlen(val2) > 10  || sscanf(val1, "%ld", &op1) == 0 || sscanf(val2, "%ld", &op2) == 0 ){
        ui->lineEdit_3->setText("INCORR. VAL");
        ui->lineEdit_4->setText("INCORR. VAL");
    }
    else
    {

            ui->lineEdit_3->setText(QString::number(op1 + op2));
            ui->lineEdit_4->setText(QString::number(op1 * op2));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}
