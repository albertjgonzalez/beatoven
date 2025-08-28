#include "projectsmanager.h"

#include <QDir>
#include <QDebug>

ProjectsManager::ProjectsManager() {}

void ProjectsManager::addProject(QString projectLocation) {
    QDir dir(projectLocation);
    auto files = dir.entryList();
    for (auto file : files) {
        qDebug() << "Adding project " << file << " to Projects List";
        tempProjectsList.append(file);
    }

}

