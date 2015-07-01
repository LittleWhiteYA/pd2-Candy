#include "game.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game w;
    w.show();
    w.Check_Candy();

    return a.exec();
}
