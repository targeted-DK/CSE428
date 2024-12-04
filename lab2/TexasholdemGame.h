//TexasholdemGame.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//header file for TexasholdemGame class derived from Game class.
#include "Game.h"
#include "Texasholdem.h"
#include "header.h"
#include "Card_T.h"

#pragma once

enum class HoldEmState {preflop, flop, turn, river, undefined};
//#14. Declare an enum class HoldEmHandRank enumerated type 
enum class HoldEmHandRank {xhigh, pair, twopair, threeofakind, straight, flush, fullhouse, fourofakind, straightflush, undefined};

class TexasholdemGame : public Game{

    public :
        TexasholdemGame(int argc, const char *argv[]);
        virtual int play();

        //#16. Add a nested struct to your HoldEmGame class 
        struct Player {
            CardSet<Suit, TexasholdemRank> card_set;
            string player_name;
            HoldEmHandRank hand_rank;
           
            Player(const CardSet<Suit, TexasholdemRank>& _card_set, const std::string& _player_name, HoldEmHandRank _hand_rank)
            : card_set(_card_set),player_name(_player_name), hand_rank(_hand_rank){};

        };

        //#16. declare and define a non-member less than operator (operator<) 
        friend bool operator<(const Player& lhs, const Player& rhs);
        
          
    protected :
        HoldEmState state;
        Texasholdem texas_deck;
        std::vector< CardSet<Suit, TexasholdemRank> > hands;
        CardSet<Suit, TexasholdemRank> board;
        virtual void deal();

        //helper functions;
        void printPlayerHands();
        void collectPlayerCards();
        void collectDeckCards();

    private:
         //#15. Declare and define a private holdem_hand_evaluation member function
         HoldEmHandRank holdem_hand_evaluation(const CardSet<Suit, TexasholdemRank>& holdem_player_hand);
         HoldEmHandRank isUndefined(const vector<Card <Suit, TexasholdemRank> >& cards);
         HoldEmHandRank isStraight(const vector<Card <Suit, TexasholdemRank> >& cards);
         HoldEmHandRank isFlush(const vector<Card<Suit, TexasholdemRank>>& cards);
         HoldEmHandRank isFourOfAKind(const vector<Card<Suit, TexasholdemRank>>& cards);
         HoldEmHandRank isFullHouse(const vector<Card<Suit, TexasholdemRank>>& cards);
         HoldEmHandRank isThreeOfAKind(const vector<Card<Suit, TexasholdemRank>>& cards);
         HoldEmHandRank isTwoPair(const vector<Card<Suit, TexasholdemRank>>& cards);
         HoldEmHandRank isPair(const vector<Card<Suit, TexasholdemRank>>& cards);
        
};

//#14. Declare and define a left shift operator (operator<<) 
std::ostream& operator<<(std::ostream& os, const HoldEmHandRank& hand_rank);

//#15. declare and define a non-member less than operator (operator<) 
bool operator<(const TexasholdemGame::Player& lhs, const TexasholdemGame::Player& rhs);
bool compare_xhigh(vector<Card<Suit, TexasholdemRank>>& lhs_cards, vector<Card<Suit, TexasholdemRank>>& rhs_cards);  
bool compare_pair(vector<Card<Suit, TexasholdemRank>>& lhs_cards, vector<Card<Suit, TexasholdemRank>>& rhs_cards);  
bool compare_twopair(vector<Card<Suit, TexasholdemRank>>& lhs_cards, vector<Card<Suit, TexasholdemRank>>& rhs_cards);
bool compare_threeofakind(vector<Card<Suit, TexasholdemRank>>& lhs_cards, vector<Card<Suit, TexasholdemRank>>& rhs_cards);
bool compare_straight(vector<Card<Suit, TexasholdemRank>> &lhs_cards, vector<Card<Suit, TexasholdemRank>> &rhs_cards);
bool compare_flush(vector<Card<Suit, TexasholdemRank>> &lhs_cards, vector<Card<Suit, TexasholdemRank>> &rhs_cards);
bool compare_fullhouse(vector<Card<Suit, TexasholdemRank>> &lhs_cards, vector<Card<Suit, TexasholdemRank>> &rhs_cards);
bool compare_fourofakind(vector<Card<Suit, TexasholdemRank>> &lhs_cards, vector<Card<Suit, TexasholdemRank>> &rhs_cards);
bool compare_straightflush(vector<Card<Suit, TexasholdemRank>> &lhs_cards, vector<Card<Suit, TexasholdemRank>> &rhs_cards);