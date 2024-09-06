#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickView>

#include "myclass.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Dashboard2", "Main");






    MyClass myClass(engine);
    QObject::connect(engine.rootObjects().at(0)->findChild<QObject*>("mySlider"), SIGNAL(qmlSignal(int)),
                     &myClass, SLOT(cppSlot(int)));

    QObject::connect(engine.rootObjects().at(0)->findChild<QObject*>("myButton"), SIGNAL(qmlPressed()),
                     &myClass, SLOT(buttonPressed()));

    QObject::connect(engine.rootObjects().at(0)->findChild<QObject*>("shutdownBtn"), SIGNAL(exitPressed()),
                     &myClass, SLOT(exitPressed()));

    return app.exec();
}
