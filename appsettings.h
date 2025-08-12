#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QSettings>

class AppSettings {
public:
    AppSettings();
    QString projectsFolder() const;
    void setProjectsFolder(const QString& path);

private:
    QSettings m_settings;
};

#endif // APPSETTINGS_H
