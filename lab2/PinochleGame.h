//PinochleGame.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//header file for PinochleGame class derived from Game class.
#include "Game.h"
#include "Pinochle.h"
#include "header.h"
#include "Card_T.h"

#pragma once

//#10. Declare a public enum class PinochleMelds enumerated type
enum class PinochleMelds {dix, offsuitmarriage, fortyjacks, pinochle, insuitmarriage, sixtyqueens, eightykings, hundredaces, insuitrun, doublepinochle, fourhundredjacks, sixhundredqueens, eighthundredkings, thousandaces, insuitdoublerun};

class PinochleGame : public Game{

    public :
        PinochleGame(int argc, const char *argv[]);
        virtual int play();
        
        //#10. declare and initialize a public static member variable of the PinochleGame class
        static const unsigned int meld_point = 0;
        static const unsigned int meld_points[];

          
    protected :
        Pinochle pino_deck;
        std::vector< CardSet<Suit, PinochleRank> > hands;
        virtual void deal(); 
        void printPlayerHands();
        void collectPlayerCards();

    private : 

    //#12. Declare and define a private suit_independent_evaluation member function
    void suit_independent_evaluation(const CardSet<Suit, PinochleRank>& pino_player_hand, std::vector<PinochleMelds>& pino_melds_vector);

    
};


//#11. Declare and define a left shift operator (operator<<) 
std::ostream& operator<<(std::ostream& os, const PinochleMelds& meld);

