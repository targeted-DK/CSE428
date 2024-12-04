//main.cpp
//Author : Donggyu Kim, donggyukim@wustl.edu
//main file that runs BaseClass, DerivedClass
#include "BaseClass.h"
#include "DerivedClass.h"
#include <iostream>
#include <memory>
#include <exception>
#include <functional>

using namespace std;

#define SUCCESS 0;

int main () { 
    BaseClass b;
    DerivedClass d;

    // const std::string DerivedClass::*dp1 = &DerivedClass::str;
    // const std::string DerivedClass::*dp2 = &BaseClass::str;
    // const std::string DerivedClass::*bp1 = &BaseClass::str;
    // void (BaseClass::*p1)() = &BaseClass::test;
    // void (DerivedClass::*p2)() = &BaseClass::test;
    // void (DerivedClass::*p3)() = &DerivedClass::test;

    // std::function<void(BaseClass*)> p1 = std::bind(&BaseClass::test, std::placeholders::_1);
    // std::function<void(DerivedClass*)> p2 = std::bind(&BaseClass::test, std::placeholders::_1);
    // std::function<void(DerivedClass*)> p3 = std::bind(&DerivedClass::test, std::placeholders::_1);

    auto p1 = mem_fn(&BaseClass::test);
    auto p2 = mem_fn(&BaseClass::test);
    auto p3 = mem_fn(&DerivedClass::test);
    // cout << (b.*p1)() << endl;
    // (b.*p1)();
    // (d.*p2)();
    // (d.*p3)();
    p1(&b);
    p2(&d);
    p3(&d);
    // cout << p2 << endl;
    // cout << p3 << endl;
    
    return SUCCESS;

  
}

// Then, in your main function replace the pointers to data members with a pointer to a base class member function 
// that is initialized to point to the base class member function, a pointer to a derived class member function 
// that is initialized to point to the base class member function, and a pointer to a derived class member function 
// that is initialized to point to the derived class member function.

// Modify the output statements in your main function so that they reflect which pointer the function is invoked through,
//  and then use each of them to invoke the member function it points to on the appropriate object as follows: 
//  the pointer to the base class member function is used to invoke its member function on the object of the base class type,
//   and the other two are used to invoke their member functions on the object of the derived class type.

// Build and run your program and as the answer to this exercise please show 
// (1) the output the program produced, and 
// (2) the modified statements in your main function that declare, initialize, and use the pointers to member functions.