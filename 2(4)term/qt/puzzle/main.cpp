#include "mainboard.h"
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QSlider>
#include "control.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainBoard w;
    w.show();
    return a.exec();
}
