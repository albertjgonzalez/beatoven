#include "appcontroller.h"
#include "services/folderscanner.h"

#include <QStandardPaths>
#include <QFileInfo>
#include <QDebug>
#include <QDir>

AppController::AppController(QObject* parent): QObject(parent) {}
AppController::~AppController() = default;

void AppController::startup() {
    qDebug() << "starting up bb";


}

void AppController::shutdown() {
    qDebug() << "shuting down bb";
}
