#include "folderscanner.h"
#include <QDir>
#include <QDebug>

FolderScanner::FolderScanner()
{

}

FolderScanner::~FolderScanner()
{

}

QStringList FolderScanner::scanFolder(const QString& path)
{
    QDir dir(path);
    if (!dir.exists()) {
        qWarning() << "Directory does not exist:" << path;
        return {};
    }

    QStringList folderList = dir.entryList(
        QDir::Dirs | QDir::NoDotAndDotDot,
        QDir::Name);

    for (const auto& name : std::as_const(folderList)) {
        qDebug().noquote() <<"Found Folder:" << name;
    }

    return folderList;
}
