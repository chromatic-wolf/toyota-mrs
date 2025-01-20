#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>

class testClass : public QObject
{
    Q_OBJECT
public:
    explicit testClass(QObject *parent = nullptr);

signals:
};

#endif // TESTCLASS_H
