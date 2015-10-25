#ifndef MAINW_H
#define MAINW_H

#include <QMainWindow>
#include "drawarea.h"
#include "setter.h"
#include <QSettings>
namespace Ui {
class Mainw;
}

class Mainw : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mainw(QWidget *parent = 0);
    drawArea*  dr;
    setter* setting;
    ~Mainw();
protected :
   void closeEvent(QCloseEvent *ev) ;
private:
    Ui::Mainw *ui;
};

#endif // MAINW_H
