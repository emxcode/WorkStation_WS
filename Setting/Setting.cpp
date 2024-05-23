#include "Setting.h"
#include "ui_Setting.h"

Setting::Setting(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Setting)
{
    ui->setupUi(this);
    m_databasePath = new QString;
    m_xDirectory = new xDirectory;
}

Setting::~Setting()
{
    delete ui;
    delete m_databasePath;
    delete m_xDirectory;
}

void Setting::on_pushButtonApplyChange_clicked()
{
    bool hasPathChanged = m_xDirectory->getHasChanged();
    if(hasPathChanged == true)
    {
        m_hasSettingChanged = true;
    }

    Q_EMIT sigSetPathToDatabase(m_databasePath);
}

void Setting::on_pushButtonSetDatabasePath_clicked()
{
    m_xDirectory->show();

}

void Setting::on_pushButtonCancel_clicked()
{
    this->close();
}

void Setting::on_pushButtonSetDefault_clicked()
{

}
