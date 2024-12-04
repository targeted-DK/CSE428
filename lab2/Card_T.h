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

template<typename S, typename R>
bool operator<(const S& lhs, const S& rhs);

template<typename S, typename R>
bool operator<(const R& lhs, const R& rhs);

template<typename S, typename R>
bool compare_rank (const Card<S,R>& firstCard, const Card<S,R>& secondCard);

template<typename S, typename R>
bool compare_suit (const Card<S,R>& firstCard, const Card<S,R>& secondCard);

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "Card_T.cpp"
#endif
