#include "settingsdialog.h"
#include "ui_settingsdialog.h"

#include <QFileDialog>
#include <QMessageBox>

SettingsDialog::SettingsDialog(AppSettings* settings, QWidget *parent) :
    m_settings(settings),
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);

    ui->folderLineEdit->setText(m_settings->projectsFolder());


    connect(ui->browseButton, &QPushButton::clicked, this, &SettingsDialog::browseForFolder);
    connect(ui->saveButton, &QPushButton::clicked, this, &SettingsDialog::saveSettings);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::browseForFolder()
{
    QString folder = QFileDialog::getExistingDirectory(this, "Select Projects Folder");
    if(!folder.isEmpty()) {
        ui->folderLineEdit->setText(folder);
    }

}
void SettingsDialog::saveSettings()
{
    QString folder = ui->folderLineEdit->text().trimmed();
    if(folder.isEmpty()) {
        QMessageBox::warning(this, "Invalid Folder", "Please select a valid folder");
        return;
    }

    m_settings->setProjectsFolder(folder);
    accept();
}
