#include "mainboard.h"
#include "ui_mainboard.h"

MainBoard::MainBoard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainBoard)
{
    ui->setupUi(this);
}

MainBoard::~MainBoard()
{
    delete ui;
}
