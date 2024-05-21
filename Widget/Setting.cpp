#include "Setting.h"
#include "ui_Setting.h"

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    m_databasePath = new QString;
}

Setting::~Setting()
{
    delete ui;
    delete m_databasePath;
}

void Setting::on_pushButtonApplyChange_clicked()
{
   Q_EMIT sigSetPathToDatabase(m_databasePath);
}

void Setting::on_pushButtonSetDatabasePath_clicked()
{
    QFileDialog folder;
    QString path;

    folder.setFileMode(QFileDialog::Directory);
    folder.setOption(QFileDialog::ShowDirsOnly);
    folder.setWindowTitle("Set Database Path");
    path = folder.getExistingDirectory(this);
    ui->labelPath->setText(path);
    m_databasePath = &path;
}

void Setting::on_pushButtonCancel_clicked()
{
    this->close();
}
