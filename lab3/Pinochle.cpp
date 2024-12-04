//Pinochle.cpp
//Author : Donggyu Kim, donggyukim@wustl.edu
//Source file for Pinochle class
#include "Pinochle.h"


using namespace std;


   Pinochle::Pinochle(){
     for(Suit i = Suit::clubs; i < Suit::undefined; ++i){
           for(PinochleRank j = PinochleRank::nine; j < PinochleRank::undefined; ++j){
                cards.push_back(Card<Suit, PinochleRank>(i,j));
                cards.push_back(Card<Suit, PinochleRank>(i,j));

           }
        }
        
   };


PinochleRank &operator++(PinochleRank& pinochleRank)
{

   switch (pinochleRank)
   {
   case PinochleRank::nine:
      pinochleRank = PinochleRank::jack;
      break;

   case PinochleRank::jack:
      pinochleRank = PinochleRank::queen;
      break;

   case PinochleRank::queen:
      pinochleRank = PinochleRank::king;
      break;

   case PinochleRank::king:
      pinochleRank = PinochleRank::ten;
      break;

   case PinochleRank::ten:
      pinochleRank = PinochleRank::ace;
      break;

   case PinochleRank::ace:
      pinochleRank = PinochleRank::undefined;
      break;
   
   case PinochleRank::undefined:
         break;
   };


   return pinochleRank;
};

//Design Implementation : For the readibility of Cards, I simplified each card with numbers and single letters.
ostream &operator<<(ostream &os, const PinochleRank &pinochleRank)
{

   switch (pinochleRank)
   {
   case PinochleRank::nine:
      os << "9"
         << " ";

      break;
   case PinochleRank::jack:
      os << "J"
         << " ";

      break;
   case PinochleRank::queen:
      os << "Q"
         << " ";

      break;
   case PinochleRank::king:
      os << "K"
         << " ";

      break;
   case PinochleRank::ten: 
      os << "10"
         << " ";

      break;
   case PinochleRank::ace:
      os << "A"
         << " ";

      break;
   case PinochleRank::undefined:
      os << "?"
         << " ";
      break;
   }


   return os;
}
