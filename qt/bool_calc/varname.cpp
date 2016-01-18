#include "varname.h"
#include "ui_varname.h"

varname::varname(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::varname)
{
    ui->setupUi(this);
}

varname::~varname()
{
    delete ui;
}
