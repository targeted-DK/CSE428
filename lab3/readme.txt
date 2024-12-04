1. Donggyu Kim(437008), donggyukim@wustl.edu, lab3

2.
Errors and Warnings encountered :

#1: Wrong instantiation of 'input_rank' variable caused wrong comparison
In file included from ./GoFishGame_T.h:69:
./GoFishGame_T.cpp:190:32: error: invalid operands to binary expression ('TexasholdemRank' and 'PinochleRank')
            while(!(input_rank == PinochleRank::nine || input_rank == PinochleRank::jack || input_rank == PinochleRank::queen ||

#2: Incorrect template specialization caused bit of issues with recognizing identifiers
./GoFishGame_T.cpp:289:5: error: use of undeclared identifier 'game_deck'
    game_deck.shuffle();
    ^
./GoFishGame_T.cpp:295:18: error: use of undeclared identifier 'game_deck'
            if (!game_deck.is_empty()) {
                 ^
./GoFishGame_T.cpp:296:17: error: use of undeclared identifier 'game_deck'
                game_deck >> player_hand;

#3: parameterization issues : I was keep trying to use Suit, instead of Color to create game pointer using UnoDeck
./GoFishGame_T.h:28:5: error: static assertion failed due to requirement 'std::is_base_of<CardSet<Suit, UnoRank>, Uno>::value': deck_type must be derived from CardSet<S, R>
    static_assert(std::is_base_of< CardSet<suit_type, rank_type>, deck_type>::value,

#4: Segmentation fault : The game pointer was not being properly created, thereby causing segmentation fault error. This was related to trying to access elements outside of vector when
creating a deck used for GoFishGame. 

#5: Command line issues : A bit of overcomplication of how command line inputs were dealt with caused bit of trouble - simplification is always the best. 

#6: Code issues: below code in CardSet_T.cpp was causing issues with getting card from another deck. 
// template <typename S, typename R>
// CardSet<S,R>::CardSet(const CardSet<S,R>& another_cardSet){
    
//     for (const Card<S, R>& card : another_cardSet.cards) {
//         this->cards.push_back(card);
//     }
// }

#6=7: Other trivial errors :
These were related to wrong comparison of ranks, typos. 


3. Debugging issues:
#1: The index player and index of books stored were different which caused me a bit of trouble understanding why each player was printing out someone else's book.

#2: issues with transferring a card from a player to a player
There was an issue with transferring a card from a player to another player, creating duplicate cards in the deck. This was hard to figure out because game seemed to run fine,
until I had to print every single cards in deck/player hands to find out possibility of duplicates

#3: There were some design issues related to edge cases, such as :
    1) Game over conditions
    2) Skpping eliminated players 
    3) A lot of 'return false' and 'return true' made myself hard to understand the flow of the game

#4: There x2 players created(vector size was a double for player_hand) and cards in the deck were much less that what it had to be after distributing cards to players.


4. Design Implementations
#1. There is a board that prints out a Hand, contents of books and number of books collected so that the current player knows what's going on
#2. Every turn, Game log prints out information regarding how a card to transferred from another player to a player
#3. Every turn, Game log prints out information regarding which card is draw from the deck
#4. Every turn, Game log prints out number of cards left in the deck
#5. If a player is eliminated, than players can no longer choose eliminated player's index, and eliminated player's turn is automatically skipped.


5.
Trials Ran(these were run with less cards to fasten debugging process)
 
Case 1: Two players with 7 cards each using Pinochle deck, and one player has no more cards on his hands
TLDR; Game ends when there is one play remaning.

./lab3 GoFish Pinochle a b    
--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : S9  D10  HA  C10  HA  DA  S9  
Books Collected : 0

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : D9  S10  S10  CA  CQ  CA  C9  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player a(number 0)'s turn. 

Enter the player number from 0 to 1 to ask cards from :1

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
0

[ Game Log ]
Player a(number 0) collected rank of 9  card from player b

--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : S9  D10  HA  C10  HA  DA  S9  D9  
Books Collected : 0

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : S10  S10  CA  CQ  CA  C9  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player a(number 0)'s turn. 

Enter the player number from 0 to 1 to ask cards from :1

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
0

[ Game Log ]
Player a(number 0) collected rank of 9  card from player b

--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : D10  HA  C10  HA  DA  
Books Collected : 1
9  : S9  S9  D9  C9  

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : S10  S10  CA  CQ  CA  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player a(number 0)'s turn. 

Enter the player number from 0 to 1 to ask cards from :1

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
4

[ Game Log ]
Player a(number 0) collected rank of 10  card from player b

--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : D10  HA  C10  HA  DA  S10  
Books Collected : 1
9  : S9  S9  D9  C9  

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : S10  CA  CQ  CA  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player a(number 0)'s turn. 

Enter the player number from 0 to 1 to ask cards from :1

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
4

[ Game Log ]
Player a(number 0) collected rank of 10  card from player b

--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : HA  HA  DA  
Books Collected : 2
9  : S9  S9  D9  C9  
10  : D10  C10  S10  S10  

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : CA  CQ  CA  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player a(number 0)'s turn. 

Enter the player number from 0 to 1 to ask cards from :1

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
5

[ Game Log ]
Player a(number 0) collected rank of A  card from player b

--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : 
Books Collected : 3
9  : S9  S9  D9  C9  
10  : D10  C10  S10  S10  
A  : HA  HA  DA  CA  

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : CQ  CA  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player a(number 0)'s turn. 

Enter the player number from 0 to 1 to ask cards from :1

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
5

[ Game Log ]
Player a(number 0) called Go Fish!
Player a(number 0) draws a card CK  from the deck
Cards left in the Deck : 19 cards.

--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : CK  
Books Collected : 3
9  : S9  S9  D9  C9  
10  : D10  C10  S10  S10  
A  : HA  HA  DA  CA  

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : CQ  CA  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player b(number 1)'s turn. 

Enter the player number from 0 to 1 to ask cards from :1

[ Game Log ]
You cannot ask yourself for cards

Enter the player number to ask from 0 to 1 :1

[ Game Log ]
You cannot ask yourself for cards

Enter the player number to ask from 0 to 1 :0

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
1

[ Game Log ]
Player b(number 1) called Go Fish!
Player b(number 1) draws a card SK  from the deck
Cards left in the Deck : 18 cards.

Round 0 has ended. 
-------------------------------------------------------- 
--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : CK  
Books Collected : 3
9  : S9  S9  D9  C9  
10  : D10  C10  S10  S10  
A  : HA  HA  DA  CA  

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : CQ  CA  SK  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player a(number 0)'s turn. 

Enter the player number from 0 to 1 to ask cards from :1

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
0

[ Game Log ]
Player a(number 0) called Go Fish!
Player a(number 0) draws a card DJ  from the deck
Cards left in the Deck : 17 cards.

--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : CK  DJ  
Books Collected : 3
9  : S9  S9  D9  C9  
10  : D10  C10  S10  S10  
A  : HA  HA  DA  CA  

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : CQ  CA  SK  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player b(number 1)'s turn. 

Enter the player number from 0 to 1 to ask cards from :0

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
1

[ Game Log ]
Player b(number 1) collected rank of J  card from player a

--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : CK  
Books Collected : 3
9  : S9  S9  D9  C9  
10  : D10  C10  S10  S10  
A  : HA  HA  DA  CA  

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : CQ  CA  SK  DJ  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player b(number 1)'s turn. 

Enter the player number from 0 to 1 to ask cards from :0

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
3
Player a(number 0) is eliminated from the game!

[ Game Log ]
Player b(number 1) collected rank of K  card from player a

Round 1 has ended. 
-------------------------------------------------------- 
Only one player remains in this game. Game Ends. Calculating final scores...
           RESULT          
===================================
Player a(0) :  collected most books(3 books)
===================================

-------------------------------------------------------- -------------------------------------------------------- -------------------------------------------------------- -------------------------------------------------------- -------------------------------------------------------- 

Case 2: Five players with 5 cards each using Pinochle deck, game ends when there is no more cards in the deck
TLDR; Game ends when there are no more cards to draw from the deck.

./lab3 GoFish Pinochle a b c d e  
--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : SK  D9  C10  SQ  DK  
Books Collected : 0

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : DK  DQ  H9  CJ  D9  
Books Collected : 0

-------------------------------------------------------- 

Player c(number 2)'s hands and books : 
Hand : HQ  HA  CJ  SQ  CQ  
Books Collected : 0

-------------------------------------------------------- 

Player d(number 3)'s hands and books : 
Hand : S9  S10  DJ  H10  SK  
Books Collected : 0

-------------------------------------------------------- 

Player e(number 4)'s hands and books : 
Hand : D10  HQ  S10  HA  H10  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player a(number 0)'s turn. 

Enter the player number from 0 to 4 to ask cards from :1

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
4
--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : SK  D9  C10  SQ  DK  
Books Collected : 0

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : DK  DQ  H9  CJ  D9  
Books Collected : 0

-------------------------------------------------------- 

Player c(number 2)'s hands and books : 
Hand : HQ  HA  CJ  SQ  CQ  
Books Collected : 0

-------------------------------------------------------- 

Player d(number 3)'s hands and books : 
Hand : S9  S10  DJ  H10  SK  
Books Collected : 0

-------------------------------------------------------- 

Player e(number 4)'s hands and books : 
Hand : D10  HQ  S10  HA  H10  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player b(number 1)'s turn. 

Enter the player number from 0 to 4 to ask cards from :2

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
0
--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : SK  D9  C10  SQ  DK  
Books Collected : 0

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : DK  DQ  H9  CJ  D9  
Books Collected : 0

-------------------------------------------------------- 

Player c(number 2)'s hands and books : 
Hand : HQ  HA  CJ  SQ  CQ  
Books Collected : 0

-------------------------------------------------------- 

Player d(number 3)'s hands and books : 
Hand : S9  S10  DJ  H10  SK  
Books Collected : 0

-------------------------------------------------------- 

Player e(number 4)'s hands and books : 
Hand : D10  HQ  S10  HA  H10  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player c(number 2)'s turn. 

Enter the player number from 0 to 4 to ask cards from :3

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
5
--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : SK  D9  C10  SQ  DK  
Books Collected : 0

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : DK  DQ  H9  CJ  D9  
Books Collected : 0

-------------------------------------------------------- 

Player c(number 2)'s hands and books : 
Hand : HQ  HA  CJ  SQ  CQ  
Books Collected : 0

-------------------------------------------------------- 

Player d(number 3)'s hands and books : 
Hand : S9  S10  DJ  H10  SK  
Books Collected : 0

-------------------------------------------------------- 

Player e(number 4)'s hands and books : 
Hand : D10  HQ  S10  HA  H10  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player d(number 3)'s turn. 

Enter the player number from 0 to 4 to ask cards from :4

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
0
--------Current hands and books of player name(number #)-------- 

Player a(number 0)'s hands and books : 
Hand : SK  D9  C10  SQ  DK  
Books Collected : 0

-------------------------------------------------------- 

Player b(number 1)'s hands and books : 
Hand : DK  DQ  H9  CJ  D9  
Books Collected : 0

-------------------------------------------------------- 

Player c(number 2)'s hands and books : 
Hand : HQ  HA  CJ  SQ  CQ  
Books Collected : 0

-------------------------------------------------------- 

Player d(number 3)'s hands and books : 
Hand : S9  S10  DJ  H10  SK  
Books Collected : 0

-------------------------------------------------------- 

Player e(number 4)'s hands and books : 
Hand : D10  HQ  S10  HA  H10  
Books Collected : 0

-------------------------------------------------------- 


[ Game Log ]
Player e(number 4)'s turn. 

Enter the player number from 0 to 4 to ask cards from :1

[ Game Log ]
Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask
5
Round 0 has ended. 
-------------------------------------------------------- 
Deck ran out of cards! Game Ends. Calculating final scores...
           RESULT          
===================================
Player a(0) :  collected most books(0 books)
Player b(1) :  collected most books(0 books)
Player c(2) :  collected most books(0 books)
Player d(3) :  collected most books(0 books)
Player e(4) :  collected most books(0 books)
===================================


-------------------------------------------------------- -------------------------------------------------------- -------------------------------------------------------- -------------------------------------------------------- -------------------------------------------------------- 


