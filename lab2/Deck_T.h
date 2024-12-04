//Deck_T.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//Deck Template Class that drives from CardSet Template Class
#include "CardSet_T.h"
#include <iostream>

#pragma once

using namespace std;

template <typename S, typename R>
class Deck : public CardSet < S, R > {

    public : 
        void shuffle();
        void collect(CardSet<S,R> &card_set);

};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "Deck_T.cpp"
#endif


