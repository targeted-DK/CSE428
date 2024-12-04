#include "header.h"

using namespace std;

std::ostream& operator<<(std::ostream& os, const MyClass& class_obj) {
    os << class_obj.var;
    return os;    
}

void MyClass::template_func(std::ostream& os, const MyClass& t){
            
            const char* message = " This is printed from non template_func : ";
             os << message;
            os << t;
        };
