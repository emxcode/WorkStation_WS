#ifndef DATABASE_H
#define DATABASE_H

#include<QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include "DataType/Task.h"

class Database
{
public:
    Database();
    ~Database();


    bool searchInDatabase(QString value, QString keyValue);
    bool addItemToDatabase(const Task task);
    bool updateData(QString value, QString keyValue);

private:
    QSqlDatabase *m_database;
};

#endif // DATABASE_H
