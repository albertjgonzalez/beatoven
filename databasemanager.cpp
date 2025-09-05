#include "databasemanager.h"

#include <QFileInfo>
#include <QDebug>

DatabaseManager::DatabaseManager(const QString& dbLocation) {

    if(QFileInfo::exists(dbLocation)) qDebug() << "Could not find DB";

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(dbLocation);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}
