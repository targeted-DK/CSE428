#include <iostream>
#include <string>

#pragma once

class MyClass{
    private :
        std::string var;

    public:
        MyClass(const std::string& str) : var(str){};
        void template_func(std::ostream& os, const MyClass& t);

        
        friend std::ostream& operator<<(std::ostream& os, const MyClass& class_obj);
};


std::ostream& operator<<(std::ostream& os, const MyClass& class_obj);





