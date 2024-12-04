#include "header.h"
#include <iostream>

using namespace std;

MyClass::MyClass(const string& str) : var(str){
    cout << "Constructor : Address of this object is : " << this << endl;
    cout << "Constructor : Variable of this object is : " << var << endl;
}
MyClass::MyClass(const MyClass& other) : var(other.var) {

    cout << "Copy Constructor : Address of this object is : " << this << endl;
    cout << "Copy Constructor : Variable of this object is : " << this->var << endl;
    cout << "Copy Constructor : Address of other object is : " << &other << endl;
     cout << "Copy Constructor : Variable of other object is : " << other.var << endl;
}

MyClass::~MyClass() {
    cout << "Destructor : Address of this object is : " << this << endl;
    cout << "Destructor : Variable of this object is : " << var << endl;
}
void MyClass::print(){
    cout << "print() : Address of this object : " << this << endl;
    cout << "print() : object's private member variable : " << this->var << endl;
   
}
 MyClass& MyClass::operator=(const MyClass& myclass){
        cout << "operator= : Address of private member variable is : " << &myclass.var << endl;
        cout << "operator= : Value of private member variable is : " << myclass.var << endl;
        this->var = myclass.var;

        return *this;
 }

 // Declare and define a public assignment operator for your class, 
// which takes a const reference to an object of the class type and returns a non-const reference to an object of the class type. 
// That operator should (1) first print out the address and private member variable of the object on which it is being called, 
// followed by the address and private member variable of the object that was passed into it;
//  (2) assign its private member variable the private member variable of the object that was passed into it; and then
//   (3) return a (non-const) reference to the object on which it was invoked.