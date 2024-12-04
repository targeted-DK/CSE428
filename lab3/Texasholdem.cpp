// Texasholdem.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// Source file for Texasholdem class
#include "Texasholdem.h"
#include "Card_T.h"
#include "Deck_T.h"
#include "header.h"
#include <iostream>
#include <vector>

using namespace std;

Texasholdem::Texasholdem()
{
   for (Suit i = Suit::clubs; i < Suit::undefined; ++i)
   {
      for (TexasholdemRank j = TexasholdemRank::two; j < TexasholdemRank::undefined; ++j)
      {
         cards.push_back(Card<Suit, TexasholdemRank>(i, j));
      }
   }
}

TexasholdemRank &operator++(TexasholdemRank &texasholdemRank)
{

   switch (texasholdemRank)
   {
   case TexasholdemRank::two:
      texasholdemRank = TexasholdemRank::three;
      break;
   case TexasholdemRank::three:
      texasholdemRank = TexasholdemRank::four;
      break;
   case TexasholdemRank::four:
      texasholdemRank = TexasholdemRank::five;
      break;
   case TexasholdemRank::five:
      texasholdemRank = TexasholdemRank::six;
      break;
   case TexasholdemRank::six:
      texasholdemRank = TexasholdemRank::seven;
      break;
   case TexasholdemRank::seven:
      texasholdemRank = TexasholdemRank::eight;
      break;
   case TexasholdemRank::eight:
      texasholdemRank = TexasholdemRank::nine;
      break;
   case TexasholdemRank::nine:
      texasholdemRank = TexasholdemRank::ten;
      break;
   case TexasholdemRank::ten:
      texasholdemRank = TexasholdemRank::jack;
      break;

   case TexasholdemRank::jack:
      texasholdemRank = TexasholdemRank::queen;
      break;

   case TexasholdemRank::queen:
      texasholdemRank = TexasholdemRank::king;
      break;

   case TexasholdemRank::king:
      texasholdemRank = TexasholdemRank::ace;
      break;

   case TexasholdemRank::ace:
      texasholdemRank = TexasholdemRank::undefined;
      break;

   case TexasholdemRank::undefined:
      break;
   };

   return texasholdemRank;
}

// Design Implementation : For the readibility of Cards, I simplified each card with numbers and single letters.
ostream &operator<<(ostream &os, const TexasholdemRank &texasholdemRank)
{

   switch (texasholdemRank)
   {
   case TexasholdemRank::two:
      os << "2";
      break;
   case TexasholdemRank::three:
      os << "3";
      break;
   case TexasholdemRank::four:
      os << "4";
      break;
   case TexasholdemRank::five:
      os << "5";
      break;
   case TexasholdemRank::six:
      os << "6";
      break;
   case TexasholdemRank::seven:
      os << "7";
      break;
   case TexasholdemRank::eight:
      os << "8";
      break;
   case TexasholdemRank::nine:
      os << "9";
      break;
   case TexasholdemRank::ten:
      os << "10";
      break;
   case TexasholdemRank::jack:
      os << "J";
      break;
   case TexasholdemRank::queen:
      os << "Q";
      break;
   case TexasholdemRank::king:
      os << "K";
      break;

   case TexasholdemRank::ace:
      os << "A";
      break;

   case TexasholdemRank::undefined:
      os << "?";
      break;
   }

   return os;
}