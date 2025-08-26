#include "mainwindow.h"
#include "appcontroller.h"
#include "appsettings.h"

#include <QApplication>
#include <QCoreApplication>
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("BeatOven");
    QCoreApplication::setApplicationName("BeatOven");

    QApplication app(argc, argv);

    AppSettings* settings = new AppSettings();

    MainWindow w;
    w.setWindowTitle("BeatOven");

    QObject::connect(settings, &AppSettings::needsSetup, &w, &MainWindow::showSettingsDialog);
    settings->checkNeedsSetup();


    AppController controller(&app);


    QTimer::singleShot(0,&controller, &AppController::startup);
    QObject::connect(&app, &QCoreApplication::aboutToQuit,
                    &controller, &AppController::shutdown);

    w.show();
    return app.exec();
}
