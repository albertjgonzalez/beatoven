#include "projectsmanager.h"

#include <QDir>
#include <QDebug>
#include <QCryptographicHash>

ProjectsManager::ProjectsManager(QObject* parent)
    : QObject(parent)
{
}

void ProjectsManager::setProjectsList(const QString& projectsDirectoryPath)
{
    QCryptographicHash projectHasher(QCryptographicHash::Md4);
    QDir dir(projectsDirectoryPath);
    auto files = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);


    //
    //
    //                             This is where we look at projects folder, create hashes, and check for updates. Please split these responsibilities.
    //
    //

    for (const auto& file : files) {

        auto tPath = projectsDirectoryPath + "/" + file;
        dir.cd(tPath);
        auto alsFiles = dir.entryList(QStringList() << "*.als", QDir::Files);

        for (const auto& alsFile : alsFiles) {

            QString fullPath = dir.absoluteFilePath(alsFile);
            qDebug() << file << " has Ableton file:" << fullPath;
            QFile f(fullPath);
            if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
                return;

             int lineNumber = 1;
             while (!f.atEnd()) {
                 QByteArray line = f.readLine();
                 projectHasher.addData(line);
                // qDebug() << "Line number " << lineNumber << " : " << line;
            }
             auto result = projectHasher.result();
            qDebug() << "The Hash is " << result;
        }
        dir.cdUp();
        qDebug() << "Adding project " << file << " to Projects List";
        m_tempProjectsList.append(file);
        emit projectAdded(file);
    }
}
