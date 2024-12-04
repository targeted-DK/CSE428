// GoFishGame_T.h
// Author : Donggyu Kim, donggyukim@wustl.edu
// Go Fish Game Template header file for different deck types
#pragma once

#include "header.h"
#include "Game.h"
#include "Texasholdem.h"
#include "Pinochle.h"
#include "Uno.h"
#include "CardSet_T.h"
#include "Deck_T.h"


#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <type_traits>



// #16.Create a new C++ source and header file and in them declare and define a class template called GoFishGame, with 3 type parameters:
template <typename suit_type = Suit, typename rank_type = TexasholdemRank, typename deck_type = Texasholdem>
class GoFishGame : public Game{

    //#17. add a static_assert to check whether the Deck parameter makes use of the provided suit and rank types
    static_assert(std::is_base_of< CardSet<suit_type, rank_type>, deck_type>::value,
                  "deck_type must be derived from CardSet<S, R>");


    public:
        
        //#16.Public members should include a constructor, a virtual destructor, and a virtual implementation of play()
        GoFishGame(int num_players, const char* player_names[]);
        virtual ~GoFishGame() = default;
        virtual int play();
        
    protected:
        deck_type go_fish_game_deck;
        
        std::vector< CardSet<suit_type, rank_type> > player_hands;
        std::vector< CardSet<suit_type, rank_type> > books;
        std::vector<int> player_books_count;
        std::vector<int> lost_players;

        virtual void deal();
        //#18. Add a collect_books method 
        bool collect_books(int player_number);

        //#19. protected turn method 
        bool turn(int player_number);
        int total_player_num;
        

};





#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "GoFishGame_T.cpp"
#endif