// Deck_T.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// Deck Class source file that publicly inherits CardSet base class template
#include "Deck_T.h"
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

#define START_COUNT 0

template <typename S, typename R>
void Deck<S, R>::shuffle()
{

    // https://stackoverflow.com/questions/38367976/do-stdrandom-device-and-stdmt19937-follow-an-uniform-distribution
    random_device rd;
    mt19937 g(rd());

    std::shuffle(CardSet<S, R>::cards.begin(), CardSet<S, R>::cards.end(), g);
}

template <typename S, typename R>
void Deck<S, R>::collect(CardSet<S, R> &card_set)
{
   
        while(!card_set.is_empty()){
            card_set >> *this;
        }
           

    return;
}
