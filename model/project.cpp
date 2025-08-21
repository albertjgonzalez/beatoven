#include "project.h"

Project::Project(){ }

QString Project::name() const
{
    return m_name;
}

void Project::setName(const QString& name)
{
    m_name = name;
}

QDir Project::path() const
{
    return m_path;
}

void Project::setPath(const QDir& path)
{
    m_path = path;
}

QList<Collaborator> Project::collaborators() const
{
    return m_collaborators;
}

void Project::addCollaborator(const Collaborator& collaborator)
{
    m_collaborators.append(collaborator);
}

void Project::setCollaborators(const QList<Collaborator>& collaborators)
{
    m_collaborators = collaborators;
}

QString Project::owner() const
{
    return m_owner;
}

void Project::setOwner(const QString& owner)
{
    m_owner = owner;
}

QString Project::mainHash() const
{
    return m_mainHash;
}

void Project::setMainHash(const QString& mainHash)
{
    m_mainHash = mainHash;
}

QString Project::status() const
{
    return m_status;
}

void Project::setStatus(const QString& status)
{
    m_status = status;
}

QList<Snapshot> Project::snapshots() const
{
    return m_snapshots;
}

void Project::addSnapshot(const Snapshot& snapshot)
{
    m_snapshots.append(snapshot);
}

void Project::setSnapshots(const QList<Snapshot>& snapshots)
{
    m_snapshots = snapshots;
}