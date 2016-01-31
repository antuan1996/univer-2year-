#include "mainboard.h"
#include <QApplication>
#include "settings.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Settings input( "neon.jpg" );
    MainBoard w;
    w.create_puzzle( &input );
    w.show();
    return a.exec();
}
