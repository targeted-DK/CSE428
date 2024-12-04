#include "header.h"
#include <memory>

using namespace std;

void invoke(unique_ptr<MyClass> ptr){

    ptr->print();

    // return ptr;
};

int main(){


    MyClass a("hello");
    MyClass b(a);
    MyClass c("3");
    c = b = a;
    unique_ptr<MyClass> p1 = unique_ptr<MyClass>(new MyClass("hello"));
    unique_ptr<MyClass> p2 = std::move(p1);
    invoke(move(p2));
    p1->print();

    int SUCCESS = 0;
    return SUCCESS;
   
}

// In the source file where you defined your program's main function, 
// define a function with a void return type that takes a unique_ptr to your class type by value, 
// and uses it to invoke the public virtual member function of the object to which the unique_ptr points.

