#include "Task.h"

Task::Task()
{
    briefName = new QString;
    periority = new quint16;
    definotion = new QString;
}

Task::~Task()
{
    delete briefName;
    delete periority;
    delete definotion;
}
