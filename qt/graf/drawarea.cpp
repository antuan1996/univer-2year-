#include "drawarea.h"

double func1( double x)
{ return x*x*x;}

double func2( double x)
{ return pow((x-4), 3);}

double func3( double x)
{ return pow((x+6), 3);}


drawArea::drawArea(QWidget *parent) :
    QWidget(parent)
{
    sx = -7.;
    fx = 7.;
    sy = -7.;
    fy = 7.;
    f = func1;
    isGrid = false;
    line_style = 1;
    line_color = QColor(0, 0, 0);
    back_color = QColor( 0, 255,255 );
}
QPoint drawArea::getp( double px, double py)
{
    double delx = ( fx - sx ) / width();
    double dely = ( fy - sy ) / height();
    px = std::max( sx, ( std::min( px, fx )));
    py = std::max( sy, ( std::min( py, fy )));
    QPoint res;
    res.setX((px - sx)/delx +0.5);
    res.setY( height() -((py - sy)/ dely + 0.5));
    return res;
}

void drawArea::paintEvent(QPaintEvent *ev){
    QPainter painter(this);
    painter.setBackground(QBrush(back_color));

    QPalette curpal;
    setAutoFillBackground(true);
    curpal.setColor(QPalette::Background, back_color);
    setPalette(curpal);

    QPen curpen;

    curpen.setColor(back_color);
    curpen.setWidth(1);
    painter.setPen(curpen);
    painter.drawRect(0,0, width(), height());

    curpen.setColor(Qt::black);
    curpen.setWidth(3);
    painter.setPen(curpen);

    QPoint sp = getp(sx,0);
    QPoint fp = getp(fx,0);
    painter.drawLine(sp, fp);
    sp = getp(0, sy);
    fp = getp(0, fy);
    painter.drawLine(sp, fp);

    double delx = ( fx - sx ) / width();
    double dely = ( fy - sy ) / height();

    if(isGrid)
    {

        curpen.setWidth(1);
        painter.setPen(curpen);
        for( int x = sx + 0.5; x < fx; ++x){
            //double x = sx + delx * i;
            sp = getp(x, sy);
            fp = getp(x, fy);
            painter.drawLine(sp, fp);
            sp = getp(x,0);
            painter.drawText(sp.x(), sp.y(), QString::number(x));
        }
        for( int y = sy+0.5; y < fy; ++y){
            //double y = sy + delx * i;
            sp = getp(sx, y);
            fp = getp(fx, y);
            painter.drawLine(sp, fp);
            sp = getp(0,y);
            painter.drawText(sp.x(), sp.y(), QString::number(y));

        }
    }
    curpen.setColor(line_color);
    curpen.setWidth(1);
    painter.setPen(curpen);

    //curpen.setStyle(Qt::PenStyle(line_style));

    //painter.setFont(QFont("Arial", 30));


    QPoint prevp = getp(sx, f(sx));

    for(int i = 1; i < width(); ++i)
    {
        double curx = sx + delx * i;
        double cury = f(curx);
        ++prevp.rx();
        QPoint curp = getp(curx, cury);
        //std::cout << curp.x() << " " << curp.y() << std::endl;
        painter.drawLine(prevp, curp);
        //painter.
        //        (prevp, curp);

        prevp = curp;
    }

    double kx = getZero(sx, fx);
    //std::cout << kx << std::endl;

    curpen.setColor(Qt::red);
    curpen.setWidth(5);
    painter.setPen(curpen);
    QPoint ctr =getp(kx, 0);
    painter.drawEllipse(ctr, 4, 4);
}
void drawArea::getSettings(QColor lc, QColor bc, bool isg)
{
    line_color = lc;
    back_color = bc;
    isGrid = isg;
    update();
}
void drawArea::getfuncid(int id)
{
    fid = id;
    f = func1;
    if( id == 1) f = func2;
    if( id == 2) f = func3;
    update();
}
double drawArea::getZero(double lb, double rb)
{
    if( fabs( rb - lb) < 1e-10)
    {
        emit foundedPoint(lb, f(lb));
        return lb;
    }
    double x1 = (lb + rb)/2;
    //std::cout << x1 << std::endl;
    double a = f( x1 );
    if(a < 0) return getZero(x1, rb);
    return getZero(lb, x1);
}
void drawArea::wheelEvent(QWheelEvent *ev)
{
    QPoint p = ev->angleDelta();
    std::cout << p.x() <<' '<<p.y() << std::endl;
    if(p.y() > 0)
    {
        double del = (fx - sx)/10.;
        sx += del;
        fx -= del;
    }
    else
    {
        double r = (fx - sx)/8.;
        sx -= r;
        fx += r;
    }
    update();
}
