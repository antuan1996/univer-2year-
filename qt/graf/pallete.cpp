#include "pallete.h"

pallete::pallete(QWidget *parent) :
    QWidget(parent)
{
    r_base = 0;
    setGeometry(0, 0, 255, 255);
    //setSizePolicy(QSizePolicy::Fixed);
}
void pallete::setRval(int r)
{
    r_base = r;
    update();
}

void pallete::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen mypen;
    for(int g = 0; g < 256; ++g)
        for(int b = 0; b < 256; ++b)
        {
            mypen.setColor(QColor(r_base, g, b));
            painter.setPen(mypen);
            painter.drawPoint(g,b);
        }
}
void pallete::mousePressEvent(QMouseEvent *ev)
{
    QPoint mous_pos = ev->pos();
    QColor res;
    res.setRed(r_base);
    res.setGreen(mous_pos.x());
    res.setBlue(mous_pos.y());
    emit colorClicked(res);
}
