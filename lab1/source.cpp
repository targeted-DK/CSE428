//source.cpp
//Author : Donggyu Kim, donggyukim@wustl.edu
//Defines operaters for Suit enum
#include "header.h"
#include <iostream>

using namespace std;


ostream& operator<<(ostream& os, const Suit& cardsuit){

   if(cardsuit == Suit::clubs){
    os << 'C';
   } else if(cardsuit == Suit::diamonds){
    os << 'D';
   } else if(cardsuit == Suit::hearts){
    os << 'H';
   } else if(cardsuit == Suit::spades){
    os << "S";
   } else if(cardsuit == Suit::undefined) {
    os << "?";
   }
   
    return os;
}

Suit& operator++(Suit& cardsuit){

    switch (cardsuit)
    {
    case Suit::clubs:
        cardsuit = Suit::diamonds;
        break;
    
    case Suit::diamonds:
        cardsuit = Suit::hearts;
        break;
    
    case Suit::hearts:
        cardsuit = Suit::spades;
        break;
    
    case Suit::spades:
        cardsuit = Suit::undefined;
        break;

    case Suit::undefined:
        break;
    }

    return cardsuit;
};