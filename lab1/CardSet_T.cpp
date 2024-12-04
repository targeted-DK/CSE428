// CardSet_T.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// CardSet Template class source file
#include "CardSet_T.h"
#include <stdexcept>
using namespace std;

//Design Implementation : Each card prints out sequentially with a space inbetween each cards, and breaks a lines after some user input value number of cards are printed.
template <typename S, typename R>
void CardSet<S, R>::print(ostream &os, size_t size)
{

    typename vector<Card<S, R>>::iterator iter;

    size_t counter = 0;

    for (iter = this->cards.begin(); iter < this->cards.end(); iter++)
    {

        os << *iter << " ";
        counter++;
        if (counter == size)
        {
            os << "\n";
            counter = 0;
        }
    }
};

template <typename S, typename R>
Card<S, R> CardSet<S, R>::pop()
{

    Card<S, R> popped_card = this->cards.back();
    this->cards.pop_back();

    return popped_card;
}

template <typename S, typename R>
CardSet<S, R> &CardSet<S, R>::operator>>(CardSet<S, R> &card_set)
{
    if (this->is_empty())
    {
        throw runtime_error("Card set is empty");
    }
    card_set.cards.push_back(this->getCards().back());
    this->getCards().pop_back();

    return *this;
}
template <typename S, typename R>
vector<Card<S, R>> &CardSet<S, R>::getCards()
{

    return this->cards;
}

template <typename S, typename R>
bool CardSet<S, R>::is_empty()
{

    return this->cards.empty();
}
