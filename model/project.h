#ifndef PROJECT_H
#define PROJECT_H

#include "collaborator.h"
#include "snapshot.h"

#include <QString>
#include <QDir>
#include <QList>

class Project
{
private:
    QString m_name;
    QDir m_path;
    QList<Collaborator> m_collaborators;
    QString m_owner;
    QString m_mainHash;
    QString m_status;
    QList<Snapshot> m_snapshots;

public:
    Project();
    
    QString name() const;
    void setName(const QString& name);

    QDir path() const;
    void setPath(const QDir& path);

    QList<Collaborator> collaborators() const;
    void addCollaborator(const Collaborator& collaborator);
    void setCollaborators(const QList<Collaborator>& collaborators);

    QString owner() const;
    void setOwner(const QString& owner);

    QString mainHash()const;
    void setMainHash(const QString& mainHash);

    QString status() const;
    void setStatus(const QString& status);

    QList<Snapshot> snapshots() const;
    void addSnapshot(const Snapshot& snapshot);
    void setSnapshots(const QList<Snapshot>& snapshots);
};

#endif //PROJECT_H