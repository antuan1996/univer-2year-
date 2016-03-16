#include "startwindow.h"
#include "ui_startwindow.h"
#include "control.h"
#include "about.h"
StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    setWindowState( Qt::WindowMaximized );
    ui->statusbar->showMessage( "Чтобы начать, Выберете изображение для создания пазла" );

    QPalette pal( ui->centralwidget->palette() );
    pal.setColor( QPalette::Background, Qt::blue);
    QBrush back_brush( QPixmap(":/images/wood_pattern.jpg" ));
    pal.setBrush( QPalette::Background, back_brush );
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(pal);
    connect( ui->centralwidget, SIGNAL(status_changed(QString)), this, SLOT(set_current_status(QString)) );
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::set_current_status( QString str )
{
    ui->statusbar->showMessage( str );
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

void StartWindow::on_action_3_triggered()
{
    about* d = new about( this);
    d->exec();
    d->deleteLater();
}
