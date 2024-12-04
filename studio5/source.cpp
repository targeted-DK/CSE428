//source.cpp
//Donggyu Kim, donggyukim@wustl.edu
//source file for studio5
#include <cstring>
#include <iostream>
#include <cmath>
#include <functional>
#include "Compose_T.h"

using namespace std;
using namespace std::placeholders;

int main(int argc, char *argv[]){

     const char *str1 = "Hello!";
    const char *str2 = "World!";
    std::size_t (*p)( const char* ) = std::strlen;
     cout << (*p)(str1) << endl;
       cout << (*p)(str2) << endl;
    cout << "\"" << str1 << "\"" << endl;
    cout << "\"" << str2 << "\"" << endl;
   cout <<  std::strlen(str1) << endl;
    cout << std::strlen(str2) << endl;
    float number = 1;
    auto b =  std::sin(std::cos(number));
    function<float(float)> sn =
		 [](auto i) { return std::sin(i); }; 
    
      function<float(float)> cs =
		 [](auto i) { return std::cos(i); }; 

    // cout << sn(cs(number));
    auto a = compose(sn, cs);
    auto c = a(number);
    auto d = bind(a,123);

    cout << c << endl;
    cout << d();

    return 0;



    
}