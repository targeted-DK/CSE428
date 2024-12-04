//Card_T.cpp
//Author : Donggyu Kim, donggyukim@wustl.edu
//Source file for Card_T Template
#include "Card_T.h"
#include <iostream>

using namespace std;

//Design Implementation : Card's suit and rank are printed next to each other, without any spaces, for readibility.
template<typename S, typename R>
ostream& operator<<(ostream& os, const Card<S, R>& card){

    os << card.suit;
    os << "";
    os << card.rank;
    
    return os;
}
