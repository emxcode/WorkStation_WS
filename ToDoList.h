#ifndef TODOLIST_H
#define TODOLIST_H
#include <QString>
#include <QVector>
#include <QObject>

class ToDoList : public QObject
{
    Q_OBJECT
public:
    ToDoList();
    ~ToDoList();

     void addItem(const QString& item);
     void updateList();


private:

    QVector<QString> *m_itemList;
    inline void initObject();


Q_SIGNALS:
    void sigUpdateListItem(const QVector<QString>* item);

};

#endif // TODOLIST_H
