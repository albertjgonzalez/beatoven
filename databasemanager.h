#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "model/project.h"

#include <QList>
#include <QSqlDatabase>

class DatabaseManager
{
public:
    DatabaseManager(const QString& dbFilePath);
    void createNewDb();
    void setupNewDb();

    void setProjects(const QList<Project>& projects);
    void addProject(const Project& project);

    bool projectExists(const QString& projectName);
    bool projectLatest(const QString& projectName, QByteArray projecthHash);

    QByteArray getStoredHash(const QString& projectName);
    void updateProject(const Project& project);

private:
    QSqlDatabase m_db;
    QString m_dbPath;
};

#endif // DATABASEMANAGER_H
