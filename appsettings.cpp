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
    //need to fix this,
    const QStringList settingsList = m_settings.allKeys();
    QStringList missingSettingsList;

    if(settingsList.isEmpty()) {
        qDebug() << "Settings File is Blank";
        emit needsSetup();
    }

    std::for_each(settingsList.begin(), settingsList.end(),[this, &missingSettingsList](const QString &key){
        if(!key.isEmpty()){
            qDebug() << "Current Settings: " << key << " = " << m_settings.value(key).toString();
        }
        else {
        missingSettingsList.append(key);
        qDebug() << "Missing Settings: " << key << " = " << m_settings.value(key).toString();
        }
    });

    if(!missingSettingsList.isEmpty()) {
        emit needsSetup();
    }
}
