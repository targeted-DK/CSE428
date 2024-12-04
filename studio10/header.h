//header.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//header file

#include <string>
#include <iostream>

#pragma once

class BaseClass {
    private : 
        static std::size_t count;
        std::size_t id;
    
    public: 
        BaseClass();  
        BaseClass(const BaseClass& other); 
        ~BaseClass();  
        void display() const; 

};

// Add a header and source file for a class that has 
// (1) a static member variable of type size_t that is initialized to 0 and will be used to track how many objects of that class have been constructed;
//  (2) a non-static member variable of type size_t that (along with its memory address that is stored in its this pointer) identifies the object; 
//  (3) a default constructor that initializes the non-static member variable with the value of the static member variable, increments the static member variable,
//   and then prints to the standard output stream a message indicating that the default constructor was called and what the non-static member variable's value and the object's address are; 
//   (4) a copy constructor that initializes the non-static member variable with the value of the non-static member variable of the object from which it is being constructed, 
//   increments the static member variable, and then prints to the standard output stream a message indicating that the copy constructor was called and
//    what the non-static member variable's value and the object's address are; and 
//    (5) a destructor that prints to the standard output stream a message indicating that the destructor was called and
//     what the non-static member variable's value and the object's address are (but does not modify the static member variable).
