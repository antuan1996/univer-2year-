#ifndef STARTWINDOW_H
#define STARTWINDOW_H

#include <QMainWindow>
#include <QPixmap>
namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

private slots:
    void on_actionPuzzles_triggered();

    void on_action_triggered();

    void on_action_2_triggered();

private:
    Ui::StartWindow *ui;
};

#endif // STARTWINDOW_H
