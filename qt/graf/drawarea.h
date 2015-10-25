#ifndef DRAWAREA_H
#define DRAWAREA_H

#include <QWidget>
#include <QPainter>
#include <QWheelEvent>
#include <cmath>
#include <iostream>
class drawArea : public QWidget
{
    Q_OBJECT
public:
    explicit drawArea(QWidget *parent = 0);

    double sx, sy, fx, fy;
    bool isGrid;
    QColor line_color, back_color;
    int line_style;

    double (*f)(double x);
    int fid;
    double getZero(double lb, double rb);
signals:
    void foundedPoint(double x, double y);
public slots:
    void getSettings(QColor lc, QColor bc,bool isg );
    void getfuncid(int id);

protected :
    void paintEvent(QPaintEvent* ev) override;
    void wheelEvent(QWheelEvent* ev) override;
    QPoint getp( double px, double py);

};

#endif // DRAWAREA_H
