#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(get_val()));
    connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::get_val(){
    std::string buf = ui->lineEdit->text().toStdString();
    const char * val1 = buf.c_str();
    buf = ui->lineEdit_2->text().toStdString();
    const char * val2 = buf.c_str();
    long long op1, op2;
    if(strlen(val1) ==0 || strlen(val2) == 0 || strlen(val1) > 10 || strlen(val2) > 10  || sscanf(val1, "%ld", &op1) == 0 || sscanf(val2, "%ld", &op2) == 0 )
        ui->textBrowser->setText("Incorrect value");
    else{
        std::string zn;
        double res;
        QString ans;
        if(ui->comboBox->currentIndex() == 0){
            zn = " + ";
            res = op1 + op2;
            ans =  QString::number(res);
        }
        if(ui->comboBox->currentIndex() == 1){
            zn = " - ";
            res = op1 - op2;
            ans =  QString::number(res);
        }
        if(ui->comboBox->currentIndex() == 2){
            zn = " * ";
            res = op1 * op2;
            ans =  QString::number(res);
        }
        if(ui->comboBox->currentIndex() == 3){
            zn = " / ";

            if(op2 != 0){
                res = 1.*op1 / op2;
                ans =  QString::number(res);

            }
            else
                ans = QString("INfinity");
        }
        //QString prev = ui->textBrowser->str
        ui->textBrowser->setText( ui->lineEdit->text() + QString(zn.c_str()) + ui->lineEdit_2->text()+QString(" = ") + ans + "\n");
    }
}
