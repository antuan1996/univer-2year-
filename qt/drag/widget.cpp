#include "widget.h"
#include "ui_widget.h"
#include <iostream>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->listWidget->setDragEnabled(1);
    ui->listWidget_2->setAcceptDrops(1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_listWidget_3_itemChanged(QListWidgetItem *item)
{
    std::cout << "item->text().toStdString()" << std::endl;
    ui->listWidget_3->clear();
    item = ui->listWidget->currentItem();
    std::cout << item->text().toStdString();
    ui->listWidget->takeItem(ui->listWidget->currentRow());
    ui->listWidget->update();
}

void Widget::on_pushButton_clicked()
{
    ui->listWidget->addItem(ui->lineEdit->text());
}
