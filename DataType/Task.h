#ifndef TASK_H
#define TASK_H
#include <QString>

class Task
{
public:
    Task();
    ~Task();


private:
    QString *briefName;
    quint16 *periority;
    QString *definotion;


};

#endif // TASK_H
