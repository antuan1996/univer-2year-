#ifndef BOARD_H
#define BOARD_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPixmap>
#include <QPen>
#include <iostream>
class board : public QWidget
{
    Q_OBJECT
public:
    explicit board(QWidget *parent = 0);

signals:
protected:
    void mouseMoveEvent(QMouseEvent *ev) override;
    void mousePressEvent(QMouseEvent *) override;
    void mouseReleaseEvent(QMouseEvent *) override;
    void paintEvent(QPaintEvent *);
public slots:
    void setTool(int t);
private :
    bool isDown;
    QPoint prevp;
    QPixmap* pixm;
    QColor mycolour;
    int mywidth;
};

#endif // BOARD_H
