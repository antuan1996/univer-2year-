#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <iostream>
#include <vector>
#include "dialog.h"
#include <QMenu>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QAction* fillAct;
    QAction* closeAct;
    QAction* searchAct;
    QAction* deleteAct;
    QAction* createAct;
    Ui::MainWindow *ui;
    QMenu* sub_menu;
    int rnum;
    int cnum;
    int mod;
    std::vector< int > data;
    void update_matrix();
private slots:
    void fill_matrix();
    void find_max();
    void delete_row();
    void create_mat();
    void create_new(int w, int h);
    void show_menu(QPoint);
};

#endif // MAINWINDOW_H
