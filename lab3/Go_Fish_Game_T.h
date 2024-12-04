// Go_Fish_Game_T.h
// Author : Donggyu Kim, donggyukim@wustl.edu
// Go Fish Game Template header file for different deck types
#include "header.h"
#include "Texasholdem.h"
#include "Card_T.h"
#include "Game.h"
#include "Deck_T.h"
#include "CardSet_T.h"
#include "Texasholdem.h"
#include "Uno.h"
#include "Pinochle.h"


#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>


// #16.Create a new C++ source and header file and in them declare and define a class template called GoFishGame, with 3 type parameters:
template <typename suit_type = Suit, typename rank_type = TexasholdemRank, typename deck_type = Texasholdem>
class GoFishGame : public Game{
    public:

        //#16.Public members should include a constructor, a virtual destructor, and a virtual implementation of play()
        GoFishGame(int num_players, const char* player_names[]);
        virtual ~GoFishGame();
        virtual int play();

    
    protected:
        deck_type go_fish_game_deck;
        std::vector<CardSet<suit_type, rank_type>> player_hands;
        std::vector<CardSet<suit_type, rank_type>> books;
        virtual void deal();
        //#18. Add a collect_books method 
        bool collect_books(int player_number, bool four_kind_exists );
        //#19. protected turn method 
        

    //Protected members should include the deck of cards (with a type matching the one provided by the class template's deck type parameter),
    //  a vector of CardSet for the players' hands, 
    //  a vector of CardSet for the books each of the players has made, 
    //  and a virtual deal() method.


};

bool hasFourCards (int i);