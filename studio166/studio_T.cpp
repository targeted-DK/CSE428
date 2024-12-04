#include "studio_T.h"
#include "header.h"
#include <iostream>

using namespace std;

static unsigned int x = 0;
static unsigned int int_bytes = 0;
static unsigned int float_bytes = 0;

template <typename T> 
void template_func(std::ostream &os, T t){
     
     check_size(t);
    os << t << endl;
    os << "Total bytes in function parameter pack: " << x << endl;
    os << "Total bytes in float: " << float_bytes << endl;
    os << "Total bytes in int: " << int_bytes << endl;
}

template<typename T, typename... Args>
void template_func(std::ostream& os, const T& t, const Args&... args){

   
    check_size(t);
    os << t << endl;
    template_func(os, args...);
   
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

template <>
const int& check_size<int>(const int& variable) {
    x += sizeof(variable);
    int_bytes += sizeof(variable);
    return variable;
}


template <>
const float& check_size<float>(const float& variable) {
    x += sizeof(variable);
    float_bytes += sizeof(variable);
    return variable;
}



template<typename... Args>
void template_func(std::ostream& os, const std::string& str, const Args&... args){
    check_size(str);
    os << "\"" << str << "\"" << endl;
    template_func(os, args...);
}

template<typename... Args>
void template_func(std::ostream& os,const char * const c, const Args&... args){
    check_size(c);
    os << "[" << c << " " << reinterpret_cast<const void*>(c) << "] " << endl;
    template_func(os, args...);
}

template<typename... Args>
void template_func(std::ostream& os, MyClass myclass, const Args&... args){
     check_size(myclass);
     os << "{" << myclass << &myclass << " } " << endl;
    template_func(os, args...);
}





    


