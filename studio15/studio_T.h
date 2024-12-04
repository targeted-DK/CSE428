#ifndef STUDIO_T_H
#define STUDIO_T_H
#include <iostream>


template<typename T, typename... Args>
void template_func(std::ostream& os, const T& t, const Args&... args);
void template_func(std::ostream& os);

template<typename T>
const T& check_size(const T& t);


#include "studio_T.cpp"
#endif 
