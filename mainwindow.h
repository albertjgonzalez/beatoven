#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "appsettings.h"
#include "projectsmanager.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    AppSettings* m_settings;
    ProjectsManager* m_projectManager;

public:
    MainWindow(AppSettings* settings, ProjectsManager* projectManager, QWidget *parent = nullptr);
    ~MainWindow();



    void showSettingsDialog();
    void displayProjectIcons();

};
#endif // MAINWINDOW_H
