#include "projectQt.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ProjectQt w;
    w.show();

    return a.exec();
}
