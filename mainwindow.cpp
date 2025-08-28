#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settingsdialog.h"

#include <QDebug>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showSettingsDialog(AppSettings* settings)
{
    SettingsDialog dialog(settings, this);
    dialog.exec();
}
