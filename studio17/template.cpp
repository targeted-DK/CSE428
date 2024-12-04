#include "template.h"
#include <iostream>

using namespace std;

template <typename T>
void iterateAndPrint(T begin, T end) {
    for (T ptr = begin; ptr != end; ++ptr) {
        cout << *ptr << endl;
    }
}

