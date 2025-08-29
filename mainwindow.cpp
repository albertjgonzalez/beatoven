#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "settingsdialog.h"

#include <QDebug>
#include <QStandardPaths>
#include <QGridLayout>
#include <QLabel>

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
    QWidget* content = ui->scrollAreaWidgetContents_2; // content widget of scroll area
    if (!content) return;

    // If it doesn't have a layout yet, create a grid layout
    QGridLayout* grid = qobject_cast<QGridLayout*>(content->layout());
    if (!grid) {
        grid = new QGridLayout(content);
        content->setLayout(grid);
    }

    // clear old widgets
    QLayoutItem* item;
    while ((item = grid->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    int row = 0, col = 0;
    const int maxCols = 3;
    for (const auto& project : m_projectManager->tempProjectsList()) {
        QLabel* label = new QLabel(project, content); // parent = content widget
        grid->addWidget(label, row, col);

        col++;
        if (col >= maxCols) {
            col = 0;
            row++;
        }
    }
}
