#include <iostream>
#include "complex.h"

using namespace std;
int main()
{
    Complex c1(5,2),c2(5,3);
    c1.Print();
    c2.Print();
    Complex c3= c1*c2;
    c3.Print();
    if (c1!=c2)
        cout << "unequal complex numbers";
    else
        cout << "equal complex numbers";
}
