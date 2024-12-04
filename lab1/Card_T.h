//Card_T.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//Header file for Card_T Template
#include <iostream>
#include <string>
#include "header.h"

#pragma once


template <typename S, typename R>
struct Card {
    
    public:
        S suit;
        R rank;
        Card(S _suit, R _rank): suit(_suit), rank(_rank){};
};

template<typename S, typename R>
std::ostream& operator<<(std::ostream& os, const Card<S, R>& card);

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "Card_T.cpp"
#endif


