#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QString>
#include <QSettings>

class AppSettings : public QObject {
        Q_OBJECT
private:
    QSettings m_settings;
    QString m_projectsFolder;
    
public:
    AppSettings();
    void checkNeedsSetup();

    QString projectsFolder() const;
    void setProjectsFolder(const QString& path);

signals:
    void needsSetup();

};

#endif // APPSETTINGS_H
