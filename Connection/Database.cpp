#include "Database.h"

Database::Database()
{
    m_database = new QSqlDatabase;
}

Database::~Database()
{
    delete m_database;
}

bool Database::searchInDatabase(QString value, QString keyValue)
{
    return false;
}

bool Database::addItemToDatabase(const Task task)
{
    return false;
}

bool Database::updateData(QString value, QString keyValue)
{
    return false;
}
