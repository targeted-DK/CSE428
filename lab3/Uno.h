// Uno.h
// Author : Donggyu Kim, donggyukim@wustl.edu
// Uno game header file
#include "Deck_T.h"
#include "Card_T.h"
#include "Deck_T.h"

#pragma once
//#13. declare a Color enumeration 
enum class Color {red, blue, green, yellow, black, undefined};


//#14. delcare UnoRank enumeration
enum class UnoRank {zero, one, two, three, four, five, six, seven, eight, nine, skip, reverse, drawtwo, drawfour, wild, blank, undefined};

class Uno : public Deck<Color, UnoRank>{

    public:
        Uno();
};

//#14. UnoRank, Color operators
UnoRank& operator++(UnoRank& unoRank);
ostream& operator<<(ostream& os, const UnoRank& unoRank);

Color& operator++(Color& color);
ostream& operator<<(ostream& os, const Color& color);