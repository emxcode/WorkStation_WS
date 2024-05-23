#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "Setting/Setting.h"
#include <QMessageBox>
#include "DataType/Structure.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT



public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void addItemInMyTodoList(const QVector<QString>& item);


private:
    Setting *m_settingWidget;



private slots:
    void on_pushButtonAddEvent_clicked();

    void on_pushButtonSetSetting_clicked();

Q_SIGNALS:
    void sigNewEvent(const QString& event);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
