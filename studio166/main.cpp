#include "header.h"
#include "studio_T.h"
#include "studio.h"

#define SUCCESS 0

using namespace std;

int main(){

    //#2.
    std::string str = "Hi!";
    // std::string str2 = "Bye!";
    const char* c_str = "Hi, c style string!";
    MyClass a("Hi, using myclass constructor!");
    int x = 99;
    float y = 3.14f;

   

    
    //#4.
    template_func_two(cout, str, c_str, a, x,y);

    return SUCCESS;
}

