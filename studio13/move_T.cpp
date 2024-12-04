#include "move_T.h"
#include <type_traits>

using namespace std;

template <typename T> 
typename remove_reference<T>::type&& myMove (T&& t) {
  return static_cast<typename remove_reference<T>::type&&> (t);
}


