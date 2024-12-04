//BaseClass.cpp
//Author : Donggyu Kim, donggyukim@wustl.edu
//BaseClass source file
#include "BaseClass.h"
#include <iostream>

using namespace std;

// BaseClass::BaseClass() {
//     cout << "BaseClass::BaseClass()" << endl;
// };

BaseClass::~BaseClass() {
    cout << "BaseClass::~BaseClass()" << endl;
};

void BaseClass::test() {
    cout << "This function is test() and is included in BaseClass." << endl;
}


// , in which each of them prints out a statement indicating the class name and the method name (e.g., BaseClass::BaseClass()
//  in the constructor and BaseClass::~BaseClass() in the destructor), to the standard output stream.