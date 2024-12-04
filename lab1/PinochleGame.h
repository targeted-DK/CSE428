//PinochleGame.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//header file for PinochleGame class derived from Game class.
#include "Game.h"
#include "Pinochle.h"
#include "header.h"
#include "Card_T.h"

#pragma once

class PinochleGame : public Game{

    public :
        PinochleGame(int argc, const char *argv[]);
        virtual int play();

          
    protected :
        Pinochle pino_deck;
        std::vector< CardSet<Suit, PinochleRank> > hands;
        virtual void deal(); 
        void printPlayerHands();
        void collectPlayerCards();
    
    
};