// TinyNamespace.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "minimath.h"

using std::cout;
using std::endl;

using minimath::square;
using minimath::cube;

int main() {
    double y = 123.45;
    double z = square(y);
    cout << "x^2 =" << z << endl;
    cout << "x cubed is : " << cube(y) << endl;
}