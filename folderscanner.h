#ifndef FOLDERSCANNER_H
#define FOLDERSCANNER_H

#include <QString>
#include <QStringList>

class FolderScanner
{
public:
    FolderScanner();
    ~FolderScanner();

    QStringList scanFolder(const QString& path);
};

#endif // FOLDERSCANNER_H
