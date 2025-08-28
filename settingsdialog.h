#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "appsettings.h"

#include <QDialog>

namespace Ui {
class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(AppSettings* settings, QWidget *parent = nullptr);
    ~SettingsDialog();



private slots:
    void browseForFolder();
    void saveSettings();

private:
    Ui::SettingsDialog *ui;
    AppSettings* m_settings;


};

#endif // SETTINGSDIALOG_H
