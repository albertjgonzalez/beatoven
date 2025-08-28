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
    //need to fix this
    const QStringList keys = m_settings.allKeys();
    QStringList missingSettings;

    if(keys.isEmpty()) {
        qDebug() << "Settings File is Blank";
        emit needsSetup();
    }

    std::for_each(keys.begin(), keys.end(),[this, &missingSettings](const QString &key){
        if(!key.isEmpty()){
            qDebug() << "Current Settings: " << key;
        }
        else {
        missingSettings.append(key);
        qDebug() << "Missing Settings: " << key;
        }
    });

    if(!missingSettings.isEmpty()) {
        emit needsSetup();
    }
}
