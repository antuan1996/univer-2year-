#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    Ui::MainWindow *ui;
signals :
    void sendInt(int t);
private slots:
    void on_toolButton_clicked();
    void on_toolButton_2_clicked();
};

#endif // MAINWINDOW_H
