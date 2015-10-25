#include "board.h"

board::board(QWidget *parent) :
    QWidget(parent)
{
    setMouseTracking(true);
    isDown = false;
    mywidth = 1;
    mycolour = Qt::black;
    std::cout << width() << " " <<  height() << std::endl;
    pixm = nullptr;

}
void board::mousePressEvent(QMouseEvent *ev)
{
    isDown = true;
    prevp = ev->pos();
}

void board::mouseMoveEvent(QMouseEvent *ev)
{
    if( isDown )
    {
        QPoint curp = mapFromGlobal(QCursor::pos());
        QPen curpen;
        curpen.setWidth(mywidth);
        curpen.setColor(mycolour);

        QPainter painter(pixm);
        painter.setPen(curpen);

        painter.drawLine(prevp, curp);
        prevp = curp;
    }
    update();

}
void board::mouseReleaseEvent(QMouseEvent *)
{
    isDown = false;
    std::cout << width() << " " <<  height() << std::endl;
}
void board::paintEvent(QPaintEvent *)
{
        if(pixm == nullptr)
        {
            pixm = new QPixmap(width(), height());
            pixm->fill();
        }
        QPainter painter( this);
        painter.drawPixmap(0,0, width(), height(), *pixm);
}
void board::setTool(int t)
{
    switch( t )
    {
        case(1):
        {
           mycolour = (Qt::green);
           mywidth = 1;
           break;
        }
        default:
        {
            mycolour = (Qt::white);
            mywidth = 50;
            break;
        }
    }
}
