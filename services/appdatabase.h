#ifndef APPDATABASE_H
#define APPDATABASE_H

#include "./model/collaborator.h"
#include "./model/project.h"

#include <QSqlDatabase>
#include <QString>
#include <QList>

class AppDatabase
{
private:
    QString m_connectionString;

public:
    AppDatabase();
    bool open(const QString connectionString);
    bool exists();
    void setupDb();
    void close();

    QList<Collaborator> getCollaborators(int projectId);
    void addCollaborator(const Collaborator& c, int projectId);

    void addProject(const Project& p);

};


#endif // APPDATABASE_H
