#include "Controller.h"

Controller::Controller()
{
    createObject();
    m_mainWindow->show();
    initializeConnection();
}

Controller::~Controller()
{
    delete m_toDoList;
    delete m_mainWindow;
}

void Controller::initializeConnection()
{
    connect(m_mainWindow, &MainWindow::sigNewEvent, this, &Controller::sltNewEvent);
    connect(m_toDoList, &ToDoList::sigUpdateListItem, this, &Controller::sltUpdateListItem);
}

void Controller::createObject()
{
    m_mainWindow = new MainWindow();
    m_toDoList = new ToDoList();
}

void Controller::sltNewEvent(const QString &event)
{
    m_toDoList->addItem(event);
}

void Controller::sltUpdateListItem(const QVector<QString> *item)
{

}
