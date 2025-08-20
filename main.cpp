#include "mainwindow.h"
#include "AppController.h"
#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("BeatOven");
    QCoreApplication::setApplicationName("BeatOven");

    MainWindow w;
    w.setWindowTitle("BeatOven");
    w.show();



    return a.exec();
}
