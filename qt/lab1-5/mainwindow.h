#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "subw.h"
#include "str.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots :
    void get_pair(int_pair s);
    void get_num();
private:
    Ui::MainWindow *ui;
    subw *h;

};

#endif // MAINWINDOW_H
