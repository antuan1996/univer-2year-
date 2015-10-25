#include "setter.h"
#include "ui_setter.h"

setter::setter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setter)
{
    ui->setupUi(this);
    style = 1;
    line_col = QColor(0, 0, 0);
    back_col = QColor( 0, 255,255 );
    grid = false;
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),ui->widget,SLOT(setRval(int)));
    connect(ui->widget,SIGNAL(colorClicked(QColor)),this,SLOT(getColor(QColor)));
    ui->horizontalSlider->setValue(0);
    emit data_changed(line_col, back_col, grid);

}

setter::~setter()
{
    delete ui;
}
void setter::setparams(int fid, bool b)
{
    ui->comboBox->setCurrentIndex(fid);
    if(b)
        ui->radioButton->toggle();
    update();
}

void setter::on_pushButton_2_clicked()
{
    //QColor ncol = QColorDialog::getColor( line_col, this);
    //if(ncol.isValid()){
    line_col = curcolor;
    emit data_changed(line_col, back_col, grid);
   // }
}

void setter::on_pushButton_clicked()
{
    //QColor ncol = QColorDialog::getColor( back_col, this);
    //if(ncol.isValid()){
    back_col = curcolor;
    emit data_changed(line_col, back_col, grid);
    //}
}

void setter::on_comboBox_currentIndexChanged(int index)
{
    emit sendfid(index);
}

void setter::on_radioButton_toggled(bool checked)
{
    grid = checked;
    emit data_changed(line_col, back_col, grid);
}
void setter::getPoint(double x, double y)
{
    ui->label_4->setText("Zero X is " + QString::number(x, 'f') + "; f(x) = " + QString::number(y, 'f'));
}

void setter::getColor(QColor col)
{
    curcolor = col;
    ui->label->setText("R = " + QString::number(col.red()));
    ui->label_2->setText("G = " + QString::number(col.green()));
    ui->label_3->setText("B = " + QString::number(col.blue()));
}
