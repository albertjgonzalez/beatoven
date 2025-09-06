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
            qDebug() << file << " has Ableton file:" << alsFile;

            QByteArray projectHash = calculateHash(alsFile);
            if(dbManager.projectExists(alsFile)) {
                QByteArray storedHash = dbManager.getStoredHash(alsFile);
                if(projectHash == storedHash) {
                    qDebug() << "Hashes Match";
                }
            }

            currentProject.setName(alsFile);
            currentProject.setHash(projectHash);
            m_projectsList.append(currentProject);

            dbManager.addProject(currentProject);
        }
        dir.cdUp();

        qDebug() << "Adding project " << file << " to Projects List";

        m_tempProjectsList.append(file);
        emit projectAdded(file);
    }
}

QByteArray ProjectsManager::calculateHash(const QString& filePath) {
    QCryptographicHash projectHasher(QCryptographicHash::Md4);
    QFile f(filePath);

    //if (!f.open(QIODevice::ReadOnly | QIODevice::Text)) {
    //    qDebug() << "Error: Could not calculate hash -- File open: " << filePath;
    //    return 0;
    //}

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

