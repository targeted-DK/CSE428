//Card_T.cpp
//Author : Donggyu Kim, donggyukim@wustl.edu
//Source file for Card_T Template
#include "Card_T.h"
#include <iostream>


//Design Implementation : Card's suit and rank are printed next to each other, without any spaces, for readibility.
template<typename S, typename R>
ostream& operator<<(ostream& os, const Card<S, R>& card){

    os << card.suit;
    os << "";
    os << card.rank;
    
    return os;
}

template<typename S, typename R>
bool compare_rank (const Card<S,R>& firstCard, const Card<S,R>& secondCard){

    if( static_cast<int>(firstCard.rank) <  static_cast<int>(secondCard.rank)){
        return true;
    } else if( static_cast<int>(firstCard.rank) ==  static_cast<int>(secondCard.rank) &&  static_cast<int>(firstCard.suit) <  static_cast<int>(secondCard.suit)){
        return true;
    }

    return false;
}

template<typename S, typename R>
bool compare_suit (const Card<S,R>& firstCard, const Card<S,R>& secondCard){
    
    if( static_cast<int>(firstCard.suit) <  static_cast<int>(secondCard.suit)){
        return true;
    } else if(static_cast<int>(firstCard.suit) == static_cast<int>(secondCard.suit) && static_cast<int>(firstCard.rank) < static_cast<int>(secondCard.rank)){
       return true;
    }

    return false;
}

