#include "header.h"
#include "studio_T.h"

#define SUCCESS 0

using namespace std;

int main(){

    //#2.
    std::string str = "Hi!";
    std::string str2 = "Bye!";
    const char* c_str = "Hi, c style string!";
    studio::MyClass a("Hi, using myclass constructor!");
    int x = 99;
    float y = 3.14f;

    //#2.
    // template_func(cout, str);
    // cout << endl;
    // template_func(cout, c_str);
    // cout << endl;
    // template_func(cout, a);
    // cout << endl;
    // template_func(cout, x);
    // cout << endl;
    // template_func(cout, y);
    // cout << endl;

    //#3.
    // template_func(cout, str, c_str, a, x, y);

    //#4.
    template_func_two(cout, str, c_str, a, x, y);



    return SUCCESS;
}

