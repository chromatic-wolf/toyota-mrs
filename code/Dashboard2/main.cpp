#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QObject>
#include <QQuickView>
#include <QTimer>
#include <QString>

#include "myclass.h"
#include "fakeengine.h"

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

    fakeEngine myEngine;


    QTimer *timer = new QTimer();

    QObject::connect(timer, SIGNAL(timeout()),
            &myEngine, SLOT(tickEngine()));


    timer->start(1000);


    MyClass myClass(engine);
    QObject::connect(engine.rootObjects().at(0)->findChild<QObject*>("mySlider"), SIGNAL(qmlSignal(int)),
                     &myClass, SLOT(cppSlot(int)));

    QObject::connect(engine.rootObjects().at(0)->findChild<QObject*>("myButton"), SIGNAL(qmlPressed()),
                     &myClass, SLOT(buttonPressed()));

    QObject::connect(engine.rootObjects().at(0)->findChild<QObject*>("shutdownBtn"), SIGNAL(exitPressed()),
                     &myClass, SLOT(exitPressed()));

    QObject::connect(&myEngine, SIGNAL(getRpm(double)), &myClass, SLOT(rpmUpdateSlot(double)));
    QObject::connect(&myEngine, SIGNAL(getPressure(double)), &myClass, SLOT(pressureUpdateSlot(double)));
    QObject::connect(&myEngine, SIGNAL(getCurrentVe(double)), &myClass, SLOT(veUpdateSlot(double)));


    return app.exec();
}
