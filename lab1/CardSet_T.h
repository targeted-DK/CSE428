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

protected:
    std::vector<Card<S, R>> cards;
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "CardSet_T.cpp"
#endif
