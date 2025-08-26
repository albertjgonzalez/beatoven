#include "appsettings.h"
#include <QStandardPaths>

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
    emit needsSetup();
}
