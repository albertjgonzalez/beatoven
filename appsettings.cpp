#include "appsettings.h"
#include <QStandardPaths>

AppSettings::AppSettings()
    : m_settings()
{
}


QString AppSettings::projectsFolder() const
{
    const QString defaultPath =
        QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    return m_settings.value(QStringLiteral("projects/folder"), defaultPath).toString();
}

void AppSettings::setProjectsFolder(const QString& path)
{
    m_settings.setValue(QStringLiteral("projects/folder"), path);
}
