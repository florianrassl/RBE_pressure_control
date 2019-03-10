#include "rbemainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    rbeMainWindow w;
    w.show();

    return a.exec();
}
