#include "subw.h"
#include "ui_subw.h"

subw::subw(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::subw)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(but_press()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(close()));
}

subw::~subw()
{
    delete ui;
}
void subw::but_press(){
    int n,m;
    std::string buf = ui->lineEdit->text().toStdString();

    if(sscanf(buf.c_str(), "%d", &n) != 1) return;
    buf = ui->lineEdit_2->text().toStdString();
    if(sscanf(buf.c_str(), "%d", &m) != 1) return;
    int_pair cur;
    cur.a = n;
    cur.b = m;
    emit send_pair(cur);
    this->close();
}
