#ifndef PROJECTSMANAGER_H
#define PROJECTSMANAGER_H

#include "model/project.h"

#include <QObject>
#include <QList>
#include <QString>

class ProjectsManager : public QObject
{
    Q_OBJECT

public:
    explicit ProjectsManager(QObject* parent = nullptr);

    const QList<Project>& projectsList() const { return m_projectsList; }
    const QList<QString>& tempProjectsList() const { return m_tempProjectsList; }

    void setProjectsList(const QString& projectsDirectoryPath);

    QByteArray calculateHash(const QString& projectFilePath);

signals:
    void projectAdded(const QString& projectName);

private:
    QList<Project> m_projectsList;
    QList<QString> m_tempProjectsList;
};

#endif // PROJECTSMANAGER_H
