#ifndef XDIRECTORY_H
#define XDIRECTORY_H

#include <QWidget>
#include <QFileDialog>
#include <QString>
#include <QMessageBox>

namespace Ui {
class xDirectory;
}

class xDirectory : public QWidget
{
    Q_OBJECT

    enum xDirectoryPopupMessage
    {
        PATH_VALIDITY,
        OPERATION_FAILED,
        OPERATION_SUCCESED,
        SAME_PATH
    };

public:
    explicit xDirectory(QWidget *parent = nullptr);
    ~xDirectory();


    bool getHasChanged() const;

    bool getIsPathValid() const;
    void setIsPathValid(bool isPathValid);

    QString getWorkingDirectoryPath() const;

    QString getDatabasePath() const;

private:
    QString getPath(const bool& isValidRequested, const bool& isEmptyRequested, const QString &subject);
    void giveMessage(const xDirectoryPopupMessage& messageType,
                     const QString& title,
                     const QString& text);

    bool m_hasChanged = false;
    bool m_isPathValid = false;
    QString m_workingDirectoryPath;
    QString m_databasePath;

private slots:
    void on_pushButtonCancel_clicked();

    void on_pushButtonSetWorkingPath_clicked();

    void on_pushButtonSetDatabasePath_clicked();

    void on_pushButtonApply_clicked();

    void on_pushButtonOK_clicked();

private:
    Ui::xDirectory *ui;
};

#endif // XDIRECTORY_H
