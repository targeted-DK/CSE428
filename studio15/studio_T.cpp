#include "studio_T.h"
#include <iostream>

using namespace std;

static unsigned int x = 0;

template<typename T, typename... Args>
void template_func(std::ostream& os, const T& t, const Args&... args){

    check_size(t);
    os << t;
    os << " ";
    template_func(os, args...);

     if(sizeof...(args) == 0) { 
        os << "Total bytes in function parameter pack: " << x << endl;
    }
};

void template_func(std::ostream& os) {
    os << std::endl;
}

template<typename... Args>
void template_func_two(std::ostream& os, const Args&... args){
    
    os << "# of elements left in arguments : " << sizeof...(args) << endl;
    template_func(os, args...);
}

template<typename T>
const T& check_size(const T& t){
        x = x + sizeof(t);
    return t;
}

