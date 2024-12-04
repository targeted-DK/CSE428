1. Donggyu Kim (437008), donggyukim@wustl.edu, lab2

In your readme file, make sure that your names, e-mail addresses, and the lab number (lab 2) are at the top of the file, 
and that you've documented whether you ran into any errors or warnings while developing your solution (and if so what they were)
 and what the executable program did for each of the trials you ran. Be sure to save your changes to your readme file and your Makefile, 
 as well as those to your source and header files, before uploading your solution.


2. Major errors:
1) Implementation of a pointer to the class' protected vector data member
I forgot to save error message I had when I was implementing a pointer ot the class' protected data member.

Basically the issue was the syntax issue, espeically where to play * and & when using the pointer below to point towards a class' protected data member.
std::vector<Card<S,R>> CardSet<S,R>::*CardSet<S,R>::get_cards_pointer(){
        return &CardSet<S,R>::cards;
}
I was very confused with the locations of & and *, so it took me awhile to figure out correct usage of reference and pointer symbol for defining this function.


2) Not using static_cast<int> but rather directly comparing rank and suit.
I had issues with correctly comparing right element (rank and suit), and the only way I could solve it was to use static_cast<int>, by converting enum values 
into int. This was especially useful in my design implementation because I created nested vectors to imitate 2d array to store counts of
suits and rank in pinochle game. 

3) Design issues
Rather than programmical error, I spent more time on design implementation, especially creating helper functions for operator< override for two Player objects.
I ended up choosing semi-recursive approach, that whenever a tie is found, each tiebreak function calls next lower tie breaker function. For example,
bool compare_pair(vector<Card<Suit, TexasholdemRank>> &lhs_cards, vector<Card<Suit, TexasholdemRank>> &rhs_cards)
{
   ...
           return compare_xhigh(lhs_cards_without_pair, rhs_cards_without_pair);
   ...
}

Like the code above, when both players being compared of their hands has a pair with same rank, the function would call next lower compare function to decide on tie breaker for
between players' hands. This was applied to other compare functions as well. If they could not decide order of hands based on given conditions, the function would
return a call to a lower tie-breaker helper function.






// PinochleGame.cpp: In function ‘std::ostream& operator<<(std::ostream&, const PinochleMelds&)’:
// PinochleGame.cpp:301:46: error: array subscript is not an integer
//      os << meld_str << " " << meld_points[meld];
//                                               ^
// In file included from CardSet_T.h:37,
//                  from Pinochle.h:4,
//                  from PinochleGame.h:



// template <typename S, typename R>
// CardSet<S,R>::CardSet(const CardSet<S,R>& another_cardSet){

//     //push_back() takes in a const object and makes a copy before adding the copied object to the vector.
//     for(const Card<S,R> card : another_cardSet->getCards()){
//         this->getCards().push_back(card);
//     };
// }
// PinochleGame.cpp:122:67:   required from here
// CardSet_T.cpp:80:32: error: base operand of ‘->’ has non-pointer type ‘const CardSet<Suit, PinochleRank>’
//      for(const Card<S,R> card : another_cardSet->getCards()){
                          


vtable issue -> some files were not probably included in Makefile when I was transferring data from lab 1






Design Implementation:
//                | Nine | Jack | Queen | King | Ten | Ace | Undefined |
// ---------------------------------------------------------------------
// Clubs          |      |      |       |      |     |     |           |
// ---------------------------------------------------------------------
// Diamonds       |      |      |       |      |     |     |           |
// ---------------------------------------------------------------------
// Hearts         |      |      |       |      |     |     |           |
// ---------------------------------------------------------------------
// Spades         |      |      |       |      |     |     |           |
// ---------------------------------------------------------------------
// Undefined      |      |      |       |      |     |     |           |

//                | Two  | Three| Four | Five | Six  | Seven| Eight | Nine | Ten  | Jack | Queen | King | Ace  | Undefined |
// -----------------------------------------------------------------------------------------------------------------------
// Clubs          |      |      |      |      |      |      |       |      |      |      |       |      |      |           |
// -----------------------------------------------------------------------------------------------------------------------
// Diamonds       |      |      |      |      |      |      |       |      |      |      |       |      |      |           |
// -----------------------------------------------------------------------------------------------------------------------
// Hearts         |      |      |      |      |      |      |       |      |      |      |       |      |      |           |
// -----------------------------------------------------------------------------------------------------------------------
// Spades         |      |      |      |      |      |      |       |      |      |      |       |      |      |           |
// -----------------------------------------------------------------------------------------------------------------------
// Undefined      |      |      |      |      |      |      |       |      |      |      |       |      |      |           |
// -----------------------------------------------------------------------------------------------------------------------
