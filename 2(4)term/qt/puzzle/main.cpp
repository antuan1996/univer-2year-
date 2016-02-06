#include "mainboard.h"
#include <QApplication>
#include <QString>
#include <QFileDialog>
#include <QSlider>
#include "control.h"
#include "startwindow.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartWindow w;
    w.show();
    return a.exec();
}
