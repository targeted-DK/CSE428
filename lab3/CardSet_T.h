// CardSet_T.h
// Author : Donggyu Kim, donggyukim@wustl.edu
// CardSet Template class header file
#include "Card_T.h"
#include <iostream>
#include <vector>
#include <utility>
#include <functional>

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

    
    CardSet() = default;
    CardSet(const CardSet<S,R>& another_cardSet);

    //#7. Replace an accessor:
    typename std::vector<Card<S, R>>::iterator begin();
    typename std::vector<Card<S, R>>::iterator end();
    
    //#8. My code already implementes std::sort() from previous lab.
    void sortByRank();
    void sortBySuit();

    //#9. new typedefs
    typedef Card<S, R> card_type;
    typedef R rank_type;
    typedef S suit_type;
    typedef typename vector<Card<S, R>>::iterator iter;

    //#10. Move the collect method from the Deck class template up into the CardSet class template
    void collect(CardSet<S,R> &card_set);

    //#11. Add a new method to the CardSet class template, called collect_if
    void collect_if(CardSet<S,R> &deck, std::function<bool(Card<S, R>&)> predicate);

    //#12. Add a public method called request to the CardSet class template
    bool request(CardSet<S,R> &another_card_set, R rank);


protected:
    std::vector<Card<S, R>> cards;
};




#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "CardSet_T.cpp"
#endif
