#include "control.h"
#include "ui_control.h"

Control::Control(int bw, int bh, QWidget *parent) :
    QWidget(parent),mask_horiz( "cross.bmp" ), mask_vert("cross_vert.bmp") ,ui(new Ui::Control)
{
    board_w = bw;
    board_h = bh;
    n_horiz = 2;
    n_vert  = 2;
    ui->setupUi(this);
}

Control::~Control()
{
    delete ui;
}


void Control::scale_puzzle()
{
    puzzle_h = data.height();
    puzzle_w = data.width();

    /*
    if( 2 * puzzle_w > board_w )
    {
        double mn = board_w / ( 2 * puzzle_w );
        puzzle_w *= mn;
        puzzle_h *= mn;
    }
    if( 2 * puzzle_h > board_h )
    {
        double mn = board_h / ( 2 * puzzle_h );
        puzzle_w *= mn;
        puzzle_h *= mn;
    }
    */
    int div = n_horiz * 3;
        puzzle_w += div - puzzle_w % div;
    div = n_vert * 3;
        puzzle_h += div - puzzle_h % div;

    picture = data.scaled(puzzle_w, puzzle_h);
    emit data_changed( this );
}

void Control::on_pushButton_2_clicked()
{
    QString file_name = QFileDialog::getOpenFileName( this, "Open Image", "","(*.jpg *.jpeg *.png)");
    ui->image_name->setText( file_name );
    if( data.load( file_name ))
    {

        scale_puzzle();
        ui->imagests_lbl->setText( "Loaded" );
        ui->load_buttn->setEnabled( true );
        ui->tab_2->setEnabled( true );
        ui->tab_3->setEnabled( true );
        ui->tab_4->setEnabled( true );

    }
    else
    {
        ui->imagests_lbl->setText( "Opening Error" );
        ui->load_buttn->setEnabled( false );
        ui->tab_2->setEnabled( false );
        ui->tab_3->setEnabled( false );
        ui->tab_4->setEnabled( false );

    }
}

void Control::on_load_buttn_clicked()
{
    ui->tabWidget->setCurrentIndex( 1 );
}

void Control::on_lvl_slider_valueChanged(int value)
{
    level = value;
    n_horiz = 2 * level;
    n_vert  = 2 * level;
    scale_puzzle();
}

void Control::on_nextlvl_buttn_clicked()
{
    ui->tabWidget->setCurrentIndex( 2 );
}

void Control::on_add_buttn_clicked()
{
    ui->tabWidget->setCurrentIndex( 3 );
}

void Control::on_pushButton_clicked()
{
    emit shuffle_puzzle();
}
