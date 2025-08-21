#include "appsettings.h"
#include <QStandardPaths>

AppSettings::AppSettings()
    : m_settings()
{

}

QString AppSettings::projectsFolder() const
{
    return m_settings.value(QStringLiteral("projects/folder")S).toString();
}

void AppSettings::setProjectsFolder(const QString& path)
{
    m_settings.setValue(QStringLiteral("projects/folder"), path);
}
