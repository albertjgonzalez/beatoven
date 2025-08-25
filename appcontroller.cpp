#include "appcontroller.h"
#include "appsettings.h"
#include "services/folderscanner.h"

#include <QStandardPaths>
#include <QFileInfo>
#include <QDebug>
#include <QDir>

AppController::AppController(QObject* parent): QObject(parent) {}
AppController::~AppController() = default;

void AppController::startup() {
    qDebug() << "starting up bb";

    AppSettings settings;
    QString path = QDir::toNativeSeparators(QFileInfo(settings.projectsFolder()).absoluteFilePath());
    //QString path = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

    if(path.isEmpty())
    {
        qInfo() << "No Path Found.";
        state_ = ConfigState::NeedsSetup;
        return;
    }
    QFileInfo fi(path);

    if(!fi.isAbsolute() || !fi.exists() || !fi.isDir())
    {
       qInfo() << "Path is invalid.";
        state_ = ConfigState::NeedsSetup;
       return;
    }
    else if(!fi.isWritable())//if any issues, try to create a tiny test file?
    {
        qInfo() << "Location is unwritable.";
        state_ = AppController::ConfigState::NeedsSetup;
        return;
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
