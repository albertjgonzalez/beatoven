#include "snapshot.h"

Snapshot::Snapshot() { }

QDateTime Snapshot::timeStamp() const
{
    return m_timeStamp;
}
void Snapshot::setTimeStamp(const QDateTime& timeStamp)
{
    m_timeStamp = timeStamp;
}

QString Snapshot::hash() const
{
    return m_hash;
}
void Snapshot::setHash(const QString& hash)
{
    m_hash = hash;
}

QString Snapshot::path() const
{
    return m_path;
}
void Snapshot::setPath(const QString& path)
{
    m_path = path;
}
