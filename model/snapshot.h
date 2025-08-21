#ifndef SNAPSHOT_H
#define SNAPSHOT_H

#include <QString>
#include <QDateTime>

class Snapshot
{
private:
    QDateTime m_timeStamp;
    QString m_hash;
    QString m_path;

public:
    Snapshot();

    QDateTime timeStamp() const;
    void setTimeStamp(const QDateTime& timeStamp);

    QString hash() const;
    void setHash(const QString& hash);

    QString path() const;
    void setPath(const QString& path);

};

#endif //SNAPSHOT_H