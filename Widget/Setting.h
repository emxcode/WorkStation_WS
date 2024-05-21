#ifndef SETTING_H
#define SETTING_H

#include <QWidget>
#include <QFileDialog>

namespace Ui {
class Setting;
}

class Setting : public QWidget
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = nullptr);
    ~Setting();



private slots:
    void on_pushButtonApplyChange_clicked();

    void on_pushButtonSetDatabasePath_clicked();

    void on_pushButtonCancel_clicked();

private:
    Ui::Setting *ui;
    QString *m_databasePath;

Q_SIGNALS:
    void sigSetPathToDatabase(const QString *path);
};

#endif // SETTING_H
