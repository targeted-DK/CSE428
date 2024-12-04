//source.cpp
//Donggyu Kim, donggyukim@wustl.edu
//source file
#include "header.h"
#include <iostream>
#include <algorithm>
#include <iterator>

using std::ostream;
using std::cout;
using std::endl;

// using namespace enumerations::Pressure;
using namespace enumerations::operator++;
using namespace enumerations::operator--;
using namespace enumerations::operator<<;





namespace enumerations{
ostream& operator<<(ostream&os, const Pressure& p){

    switch(p){
        case Pressure::lo:
            os << "Low" << " ";
          
            break;
        case Pressure::med:
            os << "Medium" << " ";
          
            break;
        case Pressure::hi:
            os << "High" << " ";
          
            break;
        case Pressure::pop:
            os << "Pop" << " ";
           
            break;
    }

    return os;

}

Pressure& operator++(Pressure& p){

    switch(p){
        case Pressure::lo:
            p = Pressure::med;
            break;
        
        case Pressure::med:
            p = Pressure::hi;
            break;
        
        case Pressure::hi:
            p = Pressure::pop;
            break;
        
        case Pressure::pop:
            break;
        
    };

    return p;

}
Pressure& operator--(Pressure& p){
        switch(p){
            case Pressure::hi:
                p = Pressure::med;
                break;
            
            case Pressure::med:
                p = Pressure::lo;
                break;
            
            case Pressure::lo:
                break;
            
            case Pressure::pop:
                break;

        
    };

    return p;

}
Weekday operator++(Weekday& wkdy, int){

     switch(wkdy){
        case Weekday::mon:
            wkdy = Weekday::tue;
          
             return Weekday::mon;
        case Weekday::tue:
            wkdy = Weekday::wed;
          
             return Weekday::tue;
        case Weekday::wed:
             wkdy = Weekday::thu;
          
            return Weekday::wed;
        case Weekday::thu:
             wkdy = Weekday::fri;
           
            return Weekday::thu;
        case Weekday::fri:
             wkdy = Weekday::sat;
           
             return Weekday::fri;
        case Weekday::sat:
            wkdy = Weekday::sun;
          
             return Weekday::sat;
        case Weekday::sun:
            wkdy = Weekday::mon;
             return Weekday::sun;
           
    }
    return wkdy;

}


ostream& operator<<(ostream& os, const Weekday& wkdy){

    switch(wkdy){
        case Weekday::mon:
            os << "Monday" << " ";
          
            break;
        case Weekday::tue:
            os << "Tuesday" << " ";
          
            break;
        case Weekday::wed:
            os << "Wednesday" << " ";
          
            break;
        case Weekday::thu:
            os << "Thursday" << " ";
           
            break;
        case Weekday::fri:
            os << "Friday" << " ";
           
            break;
        case Weekday::sat:
            os << "Saturday" << " ";
          
            break;
        case Weekday::sun:
            os << "Sunday" << " ";
            break;
           
    }

    return os;
}



Weekday operator--(Weekday& wkdy, int){


     switch(wkdy){
        case Weekday::mon:
            wkdy = Weekday::sun;

            return Weekday::mon;
          
           
        case Weekday::tue:
            wkdy = Weekday::mon;
          
            return Weekday::tue;
        case Weekday::wed:
             wkdy = Weekday::tue;
          
            return Weekday::wed;
        case Weekday::thu:
             wkdy = Weekday::wed;
           
            return Weekday::thu;
        case Weekday::fri:
             wkdy = Weekday::thu;
           
             return Weekday::fri;
        case Weekday::sat:
            wkdy = Weekday::fri;
          
            return Weekday::sat;
        case Weekday::sun:
            wkdy = Weekday::sat;
             return Weekday::sun;
           
    }

    return wkdy;

}
}




// int main(int argc, char *argv[]){

  

//     Pressure p = Pressure::lo;
//     Pressure p1 = Pressure::med;
//     Weekday w1 = Weekday::fri;
//     Weekday w2 = Weekday::mon;

//     // cout << (p < p1);
//     // cout << '\n';
//     // cout << (w < w1);

//     set <Weekday> s1;
//     set <Weekday> s2;

//     s1.insert(w1);
//     s1.insert(Weekday::tue);
//     s2.insert(w2);
//     s2.insert(Weekday::tue);

//    set<Weekday>::iterator itr;

//     // for(itr = s1.begin(); itr != s1.end(); itr++){
//     //     cout << *itr;
//     // }

//     // cout << '\n';

//     //  for(itr = s2.begin(); itr != s2.end(); itr++){
//     //     cout << *itr;
//     // }
 

//     set <Weekday> s3;
    
//     set_intersection(s1.begin(),s1.end(), s2.begin(), s2.end(), inserter(s3, s3.end()));


//     // for(auto itr = s3.begin(); itr != s3.end(); itr++){
//     //     cout << *itr;
//     // };


//     set<Weekday> s4;


//                 set_union(s1.begin(), s1.end(),
//                    s2.begin(), s2.end(),
//                    inserter(s4, s4.end()));

//  for(auto itr = s4.begin(); itr != s4.end(); itr++){
//         cout << *itr;
//     };

//     return 0;
// }


