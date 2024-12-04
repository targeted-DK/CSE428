//header.h
//Donggyu Kim
//header file for studio6
#include <iostream>

using namespace std;

class Test {
    
    private: 
        int x_; int y_;

    public : 
        int getX () const; int getY () const; 
        Test& setX (int); Test& setY (int); 
        Test();
        Test(const Test &);
};

Test returnbyValue(Test);


// Declare and define (in your header and source files respectively) a copy constructor for the class that takes a const reference to another object of the same type and 
// initializes its member variables (again in the base-member initialization list) to have the values of the member variables of the object from which the current object is being constructed;
//  make sure to use the base-member initialization list for initializing member variables in the copy constructor (instead of assigning them in the body of the constructor).