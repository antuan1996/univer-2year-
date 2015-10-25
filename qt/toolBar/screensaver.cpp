#include "screensaver.h"
#include "ui_screensaver.h"
#include "mainwindow.h"
screensaver::screensaver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::screensaver)
{
    ui->setupUi(this);
    id = startTimer(3000);
}
void screensaver::timerEvent(QTimerEvent *){
    killTimer(id);
    MainWindow *w = new MainWindow();
    w->show();
    this->hide();
}

screensaver::~screensaver()
{
    delete ui;
}
