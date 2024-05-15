#include "ToDoList.h"

ToDoList::ToDoList()
{
    initObject();
}

ToDoList::~ToDoList()
{
    delete m_itemList;
}

void ToDoList::addItem(const QString &item)
{
    m_itemList->append(item);
}

void ToDoList::updateList()
{
    Q_EMIT sigUpdateListItem(m_itemList);
}

void ToDoList::initObject()
{
    m_itemList = new QVector<QString>;
}
