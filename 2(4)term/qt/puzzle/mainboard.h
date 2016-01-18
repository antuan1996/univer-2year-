#ifndef MAINBOARD_H
#define MAINBOARD_H

#include <QMainWindow>

namespace Ui {
class MainBoard;
}

class MainBoard : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainBoard(QWidget *parent = 0);
    ~MainBoard();

private:
    Ui::MainBoard *ui;
};

#endif // MAINBOARD_H
