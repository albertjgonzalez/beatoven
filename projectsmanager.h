//this class will be used to manage the projects

//has a container that holds a list of all the projects
//loads list from appsettings class
//
//mainwindow will use this list to display projects FIRST, hash checks in background
//
//will create hash of each project
//check this list againt database to detect updates
//
//mainwindow will use this list to display projects and mark those that are out of sync
//notify user to update. will let them go project by project or update all for funsies
#ifndef PROJECTSMANAGER_H
#define PROJECTSMANAGER_H

#include "model/project.h"

#include <QList>
#include <QString>

class ProjectsManager
{
private:
    QList<QString> tempProjectsList;
    QList<Project> _projectsList;

public:
    ProjectsManager();

    Project& projectsList();
    void addProject(QString projectLocation);

};

#endif // PROJECTSMANAGER_H
