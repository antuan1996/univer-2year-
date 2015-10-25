#ifndef SCREENSAVER_H
#define SCREENSAVER_H

#include <QWidget>

namespace Ui {
class screensaver;
}

class screensaver : public QWidget
{
    Q_OBJECT

public:
    int id;
    explicit screensaver(QWidget *parent = 0);
    ~screensaver();

    void timerEvent(QTimerEvent *ev);
private:
    Ui::screensaver *ui;

};

#endif // SCREENSAVER_H
