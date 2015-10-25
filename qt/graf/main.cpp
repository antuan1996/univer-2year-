#include "mainw.h"
#include <QApplication>
#include "drawarea.h"
#include "setter.h"
#include "pallete.h"
int main(int argc, char *argv[])
{
    system("pwd");
    QApplication a(argc, argv);
    Mainw w;
    w.show();
    //setter s;
    //s.show();
    return a.exec();
}
