// CardSet_T.h
// Author : Donggyu Kim, donggyukim@wustl.edu
// CardSet Template class header file
#include "Card_T.h"
#include <iostream>
#include <vector>

#pragma once

template <typename S, typename R>
class CardSet
{

public:
    void print(std::ostream &os, size_t size);
    CardSet<S, R> &operator>>(CardSet<S, R> &card_set);
    bool is_empty();
    Card<S, R> pop();
    std::vector<Card<S, R>> &getCards();

    //#8 : To explicitly synthesize a default constructor
    CardSet() = default;
    CardSet(const CardSet<S,R>& another_cardSet);

    //#9 : add a static public member function
    static std::vector<Card<S,R>> CardSet<S,R>::*get_cards_pointer();
    
    //#12 : Created helper functions that sort new copied CardSet
    void sortByRank();
    void sortBySuit();

protected:
    std::vector<Card<S, R>> cards;
};




#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "CardSet_T.cpp"
#endif
