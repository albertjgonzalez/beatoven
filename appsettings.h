#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QSettings>

class AppSettings {
private:
    QSettings m_settings;
    QString m_projectDirectory;
    QString m_dbPath;
    
public:
    AppSettings();
    QString projectsFolder() const;
    void setProjectsFolder(const QString& path);

};

#endif // APPSETTINGS_H
