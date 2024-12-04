//source2.cpp
//Donggyu Kim, donggyukim@wustl.edu
//source file 2
#include "header.h"
#include <iostream>

using std::ostream;
using std::cout;
using std::endl;

using namespace enumerations;

int main(/*int argc, char *argv[]*/){

    Pressure p = Pressure::lo;
    Weekday w = Weekday::mon;


    while(p != Pressure::pop){
        cout << p << " ";
        ++p;
    }
    cout << Pressure::pop << " ";
    cout << endl;

    while(w != Weekday::sun){
        cout << w << " ";
        w++;

    }
    cout << Weekday::sun << " ";
    cout << endl;
}