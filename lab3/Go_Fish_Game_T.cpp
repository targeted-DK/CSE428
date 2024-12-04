// Go_Fish_Game_T.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// Go Fish Game Template source file for different deck types
#include "Go_Fish_Game_T.h"
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

//#17. Add a collect_books method 
// static_assert()

using namespace std;

template <typename suit_type, typename rank_type, typename deck_type>
GoFishGame<suit_type, rank_type, deck_type>::GoFishGame(int num_players, const char* player_names[]) : Game(num_players, player_names)
{
        //17.The body of the constructor should check that there are at least 4 cards of each rank in the deck, and if not it should throw an exception.
        vector<suit_type, rank_type>::iterator vec_begin = this->go_fish_game_deck.begin();
        vector<suit_type, rank_type>::iterator vec_end = this->go_fish_game_deck_end();
        // this->go_fish_game_deck.
        // Texasholdem::
        // vector<suit_type, rank_type>::iterator vec_begin = this->go_fish_game_deck.begin();
       
        int count_rank_cards[static_cast<int>(rank_type::undefined)];
        vector<suit_type, rank_type>::iterator vec_begin = this->go_fish_game_deck.begin();
        vector<suit_type, rank_type>::iterator vec_end = this->go_fish_game_deck_end();

        for(auto it = go_fish_game_deck.begin(); it < go_fish_game_deck.end(); i++){
              count_rank_cards[static_cast<int>(it->rank)]++;
        }
       
        
        count_if(count_rank_cards, count_rank_cards + static_cast<int>rank_type::undefined, hasFourCards());
        
};
asdads

template <>
GoFishGame<Color, UnoRank, Uno>::GoFishGame(int num_players, const char* player_names[]) : Game(num_players, player_names) {
  
    // Specific initialization for UnoDeck
    if (!isDeckValid()) {
        throw std::invalid_argument("Invalid UnoDeck: not enough cards of each rank.");
    }
    // Additional constructor logic for UnoDeck...
}

// Specialization for PinochleDeck
template <>
GoFishGame<Suit, PinochleRank, Pinochle>::GoFishGame(int num_players, const char* player_names[]) : Game(num_players, player_names){
    // Specific initialization for PinochleDeck
   
    if (!isDeckValid()) {
        throw std::invalid_argument("Invalid PinochleDeck: not enough cards of each rank.");
    }
    // Additional constructor logic for PinochleDeck...
}

bool hasFourCards (int i) { 

    return (i>=4); 
}


bool isDeckValid(){
    
}