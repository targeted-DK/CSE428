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

template <typename S, typename R>
CardSet<S,R>::CardSet(const CardSet<S,R>& another_cardSet){
    
    for (const Card<S, R>& card : another_cardSet.cards) {
        this->cards.push_back(card);
    }
}



template <typename S, typename R>
 void  CardSet<S, R>::sortByRank() {
        std::sort(this->cards.begin(), this->cards.end(), compare_rank<S, R>);
    }

template <typename S, typename R>
    void  CardSet<S, R>::sortBySuit() {
        std::sort(this->cards.begin(), this->cards.end(), compare_suit<S, R>);
    }


template <typename S, typename R>
void CardSet<S, R>::collect(CardSet<S, R> &card_set) {
   
    //#10. You should consider using a std::back_inserter,
    move(card_set.cards.begin(), card_set.cards.end(), std::back_inserter(this->cards));
    card_set.cards.clear();
}

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

template <typename S, typename R>
bool CardSet<S, R>::request(CardSet<S,R> &another_card_set, R rank){

    //#12.The method should use the std::find function to find a card in the provided CardSet matching the provided rank.
    //Design Implementation : find() checks if provided parameter R rank exactly matches with a value being compared but this should not work because CardSet has Cards of <S,R>.
    //so instead, I am using find_if, to which I can provide rank as a predicate to check if each Card in CardSet has same rank
    auto card_found = find_if(another_card_set.begin(), another_card_set.end(), 
                          [rank](const Card<S, R>& card) { return card.rank == rank; });


  
    if(card_found != another_card_set.end()){
        while(card_found != another_card_set.end()){
            if(card_found->rank == rank){
                this->cards.push_back(move(*(card_found)));
                another_card_set.cards.erase(card_found);
                return true;
            }
            card_found++;
        }
    }

    return false;
}



