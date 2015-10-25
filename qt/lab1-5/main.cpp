#include "mainwindow.h"
#include "subw.h"
#include <QApplication>
#include <QObject>
#include <QWidget>
#include <thread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //subw h;
    //h.show();
    w.show();
    //QObject::connect(&h, SIGNAL(send_pair(int_pair)), &w, SLOT(get_pair(int_pair)));
    return a.exec();
}
