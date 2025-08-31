#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settingsdialog.h"

#include <QDebug>
#include <QStandardPaths>
#include <QGridLayout>
#include <QLabel>
#include <QFrame>
#include <QFile>

MainWindow::MainWindow(AppSettings* settings, ProjectsManager* projectManager, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_settings(settings)
    , m_projectManager(projectManager)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showSettingsDialog()
{
    SettingsDialog dialog(m_settings, this);
    dialog.exec();
}

void MainWindow::displayProjectIcons()
{
    QWidget* projectsContainer = ui->projectsContainer;

    QGridLayout* grid = qobject_cast<QGridLayout*>(projectsContainer->layout());
    if (!grid) {
        grid = new QGridLayout(projectsContainer);
        projectsContainer->setLayout(grid);
    }


    /*
    qDeleteAll(grid->children());

    QLayoutItem* item;
    while ((item = grid->takeAt(0)) != nullptr) {
        delete item;
    }
    */

    int row = 0, col = 0;
    const int maxCols = 3;
    for (const auto& project : m_projectManager->tempProjectsList()) {

        //
        //
        //                                        This is where I am creating the project folder widget, please make seperate ui element
        //
        //  grrrrr  333 <3 ;Z) brrrr ;0 xD

        QFrame* folder = new QFrame(projectsContainer);
        folder->setFixedSize(69, 69);
        folder->setStyleSheet("border-image: url(:/images/ProjectCube.png) 0 0 0 0 stretch stretch;");

        //QLabel* label = new QLabel(project, folder);
        QVBoxLayout* layout = new QVBoxLayout(folder);
        layout->setAlignment(Qt::AlignCenter);
        //layout->addWidget(label);
        //folder->setLayout(layout);

        grid->addWidget(folder, row, col);

        col++;
        if (col >= maxCols) {
            col = 0;
            row++;
        }
    }
}
