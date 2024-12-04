//DerivedClass.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//DerivedClass header file
#include "BaseClass.h"
#include <string>
#include <iostream>

#pragma once
class DerivedClass : public BaseClass {
    public :
        DerivedClass() : str("DerivedClass") {
            std::cout << "DerivedClass::DerivedClass()" << std::endl;
        };
        virtual ~DerivedClass();
        virtual void test();
    
    private : 
        const std::string str;


};


