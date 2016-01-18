#include "new_record.h"
#include "ui_new_record.h"

new_record::new_record(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::new_record)
{
    ui->setupUi(this);
}

new_record::~new_record()
{
    delete ui;
}
