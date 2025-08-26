#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::onNeedsSetup()
{
    qInfo() << "Running Setup";
}

MainWindow::~MainWindow()
{
    delete ui;
}
