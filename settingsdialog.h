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

    AppSettings* m_settings;

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
