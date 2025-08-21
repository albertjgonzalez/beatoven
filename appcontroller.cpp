#include "appcontroller.h"
#include "appsettings.h"
#include "services/folderscanner.h"

#include <QFileInfo>
#include <QDebug>

AppController::AppController(QObject* parent): QObject(parent) {}
AppController::~AppController() = default;

void AppController::startup() {
    qDebug() << "starting up bb";

    AppSettings settings;
    QString path = settings.projectsFolder();
    QFileInfo fi(path);

    if(path.isEmpty())
    {
        qInfo() << "No Path Found.";
        state_ = AppController::ConfigState::NeedsSetup;
    }
    else if(!fi.isAbsolute() || !fi.exists() || !fi.isDir())
    {
       qInfo() << "Path is invalid.";
        state_ = AppController::ConfigState::NeedsSetup;
    }
    else if(!fi.isWritable())
    {
        qInfo() << "Location is unwritable.";
        state_ = AppController::ConfigState::NeedsSetup;
    }
    else
    {
        state_ = AppController::ConfigState::ReadyWithRoot;
        qInfo() << "Testing scanFolder on:" << path;

        FolderScanner scanner;
        const QStringList folders = scanner.scanFolder(path);
        qInfo() << "Found" << folders.size() << " folders";
    }
}

void AppController::shutdown() {
    qDebug() << "shuting down bb";
}
