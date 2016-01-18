#include "reader_view.h"
#include "ui_reader_view.h"

reader_view::reader_view(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reader_view)
{
    ui->setupUi(this);
}

reader_view::~reader_view()
{
    delete ui;
}
