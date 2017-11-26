#include "rungekutta.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    RungeKutta w;
    w.show();

    return a.exec();
}
