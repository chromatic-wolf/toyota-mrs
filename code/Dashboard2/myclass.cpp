#include "myclass.h"
#include <QDebug>
#include <QQmlApplicationEngine>
#include <QQuickItem>
#include <QString>

QQmlApplicationEngine *eng;
bool animationTriggered = false;

MyClass::MyClass(QObject *parent)
    : QObject{parent}
{}

MyClass::MyClass(QQmlApplicationEngine &engine)
{
    eng = &engine;
}

void MyClass::cppSlot(const int &msg)
{
qDebug() << "Called the C++ slot with message:" << msg;

    QObject *item = eng->rootObjects().at(0)->findChild<QObject*>("myCar");
    item->setProperty("width", msg + 400);

item->setProperty("height", msg + 400);


}

void MyClass::buttonPressed()
{
    qDebug() << "Button pressed";
    QObject *item = eng->rootObjects().at(0)->findChild<QObject*>("myCar");

        item->setProperty("running", "false");
    item->setProperty("running", "true");


}

void MyClass::exitPressed()
{
    QCoreApplication::quit();
}

void MyClass::rpmUpdateSlot(QString text)
{
    QObject *item = eng->rootObjects().at(0)->findChild<QObject*>("rpmTxt");
    item->setProperty("text", text);
}

void MyClass::pressureUpdateSlot(QString text)
{
    QObject *item = eng->rootObjects().at(0)->findChild<QObject*>("pressureText");
    item->setProperty("text", text);
}
