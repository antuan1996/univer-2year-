#include "mainwindow.h"
#include <QApplication>
#include <board.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //board b;
    //b.show();
    return a.exec();
}
