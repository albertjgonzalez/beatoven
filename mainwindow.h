#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "appsettings.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void showSettingsDialog(AppSettings* settings);

private:
    Ui::MainWindow *ui;
    AppSettings* m_settings;
};
#endif // MAINWINDOW_H
