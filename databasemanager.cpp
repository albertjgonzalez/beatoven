#include "databasemanager.h"

#include <QString>
#include <QFileInfo>
#include <QDebug>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>

DatabaseManager::DatabaseManager(const QString& dbFilePath) {

    m_dbPath = dbFilePath;
    bool newDb = false;

    if(!QFileInfo::exists(dbFilePath+"/beatoven-projects.db")) {
        qDebug() << "Could not find DB, creating now.";
        newDb = true;
    }

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbFilePath+"/beatoven-projects.db");

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
        if (newDb) setupNewDb();
    }
}

void DatabaseManager::setProjects(const QList<Project>& projects) {
    for(const Project& p: projects) {
        qDebug() << "From db------" << p.name();
    }
}

void DatabaseManager::setupNewDb() {
    QSqlQuery query;
    query.exec("CREATE TABLE project (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, location TEXT NOT NULL, hash TEXT NOT NULL);");
}


bool DatabaseManager::projectExists(const QString& projectName) {
    QSqlQuery query;
    query.exec("SELECT * FROM project WHERE name = \"" + projectName + "\";" );
    return query.next();
}

QByteArray DatabaseManager::getStoredHash(const QString& projectName) {
    QSqlQuery query;
    query.exec("SELECT hash FROM project WHERE name = \"" + projectName + "\";" );
    query.next();
    qDebug() << query.value(0);
    return 0;
}

void DatabaseManager::updateProject(const Project& project) {

}

void DatabaseManager::addProject(const Project& project) {
    QSqlQuery query;
    query.exec("INSERT INTO project(name, location, hash) VALUES (?,?,?)" );
    query.addBindValue(project.name());
    query.addBindValue(project.path().absolutePath());
    query.addBindValue(project.hash().toHex());
    if(!query.exec()) {
        qDebug() << "SQL no worky stupit" << query.lastError();
    }
}
