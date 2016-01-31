#include "mainboard.h"
#include "pmodel.h"
#include "pview.h"
#include "settings.h"
MainBoard::MainBoard(QWidget *parent) :
    QWidget(parent)
{
    is_pressed = false;
    setWindowState( Qt::WindowMaximized );
    //showMaximized();
}
bool MainBoard::create_puzzle(Settings* set)
{
    info = set;
    QRect buf = QApplication::desktop()->availableGeometry();
    setGeometry(0, 0, buf.width(), buf.height());
    set->board_w = width();
    set->board_h = height();

    puzzle  = new PModel(set, this);
    connect( this, SIGNAL( click_event(QPoint) ), puzzle, SLOT(click_event(QPoint)));
    connect( this, SIGNAL( move_event(QPoint) ), puzzle, SLOT(move_event(QPoint)));
    connect( this, SIGNAL( release_event() ), puzzle, SLOT(release_event()));

    view = new PView(set, this);
    puzzle->set_view( view );
    return true;
}

MainBoard::~MainBoard()
{
    delete view;
    delete puzzle;
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
    this->setPalette(QPalette( Qt::blue ));
    if( puzzle != nullptr)
        puzzle->show_view( &painter );
}
