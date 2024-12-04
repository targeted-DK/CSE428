#ifndef STUDIO_T_H
#define STUDIO_T_H
#include <iostream>
#include "header.h"



template <typename T> 
void template_func(std::ostream &os, T t);

template<typename T, typename... Args>
void template_func(std::ostream& os, const T& t, const Args&... args);

void template_func(std::ostream& os);

template<typename T>
const T& check_size(const T& t);

template <>
const int& check_size<int>(const int& variable);

template <>
const float& check_size<float>(const float& variable);


template<typename... Args>
void template_func(std::ostream& os, const std::string& str, const Args&... args);


template<typename... Args>
void template_func(std::ostream& os,const char * const c, const Args&... args);


template<typename... Args>
void template_func(std::ostream& os, MyClass myclass, const Args&... args);







#include "studio_T.cpp"
#endif 
