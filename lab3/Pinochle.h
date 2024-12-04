//Pinochle.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//Header file for Pinochle Class
#include "CardSet_T.h"
#include "Deck_T.h"
#include "Card_T.h"
#include "header.h"


#pragma once

enum class PinochleRank {nine, jack, queen, king, ten, ace, undefined};

class Pinochle : public Deck<Suit, PinochleRank> {  
    public : 
        Pinochle();
      
};

PinochleRank& operator++(PinochleRank& pinochleRank);
ostream& operator<<(ostream& os, const PinochleRank& pinochleRank);
