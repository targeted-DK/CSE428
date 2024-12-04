#include "studio_T.h"
#include <iostream>

using namespace std;

template<typename T>
void template_func(std::ostream& os, const T& t){
    const char* message = " This is printed from template_func : ";
    os << message;
    os << t;
};

