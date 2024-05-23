#include "xDirectory.h"
#include "ui_xDirectory.h"

xDirectory::xDirectory(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::xDirectory)
{
    ui->setupUi(this);
}

xDirectory::~xDirectory()
{
    delete ui;

}

QString xDirectory::getPath(const bool &isValidRequested, const bool &isEmptyRequested, const QString& subject)
{
    QFileDialog folder;
    QString path;

    folder.setFileMode(QFileDialog::Directory);
    folder.setOption(QFileDialog::ShowDirsOnly);
    folder.setWindowTitle(subject);
    path = folder.getExistingDirectory(this);
    QDir directory(path);
    bool isWritable = true;
    if(isValidRequested == true)
    {
        isWritable = directory.isAbsolute();
    }
    bool isEmpty = true;
    if(isEmptyRequested == true)
    {
        isEmpty = directory.isEmpty();
    }

    if(isEmpty && isWritable)
    {
        ui->labelDatabasePath->setText(path);
        return path;
    }
    else
    {
        giveMessage(OPERATION_FAILED,
                    "Path Is Not Valid",
                    "Selected Path Is Not Valid Assign Apropriate Path");
        m_isPathValid = false;
    }
    return "";
}

void xDirectory::giveMessage(const xDirectory::xDirectoryPopupMessage &messageType,
                             const QString &title,
                             const QString &text)
{
    switch(messageType)
    {
    case xDirectoryPopupMessage::OPERATION_FAILED:
    {
        QMessageBox::critical(nullptr, title, text);

        break;
    }
    case xDirectoryPopupMessage::PATH_VALIDITY:
    {
        QMessageBox::warning(nullptr, title, text);

        break;
    }
    case xDirectoryPopupMessage::OPERATION_SUCCESED:
    {
        QMessageBox::information(nullptr, title, text);
        break;
    }
    case xDirectoryPopupMessage::SAME_PATH:
    {
        QMessageBox::information(nullptr, title, text);
        break;
    }
    }
}

QString xDirectory::getDatabasePath() const
{
    return m_databasePath;
}

QString xDirectory::getWorkingDirectoryPath() const
{
    return m_workingDirectoryPath;
}

bool xDirectory::getIsPathValid() const
{
    return m_isPathValid;
}

void xDirectory::setIsPathValid(bool isPathValid)
{
    m_isPathValid = isPathValid;
}

bool xDirectory::getHasChanged() const
{
    return m_hasChanged;
}

void xDirectory::on_pushButtonCancel_clicked()
{
    this->close();
}

void xDirectory::on_pushButtonSetWorkingPath_clicked()
{
    bool isValid = ui->checkBoxWorkingDirectoryValidity->isChecked();
    bool isEmpty = ui->checkBoxWorkingDirectoryEmpty->isChecked();
    QString path = getPath(isValid, isEmpty, "Working Directory");
    if(path != "")
    {
        ui->labelWorkingPath->setText(path);
        m_workingDirectoryPath = path;
        m_hasChanged = true;
    }
}

void xDirectory::on_pushButtonSetDatabasePath_clicked()
{
    bool isValid = ui->checkBoxDatabaseValidity->isChecked();
    bool isEmpty = ui->checkBoxDatabasePathEmpty->isChecked();
    QString path = getPath(isValid, isEmpty, "Database");
    if(path != "")
    {
        ui->labelDatabasePath->setText(path);
        m_databasePath = path;
        m_hasChanged = true;
    }
}

void xDirectory::on_pushButtonApply_clicked()
{
    m_hasChanged = true;
    if(QDir::isAbsolutePath(m_workingDirectoryPath) &&
            QDir::isAbsolutePath(m_databasePath))
    {
        m_isPathValid = true;
        giveMessage(xDirectoryPopupMessage::OPERATION_SUCCESED,
                    "Path Assigend",
                    "Path Assigned Successfully");
    }
    else
    {
        m_isPathValid = false;
        giveMessage(xDirectoryPopupMessage::OPERATION_FAILED,
                    "Path Assigend",
                    "Path Assigned Error");
    }
}

void xDirectory::on_pushButtonOK_clicked()
{
    if(QDir::isAbsolutePath(m_workingDirectoryPath) &&
            QDir::isAbsolutePath(m_databasePath))
    {
        m_isPathValid = true;
        giveMessage(xDirectoryPopupMessage::OPERATION_SUCCESED,
                    "Path Assigend",
                    "Path Assigned Error Try Again");
    }
    else
    {
        m_isPathValid = false;
    }
    this->close();
}
