#include <iostream>
#include "header.h"

using namespace std;

int main(){

    Test a = Test(1);
    Test b = Test(2);

   



    cout << a.x << " " << b.x << endl;
    std::swap(a, b);

    cout << a.x << " " << b.x << endl;

    // Foo<int> c();

    //Question : Why does c.x cause error? 
    // studio1.cpp:22:15: error: request for member ‘x’ in ‘c’, which is of non-class type ‘Foo<int>()’
    // cout << c << endl;
    

    return 0;
}