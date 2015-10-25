#include "mainwindow.h"
#include <QApplication>
#include "screensaver.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    screensaver h;
    h.setWindowFlags(Qt::CustomizeWindowHint);
    h.show();
    return a.exec();
}
