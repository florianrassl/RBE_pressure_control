#include "rbemainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //set main stylesheet
    QFile styleFile( ":/stylesheet.qss" );
    styleFile.open( QFile::ReadOnly );
    QString style( styleFile.readAll() );
    a.setStyleSheet( style );

    rbeMainWindow w;
    w.show();

    return a.exec();
}
