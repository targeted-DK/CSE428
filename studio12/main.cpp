#include "header.h"
#include <iostream>
#include <memory>

using namespace std;


int main(){
    
    // //(1) a const int variable initialized with the value 0, 
    // const int a = 0;
    // auto aa = a;
    // //(2) a non-const int variable initialized with the value 1, 
    // int b = 1;
    // auto bb = b;
    // //(3) a const pointer to a const int variable initialized with the address of the const int variable, 
    // const int* const c = &a;
    // auto cc = c;
    // //(4) a const pointer to a const int variable initialized with the address of the non-const int variable, 
    // const int* const d = &b;
    // auto dd = d;
    // //(5) a const pointer to a non-const int variable initialized with the address of the const int variable, 
    // // int* e = &a; 
    // //(6) a const pointer to a non-const int variable initialized with the address of the non-const int variable, 
    // int *const f = &b;
    // auto ff = f;
    // //(7) a non-const pointer to a const int variable initialized with the address of the const int variable, 
    // const int * g = &a;
    // auto gg = g;
    // //(8) a non-const pointer to a const int variable initialized with the address of the non-const int variable, 
    // const int * h = &b;
    // auto hh = h;
    // //(9) a non-const pointer to a non-const int variable initialized with the address of the const int variable,
    // // int * i = &a;
    // //(10) a non-const pointer to a non-const int variable initialized with the address of the non-const int variable. 
    // int * j = &b;
    // auto jj = j;

    // (1) a const int variable initialized with the value 0
// const int a = 0;
// decltype(a) aa = a; // decltype(a) is const int

// // (2) a non-const int variable initialized with the value 1
// int b = 1;
// decltype(b) bb = b; // decltype(b) is int

// // (3) a const pointer to a const int variable initialized with the address of the const int variable
// const int* const c = &a;
// decltype(c) cc = c; // decltype(c) is const int* const

// // (4) a const pointer to a const int variable initialized with the address of the non-const int variable
// const int* const d = &b;
// decltype(d) dd = d; // decltype(d) is const int* const

// // (6) a const pointer to a non-const int variable initialized with the address of the non-const int variable
// int* const f = &b;
// decltype(f) ff = f; // decltype(f) is int* const

// // (7) a non-const pointer to a const int variable initialized with the address of the const int variable
// const int* g = &a;
// decltype(g) gg = g; // decltype(g) is const int*

// // (8) a non-const pointer to a const int variable initialized with the address of the non-const int variable
// const int* h = &b;
// decltype(h) hh = h; // decltype(h) is const int*

// // (10) a non-const pointer to a non-const int variable initialized with the address of the non-const int variable
// int* j = &b;
// decltype(j) jj = j; // decltype(j) is int*



    // cout << "Current variable and its value is a, " << a << " and the address is " << &a  << endl;
    //  cout << "Current variable and its value is b, " << b << " and the address is " << &b  << endl;
    //  cout << "Current variable and its value is c, " << c << " and the address is " << &c  << endl;
    //  cout << "Current variable and its value is d, " << d << " and the address is " << &d  << endl;
    //  cout << "Current variable and its value is f, " << f << " and the address is " << &f  << endl;
    //  cout << "Current variable and its value is g, " << g << " and the address is " << &g  << endl;
    //  cout << "Current variable and its value is h, " << h << " and the address is " << &h  << endl;
    // cout << "Current variable and its value is j, " << j << " and the address is " << &j  << endl;
    
    //step 3
    // Modify variables
    // ++b;  
    // // ++(*d);
    // ++(*f);
    // // ++(*g);
    // // ++(*h);
    // ++j;

    //step 4
    // ++aa;
    // ++bb;
    // ++cc;
    // ++dd;
    // ++ff;
    // ++gg;
    // ++hh;
    // ++jj;

    typedef int myInt;
typedef const int myConstInt;
typedef int* myIntPtr;
typedef const int* myConstIntPtr;
typedef int* const myConstPtrToInt;
typedef const int* const myConstPtrToConstInt;

 myConstInt a = 0;
    myInt b = 1;
    myConstPtrToConstInt c = &a;
    myConstPtrToConstInt d = &b;
    // myIntPtr e = &a; // Invalid: Cannot point non-const pointer to const int
    myConstPtrToInt f = &b;
    myConstIntPtr g = &a;
    myConstIntPtr h = &b;
    // myIntPtr i = &a; // Invalid: Cannot point non-const pointer to const int
    myIntPtr j = &b;
   
  
   
   
  
    int SUCCESS = 0;
    return SUCCESS;
   
}
