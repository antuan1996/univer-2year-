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
class Control;
class MainBoard : public QWidget
{
    Q_OBJECT

public:
    explicit MainBoard(QWidget *parent = 0);
    void delete_puzzle();

    ~MainBoard();
    void load_puzzle();
    void show_settings();
signals:
    void click_event(QPoint pos);
    void move_event(QPoint pos);
    void release_event();
    void status_changed( QString str );
public slots:
    void create_puzzle(Control *set);
    void puzzle_finished(  );
    void settings_changed( bool a, bool b, bool c);
    void puzzle_start();
protected :
    PModel* puzzle;
    PView* view;
    Control* ctrl;
    bool is_pressed;
    void mouseMoveEvent(QMouseEvent* ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);
    void paintEvent(QPaintEvent* ev);
};

#endif // MAINBOARD_H
