//DerivedClass.cpp
//Author : Donggyu Kim, donggyukim@wustl.edu
//DerivedClass source file
#include "BaseClass.h"
#include "DerivedClass.h"


#include <iostream>
using namespace std;

DerivedClass::DerivedClass() {
    cout << "DerivedClass::DerivedClass()" << endl;
};

DerivedClass::~DerivedClass() {
    cout << "DerivedClass::~DerivedClass()" << endl;
};

void DerivedClass::test() {
    cout << "This function is test() and is included in DerivedClass." << endl;
}
