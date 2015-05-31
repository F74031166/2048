#ifndef TESTS_H
#define TESTS_H
#include <iostream>
#include <QObject>


class Point:public QObject
{
    Q_OBJECT
public:
    Point();
    int value() const {return v;}
public slots:
    void setValue(int t);
signals:
    void valueChanged(int i);
private:
    int v;



};




#endif // SIGNAL

