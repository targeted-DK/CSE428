#ifndef MY_MOVE_H
#define MY_MOVE_H

#include <type_traits>

template <typename T>
typename std::remove_reference<T>::type&& myMove(T&& t);

#include "move_T.cpp"


#endif 
