#include <iostream>
#include <string>
#include "studio_T.h"

namespace studio {
class MyClass{
    private :
        std::string var;

    public:
        MyClass(const std::string& str) : var(str){};

        // bool operator<(const MyClass& other_obj);
        // friend bool operator<(const MyClass& class_obj, const MyClass& other_obj);
        void template_func(std::ostream& os, const MyClass& t);

        
        friend std::ostream& operator<<(std::ostream& os, const MyClass& class_obj);
};

std::ostream& operator<<(std::ostream& os, const MyClass& class_obj) {
    os << class_obj.var;
    return os;    
}

void template_func(std::ostream& os, const MyClass& t){
            
            const char* message = " This is printed from non template_func : ";
             os << message;
            os << t;
        };

}
// bool operator<(const MyClass& other_obj){
//             return this->var < other_obj.var;
// }

// bool operator<(const MyClass& class_obj, const MyClass& other_obj){
    
//     return class_obj.var < other_obj.var;
// }


