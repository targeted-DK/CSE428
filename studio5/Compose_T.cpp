// File: Compose_T.cpp
// Purpose: Unary function composition template declaration for 
//          Functional Programming Studio

#include "Compose_T.h"

// From https://stackoverflow.com/questions/19071268/function-composition-in-c-c11
template <class F, class G> auto compose (F f, G g) {
  return [f, g](auto x) { return f(g(x)); };
}
// The function returns a lambda (an anonymous function) that captures f and g by value. 
// This lambda can accept an argument of any type (thanks to auto x), applies g to it, 
// and then applies f to the result of g. The composed function is returned to the caller.