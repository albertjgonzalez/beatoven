#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager
{
public:
    DatabaseManager(const QString& dbLocation);

private:
    QSqlDatabase m_db;
};

#endif // DATABASEMANAGER_H
