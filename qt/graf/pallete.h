#ifndef PALLETE_H
#define PALLETE_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
class pallete : public QWidget
{
    Q_OBJECT
public:
    explicit pallete(QWidget *parent = 0);

signals:
    void colorClicked(QColor col);
public slots:
    void setRval(int r);
protected :
    void paintEvent(QPaintEvent *) override;
    void mousePressEvent(QMouseEvent *) override;
private:
    int r_base;
};

#endif // PALLETE_H
