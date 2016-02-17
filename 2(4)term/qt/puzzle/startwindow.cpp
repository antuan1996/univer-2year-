#include "startwindow.h"
#include "ui_startwindow.h"
#include "control.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    setWindowState( Qt::WindowMaximized );
    QPalette pal( ui->centralwidget->palette() );
    pal.setColor( QPalette::Background, Qt::blue);
    QBrush back_brush( QPixmap(":/images/wood_pattern.jpg" ));
    pal.setBrush( QPalette::Background, back_brush );
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(pal);

}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_actionPuzzles_triggered()
{
    ui->centralwidget->load_puzzle();
}

void StartWindow::on_action_triggered()
{
    ui->centralwidget->show_settings();
}

void StartWindow::on_action_2_triggered()
{
    close();
}
