//Texasholdem.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//Header file for Texasholdem Class
#include <iostream>
#include <vector>
#include "CardSet_T.h"
#include "Deck_T.h"
#include "Card_T.h"
#include "header.h"

#pragma once

using namespace std;


enum class TexasholdemRank {two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace, undefined};

class Texasholdem : public Deck<Suit, TexasholdemRank>{
  
    public : 
        Texasholdem();


};


TexasholdemRank& operator++(TexasholdemRank& texasholdemRank);
ostream& operator<<(ostream& os, const TexasholdemRank& texasholdemRank);

