#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>

class testClass : public QObject
{
    Q_OBJECT
public:
    explicit testClass(QObject *parent = nullptr);

public slots:
    void testSlot();
signals:
    void testSignal();
};

#endif // TESTCLASS_H
