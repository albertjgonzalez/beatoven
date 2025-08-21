#ifndef COLLABORATOR_H
#define COLLABORATOR_H

#include <QString>

class Collaborator
{
private:
    QString m_userName;
    bool m_online;

public:
    Collaborator();

    QString userName() const;
    void setUserName(const QString& name);

    bool online() const;
    void setOnline(bool online);
};

#endif // COLLABORATOR_H