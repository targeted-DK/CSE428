//main.cpp
//Author : Donggyu Kim, donggyukim@wustl.edu
//main file that runs BaseClass, DerivedClass
#include "BaseClass.h"
#include "DerivedClass.h"
#include <iostream>
#include <memory>
#include <exception>

using namespace std;

#define SUCCESS 0;

int main () {
    
    // shared_ptr<BaseClass> a = new *
    // shared_ptr<DerivedClass> b = make_shared<DerivedClass>();
//    try {

//         BaseClass *b1 = new BaseClass();
//         throw exception;
      
//     }
//     catch (const exception& de) {
//         std::cout << "Caught in DerivedException block: " << de.what() << std::endl;
       
//     }
    // catch (const exception& be) {
    //     std::cout << "Caught in BaseException block: " << be.what() << std::endl;
    //     be.test();
    // }


//#7.
    BaseClass *b1 = new BaseClass();
    BaseClass *b2 = new BaseClass();
    DerivedClass *d = new DerivedClass();

   b1->test();
   b2->test();
   d->test();

   delete b1;
   delete b2;
   delete d; 



    // BaseClass a;
    // DerivedClass b;

    // BaseClass &baseRef1 = a;             
    // BaseClass &baseRef2 = b;          
    // DerivedClass &derivedRef = b;     


    // // baseRef1.test();  
    // // baseRef2.test();  
    // // derivedRef.test(); 

    // BaseClass* base1;
    // BaseClass* base2;
    // DerivedClass* derived;
    
    // base1 = &baseRef1;
    // base2 = &baseRef2;
    // derived = &derivedRef;

    // base1->test();
    // base2->test();
    // derived->test();




    return SUCCESS;

}