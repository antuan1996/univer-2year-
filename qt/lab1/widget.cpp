#include "widget.h"
#include "ui_widget.h"
#include "iostream"
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    p = ui->pushButton->pos();
    //p.setX(p.x() + ui->horizontalLayoutWidget->pos());
    //p.setX(p.x() + ui->horizontalLayoutWidget->pos());
    f = 1;
    connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(picture_change()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(but_move()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(but_sys()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(but_opac()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(close()));
    //this->setStyleSheet("border: 1px solid red");
    //this->setWindowFlags(Qt::CustomizeWindowHint);

}
void Widget::but_sys(){
    if(f)
        this->setWindowFlags(Qt::CustomizeWindowHint);
    else
        this->setWindowFlags(Qt::Desktop);
    this->show();
    f = !f;
}

Widget::~Widget()
{
    delete ui;
}
void Widget::but_opac(){
        tim_id = startTimer(100);
    }
void Widget::timerEvent(QTimerEvent *ev){
    double op = this->windowOpacity();
    if(op > 0.2) this->setWindowOpacity(op - 0.1);
        else{
                this->setWindowOpacity(1);
                 killTimer(tim_id);
            }
    ev->accept();
}

void Widget::picture_change(){
    if(ui->label->isVisible()) ui->label->hide();
        else{
            ui->label->setVisible(1);

    }
}
void Widget::but_move(){
    QPoint curp = ui->pushButton->pos();
    //ui->pushButton->setGeometry();
    QPoint form_pos = ui->horizontalLayoutWidget->pos();
    std::cout << p.x() <<' '<<p.y() << std::endl;
    if(curp.y() < 10) ui->pushButton->move(p);
        else ui->pushButton->move(curp.x(), curp.y()-10);

}
