#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <MainWindow.h>
#include <ToDoList.h>
#include <QObject>

class Controller : public QObject
{
    Q_OBJECT
public:
    Controller();
    ~Controller();

private:
    MainWindow *m_mainWindow;
    ToDoList *m_toDoList;
    inline void initializeConnection();
    inline void createObject();

private Q_SLOTS:
    void sltNewEvent(const QString& event);
    void sltUpdateListItem(const QVector<QString>* item);

};

#endif // CONTROLLER_H
