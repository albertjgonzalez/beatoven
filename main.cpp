#include "mainwindow.h"
#include "appcontroller.h"
#include "appsettings.h"
#include "projectsmanager.h"

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


    AppSettings* settings = new AppSettings();
    QObject::connect(settings, &AppSettings::needsSetup, [&w, settings]() {
        w.showSettingsDialog(settings);
    });
    settings->checkNeedsSetup();

    ProjectsManager projectManager;
    projectManager.addProject(settings->projectsFolder());

    //next I need to load all the projects


    //QTimer::singleShot(0,&controller, &AppController::startup);         Might not need a controller, DOTS!!
    //QObject::connect(&app, &QCoreApplication::aboutToQuit,
    //                &controller, &AppController::shutdown);

    w.show();
    return app.exec();
}
