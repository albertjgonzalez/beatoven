#include "appsettings.h"
#include <QStandardPaths>

#include <algorithm>

#include <QDebug>

AppSettings::AppSettings()
    : m_settings()
{
    m_projectsFolder = m_settings.value(QStringLiteral("projects/folder")).toString();
}

QString AppSettings::projectsFolder() const
{
    return m_projectsFolder;
}

void AppSettings::setProjectsFolder(const QString& path)
{
    m_settings.setValue(QStringLiteral("projects/folder"), path);
    m_projectsFolder = m_settings.value(QStringLiteral("projects/folder")).toString();
}

void AppSettings::checkNeedsSetup()
{
    //logic to check all settings are valid
    const QStringList keys = m_settings.allKeys();

    if(keys.isEmpty()) qDebug() << "Settings File is Blank";

    std::for_each(keys.begin(), keys.end(),[](const QString &key){
        if(key.isEmpty()) qDebug() << "Missing Settings: " << key;
    });

    emit needsSetup();
}
