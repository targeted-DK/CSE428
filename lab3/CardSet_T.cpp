// CardSet_T.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// CardSet Template class source file
#include "CardSet_T.h"
#include <stdexcept>
#include <algorithm>
#include <utility>
#include <functional>



using namespace std;

template <typename S, typename R>
typename vector<Card<S, R>>::iterator CardSet<S, R>::begin() {
        return this->cards.begin();
    }

template <typename S, typename R>
typename vector<Card<S, R>>::iterator CardSet<S, R>::end() {
        return this->cards.end();
}

/** 
 * prints entire CardSet to the command line
 * @param os ostream object
 * @param size 
 */
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

/** 
 * pops a card from the CardSet
 * @return Card<S,R>
 */
template <typename S, typename R>
Card<S, R> CardSet<S, R>::pop()
{

    Card<S, R> popped_card = this->cards.back();
    this->cards.pop_back();

    return popped_card;
}

/** 
 * moves the last card from card_set to the this object's card_set
 * @param card_set object to get card from
 * @return CardSet<S,R>
 */
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

/** 
 * get vector of Cards from CardSet
 * @return a vector of Card<S,R>
 */
template <typename S, typename R>
vector<Card<S, R>> &CardSet<S, R>::getCards()
{
    return this->cards;
}

/** 
 * checks if CardSet is empty
 * @return a boolean value whether the CardSet is empty
 */
template <typename S, typename R>
bool CardSet<S, R>::is_empty()
{

    return this->cards.empty();
}


/** 
 * sorts CardSet by R
 * @return void
 */
template <typename S, typename R>
 void  CardSet<S, R>::sortByRank() {
        std::sort(this->cards.begin(), this->cards.end(), compare_rank<S, R>);
    }

/** 
 * sorts CardSet by S
 * @return void
 */
template <typename S, typename R>
    void  CardSet<S, R>::sortBySuit() {
        std::sort(this->cards.begin(), this->cards.end(), compare_suit<S, R>);
    }

/** 
 * collects all the cards from given card_set
 * @param card_set card set to collect cards from
 * @return void
 */
template <typename S, typename R>
void CardSet<S, R>::collect(CardSet<S, R> &card_set) {
   
    //#10. You should consider using a std::back_inserter,
    move(card_set.cards.begin(), card_set.cards.end(), std::back_inserter(this->cards));
    card_set.cards.clear();
}

/** 
 * collects cards based on predicate
 * @param deck deck to check for cards
 * @param predicate predicate for checking cards
 * @return void
 */
template <typename S, typename R>
void CardSet<S, R>::collect_if(CardSet<S,R> &deck, function<bool(Card<S, R>&)> predicate){

    //#11. use the std::copy_if function to copy any cards that match the predicate 
    //reference: https://en.cppreference.com/w/cpp/algorithm/copy
    copy_if(deck.begin(), deck.end(), std::back_inserter(this->cards), predicate);

    //#11.  use the std::remove_if function to remove those cards (which we just copied) from CardSet on which collect_if was called.
    //reference: https://en.cppreference.com/w/cpp/algorithm/remove
    auto past_end_pointer = remove_if(deck.begin(), deck.end(), predicate);

    //#11. to remove the undefined entries and redefine the end of the vector.
    //reference: https://en.cppreference.com/w/cpp/container/vector/erase
    deck.getCards().erase(past_end_pointer, deck.end());
}

/** 
 * requests a card of rank R from another player
 * @param another_card_set another player's cardset
 * @param rank rank of requested card
 * @return a boolean value whether the card is successfully transferred from another player to current player
 */
template <typename S, typename R>
bool CardSet<S, R>::request(CardSet<S,R> &another_card_set, R rank){


    bool isCardFound = false;
    auto it = another_card_set.cards.begin();
    while (it != another_card_set.cards.end()) {
      
        if (it->rank == rank) {
           
            this->cards.push_back(std::move(*it));
           
            another_card_set.cards.erase(it);
            isCardFound = true;
            break;
        } else {
            
            ++it;
        }
    }
    return isCardFound;
}



