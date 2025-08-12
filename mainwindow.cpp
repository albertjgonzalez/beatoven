#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <QStandardPaths>
#include "appsettings.h"
#include "folderscanner.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    {
        AppSettings settings;
        const QString path = settings.projectsFolder();
        qInfo() << "Testing scanFolder on:" <<path;

        FolderScanner scanner;
        const QStringList folders = scanner.scanFolder(path);
        qInfo() << "Found" << folders.size() << " folders";

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
