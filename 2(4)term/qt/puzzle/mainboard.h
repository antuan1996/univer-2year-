#ifndef MAINBOARD_H
#define MAINBOARD_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QDesktopWidget>
#include <QApplication>
class PModel;
class PView;
class Settings;
class MainBoard : public QWidget
{
    Q_OBJECT

public:
    explicit MainBoard(QWidget *parent = 0);
    bool create_puzzle(Settings* set );

    ~MainBoard();
signals:
    void click_event(QPoint pos);
    void move_event(QPoint pos);
    void release_event();

protected :
    PModel* puzzle;
    PView* view;
    Settings* info;
    bool is_pressed;
    void mouseMoveEvent(QMouseEvent* ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent* ev);
};

#endif // MAINBOARD_H
