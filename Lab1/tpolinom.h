#ifndef TPOLINOM_H
#define TPOLINOM_H

#include "number.h"
#include <iostream>

enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic
};

class TPolinom
{
private:
    number a, b, c;
    EPrintMode printMode;
    number r1, r2;
public:
    TPolinom(number,number,number);

    friend std::ostream& operator<<(std::ostream&, TPolinom&);

    number value(number);

    void setPrintMode(EPrintMode);

    bool roots();

    void printRoots();

    bool isInteger(number);

};

#endif // TPOLINOM_H
