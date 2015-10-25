#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(int h, int w, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->lineEdit->setText(QString::number(h));
    ui->lineEdit_2->setText(QString::number(w));
    QIntValidator* val = new QIntValidator(1,10,this);
    ui->lineEdit->setValidator(val);
    ui->lineEdit_2->setValidator(val);
    ui->lineEdit->selectAll();
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    int h = str.toInt();
    str = ui->lineEdit_2->text();
    int w = str.toInt();
    emit send_coord(h, w);
    this->close();
}
