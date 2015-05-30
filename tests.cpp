#include "tests.h"
#include <iostream>
#include <QKeyEvent>
#include <QObject>

using namespace std;

Point::Point()
{
    v=0;
}

void Point::setValue(int t)
{
    if(v!=t)
    {
        v=t;
    emit valueChanged(v);

    }
}


