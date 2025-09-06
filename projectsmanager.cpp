#include "projectsmanager.h"
#include "databasemanager.h"

#include <QDir>
#include <QDebug>
#include <QCryptographicHash>

ProjectsManager::ProjectsManager(QObject* parent)
    : QObject(parent)
{
}

void ProjectsManager::runProjectsListSetup(const QString& projectsDirectoryPath)
{
    QDir dir(projectsDirectoryPath);
    auto files = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

    DatabaseManager dbManager(projectsDirectoryPath);

    for (const auto& file : files) {

        Project currentProject;
        auto tPath = projectsDirectoryPath + "/" + file;
        dir.cd(tPath);
        auto alsFiles = dir.entryList(QStringList() << "*.als", QDir::Files);

        for (const auto& alsFile : alsFiles) {

            QString fullPath = dir.absoluteFilePath(alsFile);
            QByteArray projectHash = calculateHash(fullPath);

            currentProject.setName(alsFile);
            currentProject.setHash(projectHash);
            m_projectsList.append(currentProject);


            if(dbManager.projectExists(alsFile)) {
                QByteArray storedHash = dbManager.getStoredHash(alsFile);
                if(projectHash != storedHash) dbManager.updateProject(currentProject);
            }
            else {
                qDebug() << "Adding project " << currentProject.name() << " to Projects List";
                dbManager.addProject(currentProject);
            }
        }

        dbManager.checkCollaboratorUpdates(currentProject);//----------------------------------Next step is check hash against any one who is a collaborator
        m_projectsList.append(currentProject);
        m_tempProjectsList.append(currentProject.name());
        dir.cdUp();
        emit projectAdded(file);
    }
}

QByteArray ProjectsManager::calculateHash(const QString& filePath) {
    QCryptographicHash projectHasher(QCryptographicHash::Md4);
    QFile f(filePath);

    if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Error: Could not calculate hash -- File open: " << filePath;
        return 0;
    }

    int lineNumber = 1;
    while (!f.atEnd()) {
        QByteArray line = f.readLine();
        projectHasher.addData(line);
        // qDebug() << "Line number " << lineNumber << " : " << line;
    }
    auto result = projectHasher.result();
    qDebug() << "The Hash is " << result;

    return result;
}

