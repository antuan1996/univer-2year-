#include "types_view.h"
#include "ui_types_view.h"

types_view::types_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::types_view)
{
    ui->setupUi(this);
}

types_view::~types_view()
{
    delete ui;
}
