#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QQmlApplicationEngine>


class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);
    MyClass(QQmlApplicationEngine &engine);

public slots:
    void cppSlot(const int &msg);
    void buttonPressed();
    void exitPressed();
    void rpmUpdateSlot(double text);
    void pressureUpdateSlot(double text);
    void veUpdateSlot(double text);
    void torqueUpdateSlot(double value);
    void powerUpdateSlot(double value);

signals:
};

#endif // MYCLASS_H
