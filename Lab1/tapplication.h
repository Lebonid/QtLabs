#ifndef TAPPLICATION_H
#define TAPPLICATION_H
#include "number.h"

class TApplication
{
public:
    TApplication();
    int exec();
    number inputCoffA();

private:
    int menu();

};

#endif // TAPPLICATION_H
