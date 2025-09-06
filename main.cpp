#include "mainwindow.h"
#include "databasemanager.h"
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

    //AppController controller(&app);
    AppSettings* settings = new AppSettings(&app);
    ProjectsManager* projectManager = new ProjectsManager(&app);

    MainWindow w(settings, projectManager);
    w.setWindowTitle("BeatOven");

    QObject::connect(settings, &AppSettings::needsSetup, &w, [&w]() {
        w.showSettingsDialog();
    });
    settings->checkNeedsSetup();

    projectManager->runProjectsListSetup(settings->projectsFolder());

    w.displayProjectIcons();



    //next I need to display all projects from settings tempProjectsList


    //QTimer::singleShot(0,&controller, &AppController::startup);         Might not need a controller, DOTS!!
    //QObject::connect(&app, &QCoreApplication::aboutToQuit,
    //                &controller, &AppController::shutdown);

    w.show();
    return app.exec();
}
