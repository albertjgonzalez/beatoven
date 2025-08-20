#include "mainwindow.h"
#include "appcontroller.h"

#include <QApplication>
#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("BeatOven");
    QCoreApplication::setApplicationName("BeatOven");

    QApplication app(argc, argv);
    AppController controller(&app);

    MainWindow w;
    w.setWindowTitle("BeatOven");
    w.show();

    QTimer::singleShot(0,&controller, &AppController::startup);
    QObject::connect(&app, &QCoreApplication::aboutToQuit,
                    &controller, &AppController::shutdown);

    return app.exec();
}
