#include "header.h"
#include "studio_T.h"

#define SUCCESS 0

using namespace std;

int main(){

    
    studio::MyClass a("Hi");
    studio::MyClass b("Bye");


    //#4,#5
    // cout<< a << " " << b << endl;
    // cout << (a<b);

    //#6
    studio::template_func(std::cout, a);
    cout << " " << endl;
    template_func(std::cout, 42);
  
    // b.template_func(std::cout, b);
    
  


    return SUCCESS;
}

