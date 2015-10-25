#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    //int posx, posy;
    QPoint p;
    bool f;
    int tim_id;
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void picture_change(void);
    void but_move(void);
    void but_sys(void);
    void but_opac(void);
private:
    Ui::Widget *ui;
    void timerEvent(QTimerEvent *ev);
};

#endif // WIDGET_H
