#include "collaborator.h"


Collaborator::Collaborator()
{

}

QString Collaborator::userName() const
{
    return m_userName;
}

void Collaborator::setUserName(const QString& userName)
{
    m_userName = userName;
}

bool Collaborator::online() const
{
    return m_online;
}

void Collaborator::setOnline(bool online)
{
    m_online = online;
}