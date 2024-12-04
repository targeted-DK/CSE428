#include <iostream>
#include "header.h"

using namespace std;

// template<typename T = int> 
// struct Foo {

//     public:
//         T x;
//         Foo(T x1 = 0) : x(x1){};
// };


template<typename T>
class Foo {
    private : 
        T x;
    
    public : 
        Foo(T x1 = 0) : x(x1){};
    
   
};

template<typename T>
    ostream& operator<<<T>(ostream& os , const Foo<T>& f){
            os << x;
            return os;
}