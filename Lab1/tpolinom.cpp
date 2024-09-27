#include "tpolinom.h"
#include "cmath"

TPolinom::TPolinom(number x,number y,number z)
{
    printMode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
}

std::ostream& operator<<(std::ostream& os, TPolinom& p)
{
    if(p.printMode == EPrintModeClassic)
    {
        //os << p.a << "x^2 + " << p.b << "x + " << p.c;
        if(p.a == -1){
            os << "-x^2";
        }else if(p.a == 1){
            os << "x^2";
        }else{
            os << p.a << "x^2";
        }

        if(p.b > 0)
        {
            os << "+" << p.b << "x";
        }else if(p.b < 0){
            os << p.b << "x";
        }
        if(p.c > 0)
        {
            os << "+" << p.c;
        }else if(p.c < 0)
        {
            os << p.c;
        }

    }else{
        if(p.roots())
        {
            if(p.a!=1)
            {
                if(p.a == -1){
                    os << "-";
                }else{
                    os << p.a;
                }
            }

            if(p.r1 > 0)
            {
                os << "(x-" << p.r1 << ")";
            }else if(p.r1 == 0)
            {
                 os << "(x)";
            }
            else{
                os << "(x+" << (-1)*p.r1 << ")" ;
            }

            if(p.r2 > 0)
            {
                os << "(x-" << p.r2 << ")";
            }else if(p.r2 == 0)
            {
                os << "*(x)" << std::endl;
            }
            else{
                os << "*(x+" << (-1)*p.r2 << ")" << std::endl;
            }
        }
        else{
            std::cout << "Canonic dont exist" << std::endl;
        }
    }

    return os;
}

number TPolinom::value(number x)
{
    return a*x*x+b*x+c;
}
void TPolinom::setPrintMode(EPrintMode m)
{
    printMode = m;
}

bool TPolinom::roots()
{
    number d = (b*b)-(4*a*c);
    if(d > 0)
    {
        r1 = (-b+(sqrt(d)))/(2*a);

        r2 = (-b-(sqrt(d)))/(2*a);

        if(!isInteger(r1) && !isInteger(r2)){
            std::cout << "Roots does not meet the condition" <<std::endl;
            return false;
        }

        return true;
    }else if(d == 0)
    {
        r1 = ((-1)*b)/(2*a);
        r2=r1;
        std::cout << "Root is 0" << std::endl;
        return true;
    }else{
        std::cout << "Roots dont exist" << std::endl;
        return false;
    }
}

void TPolinom::printRoots()
{
    if(roots()){
        std::cout << "Root 1 = " << r1 << std::endl << "Root 2 = " << r2 <<std::endl;
    }
}

bool TPolinom::isInteger(number num)
{
    return fabs(num - static_cast<int>(num)) < 1e-9;
}
