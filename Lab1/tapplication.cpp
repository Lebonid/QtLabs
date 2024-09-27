#include "tapplication.h"
#include <limits>
#include <tpolinom.h>
#include <iostream>


using namespace std;

TApplication::TApplication()
{

}

int TApplication::exec()
{
    int ch;
    number a = 2,b = 10,c = -12;
    while (true)
    {
        ch = menu();
        switch(ch)
        {
        case 0:
            return 0;
        case 1:
            a=inputCoffA();
            cout << "b = ";
            cin >> b;
            cout << "c = ";
            cin >> c;
            break;
        case 2:
        {
            number x;
            cout << "x = ";
            cin >> x;
            TPolinom p(a,b,c);
            number v = p.value(x);
            cout << "p(" << x << ") = " << v << endl;
        }
            break;
        case 3:
        {
            TPolinom p(a,b,c);
            p.printRoots();
        }
            break;
        case 4:
        {
            TPolinom p(a,b,c);
            p.setPrintMode(EPrintModeClassic);
            cout << p << endl;
        }
            break;
        case 5:
        {
            TPolinom p(a,b,c);
            p.setPrintMode(EPrintModeCanonic);
            cout << p << endl;
        }
        break;
        default:
            break;
        }
    }
    return ch;
}

int TApplication::menu()
{
    int ch;
    cout << "1 - coefficient" << endl;
    cout << "2 - value" << endl;
    cout << "3 - roots" << endl;
    cout << "4 - print (classic)" << endl;
    cout << "5 - print (canonical)" << endl;
    cout << "0-exit" << endl<< ">";
    cin >> ch;
    return ch;
}

number TApplication::inputCoffA()
{
    number n = 0, min = 0;

    do{
        cout << "Enter Coffencient a = ";
        if(!(cin>>n)||(n==min)){
            cout << "Coffencient need be more 0" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while(n==0);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return n;
}

