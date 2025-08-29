#include "projectsmanager.h"

#include <QDir>
#include <QDebug>

ProjectsManager::ProjectsManager(QObject* parent)
    : QObject(parent)
{
}

void ProjectsManager::addProject(const QString& projectLocation)
{
    QDir dir(projectLocation);
    auto files = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    for (const auto& file : files) {
        qDebug() << "Adding project " << file << " to Projects List";
        m_tempProjectsList.append(file);
        emit projectAdded(file);
    }
}
