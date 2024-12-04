//TexasholdemGame.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//header file for TexasholdemGame class derived from Game class.
#include "Game.h"
#include "Texasholdem.h"
#include "header.h"
#include "Card_T.h"

#pragma once

enum class HoldEmState {preflop, flop, turn, river, undefined};

class TexasholdemGame : public Game{

    public :
        TexasholdemGame(int argc, const char *argv[]);
        virtual int play();

          
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

    
};