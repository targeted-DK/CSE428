#include <iostream>
#include "header.h"

using namespace std;

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

// Weekday operator++(Weekday& wkdy, int){

//      switch(wkdy){
//         case Weekday::mon:
//             wkdy = Weekday::tue;
          
//              return Weekday::mon;
//         case Weekday::tue:
//             wkdy = Weekday::wed;
          
//              return Weekday::tue;
//         case Weekday::wed:
//              wkdy = Weekday::thu;
          
//             return Weekday::wed;
//         case Weekday::thu:
//              wkdy = Weekday::fri;
           
//             return Weekday::thu;
//         case Weekday::fri:
//              wkdy = Weekday::sat;
           
//              return Weekday::fri;
//         case Weekday::sat:
//             wkdy = Weekday::sun;
          
//              return Weekday::sat;
//         case Weekday::sun:
//             wkdy = Weekday::mon;
//              return Weekday::sun;
           
//     }
//     return wkdy;

// }
Weekday operator++(Weekday& wkdy, int){

    Weekday original = wkdy;  

    switch(wkdy){
        case Weekday::mon:
            wkdy = Weekday::tue;
            break;
        case Weekday::tue:
            wkdy = Weekday::wed;
            break;
        case Weekday::wed:
            wkdy = Weekday::thu;
            break;
        case Weekday::thu:
            wkdy = Weekday::fri;
            break;
        case Weekday::fri:
            wkdy = Weekday::sat;
            break;
        case Weekday::sat:
            wkdy = Weekday::sun;
            break;
        case Weekday::sun:
            wkdy = Weekday::mon;
            break;
    }
    return original;  // Return the original value
}

// Weekday operator--(Weekday& wkdy, int){

//     Weekday original = wkdy;

//      switch(wkdy){
//         case Weekday::mon:
//             wkdy = Weekday::sun;

//             return Weekday::mon;
          
           
//         case Weekday::tue:
//             wkdy = Weekday::mon;
          
//             return Weekday::tue;
//         case Weekday::wed:
//              wkdy = Weekday::tue;
          
//             return Weekday::wed;
//         case Weekday::thu:
//              wkdy = Weekday::wed;
           
//             return Weekday::thu;
//         case Weekday::fri:
//              wkdy = Weekday::thu;
           
//              return Weekday::fri;
//         case Weekday::sat:
//             wkdy = Weekday::fri;
          
//             return Weekday::sat;
//         case Weekday::sun:
//             wkdy = Weekday::sat;
//              return Weekday::sun;
           
//     }

//     return wkdy;

// }

Weekday operator--(Weekday& wkdy, int){

    Weekday original = wkdy;  

    switch(wkdy){
        case Weekday::mon:
            wkdy = Weekday::sun;  
            break;
        case Weekday::tue:
            wkdy = Weekday::mon;
            break;
        case Weekday::wed:
            wkdy = Weekday::tue;
            break;
        case Weekday::thu:
            wkdy = Weekday::wed;
            break;
        case Weekday::fri:
            wkdy = Weekday::thu;
            break;
        case Weekday::sat:
            wkdy = Weekday::fri;
            break;
        case Weekday::sun:
            wkdy = Weekday::sat;
            break;
    }
    return original;  
}

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



int main(){


//    Weekday test = Weekday::mon;

    // cout << test << endl;

    // return 0;

    // for(auto i = 0; i < 3; i++){
    //     cout << p;
    //     ++p;
    // }


    // Weekday test = Weekday::mon;

    // while(test != Weekday::tue){        
    //     cout << test--;
    // }
    // cout<<test;
    // Pressure p = Pressure::lo;
    // cout << p;
  
    Pressure p = Pressure::lo;
    for(auto i = 0; i < 3; i++){
        cout << p;
        ++p;
    }
  


    return 0;
}


