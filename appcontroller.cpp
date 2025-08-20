#include "appcontroller.h"
#include "appsettings.h"
#include "folderscanner.h"
#include <QDebug>

AppController::AppController(QObject* parent): QObject(parent) {}
AppController::~AppController() = default;

void AppController::startup() {
    qDebug() << "starting up bb";
    AppSettings settings;
    const QString path = settings.projectsFolder();
    qInfo() << "Testing scanFolder on:" <<path;

    FolderScanner scanner;
    const QStringList folders = scanner.scanFolder(path);
    qInfo() << "Found" << folders.size() << " folders";
}

void AppController::shutdown() {
    qDebug() << "shuting down bb";
}
