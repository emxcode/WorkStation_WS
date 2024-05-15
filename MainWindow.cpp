#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addItemInMyTodoList(const QVector<QString> &item)
{


}


void MainWindow::on_pushButtonAddEvent_clicked()
{
    QString event = ui->lineEditEventDiscription->text();
    Q_EMIT sigNewEvent(event);
}
