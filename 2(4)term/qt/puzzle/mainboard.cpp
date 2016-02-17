#include "mainboard.h"
#include "pmodel.h"
#include "pview.h"
#include "control.h"
#include "previewfiledialog.h"

MainBoard::MainBoard(QWidget *parent) :
    QWidget(parent), puzzle( nullptr )
{

    is_pressed = false;
    QRect buf = QApplication::desktop()->availableGeometry();
    setGeometry(0, 0, buf.width(), buf.height());

    ctrl = new Control( width(), height(), this);
    connect( ctrl, SIGNAL(data_changed(Control*)), this, SLOT(create_puzzle(Control*)) );
    //ctrl->show();
    //showMaximized();
}

void MainBoard::load_puzzle()
{
    QFileDialog* dialog = new PreviewFileDialog(this, "Open image", "", tr("Image Files (*.png *.jpg *.bmp *.tif);;"));
    dialog->setAcceptMode(QFileDialog::AcceptOpen);
    connect( dialog, SIGNAL(currentChanged(QString)), ctrl, SLOT(preview_change(QString)) );
    dialog->exec();
    QString filename = dialog->selectedFiles().at( 0 );
    ctrl->img_name = filename;
    ctrl->load_image();
    show_settings();
}
void MainBoard::show_settings()
{
    ctrl->show();
}


void MainBoard::create_puzzle( Control* set )
{
    delete_puzzle();
    puzzle  = new PModel( set, this);
    puzzle->create_view( set);
    connect( this, SIGNAL( click_event(QPoint) ), puzzle, SLOT(click_event(QPoint)));
    connect( this, SIGNAL( move_event(QPoint) ), puzzle, SLOT(move_event(QPoint)));
    connect( this, SIGNAL( release_event() ), puzzle, SLOT(release_event()));
    connect( set, SIGNAL( shuffle_puzzle()), puzzle, SLOT(shuffle()) );
    connect( set, SIGNAL( view_changed(bool,bool,bool)), puzzle, SLOT(update_view(bool,bool,bool)));
}
void MainBoard::delete_puzzle()
{
    if(puzzle != nullptr )
        delete puzzle;
    puzzle = nullptr;
}

MainBoard::~MainBoard()
{
    delete_puzzle();
}

void MainBoard::mousePressEvent(QMouseEvent *ev)
{
    is_pressed = true;
    emit click_event( ev->pos() );

}
void MainBoard::mouseReleaseEvent(QMouseEvent *ev)
{
    is_pressed = false;
    emit release_event();
}
void MainBoard::mouseMoveEvent(QMouseEvent *ev)
{
    if(is_pressed)
    {
        emit move_event( ev->pos() );
    }
}

void MainBoard::paintEvent(QPaintEvent *ev)
{

    QPainter painter( this );
    if( puzzle != nullptr)
        puzzle->show_view( &painter );
}
