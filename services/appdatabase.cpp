#include "appdatabase.h"

#include <QDebug>

AppDatabase::AppDatabase()
{

    qDebug() << "starting the db class";

}

bool AppDatabase::exists()
{
    return true;
}

void AppDatabase::setupDb()
{
    qDebug() << "setting up db";
}
