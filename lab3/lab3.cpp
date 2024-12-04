// lab3.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// Includes main() for this lab
#include "header.h"
#include "Deck_T.h"
#include "Card_T.h"
#include "Game.h"
#include "Pinochle.h"
#include "Texasholdem.h"
#include "PinochleGame.h"
#include "TexasholdemGame.h"
#include "GoFishGame_T.h"

#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

#define SUCCESS 0
#define FAIL 1
#define GAME_NAME 1
#define DECK_NAME 2
#define OFFSET_THREE 3
#define PLAYER_NAMES 2
#define OFFSET 2
#define PINO_REQUIRED 4
#define TEXAS_MIN_REQUIRED 2
#define TEXAS_MAX_REQUIRED 9
#define GOFISH_MIN_REQUIRED 2
#define GOFISH_MAX_REQUIRED 5

shared_ptr<Game> create(int argc, const char *argv[])
{
    
    shared_ptr<Game> current_game;

    string game_name = argv[GAME_NAME];
    
    try
    {
        if (game_name == "Pinochle" || game_name == "pinochle")
        {
            current_game = make_shared<PinochleGame>(argc, argv);
        }
        else if (game_name == "HoldEm" || game_name == "holdem")
        {
            current_game = make_shared<TexasholdemGame>(argc, argv);
        }
        else if (game_name == "GoFish")
        {
            string deck_type = argv[DECK_NAME];
      
            if (deck_type == "Pinochle")
            {
               
                current_game = make_shared<GoFishGame<Suit, PinochleRank, Pinochle>>(argc, argv);
                
            }
            else if (deck_type == "HoldEm")
            {
                current_game = make_shared<GoFishGame<Suit, TexasholdemRank, Texasholdem>>(argc, argv);
            }
            else if (deck_type == "Uno")
            {
                current_game = make_shared<GoFishGame<Color, UnoRank, Uno>>(argc, argv);
            }
           
        }
        else
        {
            cout << "Invalid input. Choose your deck to use for GoFish game (pinochle, holdem, uno), or quit(ctrl + c) " << endl;
        }
    }

   
    catch (const runtime_error &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
       
        return nullptr;
    }

    return current_game;
}

// Design Implementation : When user does not input correct number of arguments and wrong game name, helper messages are printed to help users.
int main(int argc, const char *argv[])
{

    shared_ptr<Game> p;
    if (argc == FAIL)
    {
        cout << "Usage : ./lab3 <Game Name> <Player Names> " << endl;
        cout << "<Game Type 1> : Pinochle, HoldEm" << endl;
        cout << "<Player Names> : 4 names for Pinochole, 2 ~ 9 names for HoldEm" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << "Usage : ./lab3 <Game Name> <Deck Type> <Player Names> " << endl;
        cout << "<Game Type 2> : Gofish" << endl;
        cout << "<Deck Types> : Pinochle, Holdem, Uno" << endl;
        cout << "<Player Names> : 2 ~ 5 names for Gofish" << endl;

        return FAIL;
    }

    // https://stackoverflow.com/questions/2603039/warning-comparison-with-string-literals-results-in-unspecified-behaviour
    if (strcmp(argv[GAME_NAME], "Pinochle") == SUCCESS)
    {

        if (argc - OFFSET == PINO_REQUIRED)
        {

            p = create(argc, argv);
        }
        else
        {
            cout << "Error : Wrong number of players. Pinochle should have 4 players." << endl;
            return FAIL;
        }
    }
    else if (strcmp(argv[GAME_NAME], "HoldEm") == SUCCESS)
    {

        if (argc - OFFSET >= TEXAS_MIN_REQUIRED && argc - OFFSET <= TEXAS_MAX_REQUIRED)
        {
            p = create(argc, argv);
        }
        else
        {

            cout << "Error : Wrong number of players. Holdem should have players between 2 and 9." << endl;
            return FAIL;
        }
    }
    else if (strcmp(argv[GAME_NAME], "GoFish") == SUCCESS)
    {
      
        if((strcmp(argv[DECK_NAME], "HoldEm")) == SUCCESS || (strcmp(argv[DECK_NAME], "Pinochle")) == SUCCESS || (strcmp(argv[DECK_NAME], "Uno") == SUCCESS)){
        
             
            if (argc - (OFFSET_THREE) >= GOFISH_MIN_REQUIRED && argc - (OFFSET_THREE) <= GOFISH_MAX_REQUIRED)
                {
                   
                    p = create(argc, argv);
                }
                else
                {
                    cout << "Error : Wrong number of players. GoFish should players between 2 and 5." << endl;
                    return FAIL;
                }
        } else {
           cout << "Wrong type of deck. Choose from HoldEm, Pinochle or Uno" << endl;

        return FAIL;
        }
       
    }
    else
    {
        cout << "Usage : ./lab3 <Game Name> <Player Names> " << endl;
        cout << "<Game Type 1> : Pinochle, HoldEm" << endl;
        cout << "<Player Names> : 4 names for Pinochole, 2 ~ 9 names for HoldEm" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << "Usage : ./lab3 <Game Name> <Deck Type> <Player Names> " << endl;
        cout << "<Game Type 2> : GoFish" << endl;
        cout << "<Deck Types> : Pinochle, Holdem, Uno" << endl;
        cout << "<Player Names> : 2 ~ 5 names for GoFish" << endl;

        return FAIL;
    }
   
    if (p)
    {
       
        p->play();
    }
    else
    {

        cout << "Error: Invalid Game" << endl;
        cout << "Usage : ./lab3 <Game Name> <Player Names> " << endl;
        cout << "<Game Type 1> : Pinochle, HoldEm" << endl;
        cout << "<Player Names> : 4 names for Pinochole, 2 ~ 9 names for HoldEm" << endl;
        cout << "------------------------------------------------------------------------------------------" << endl;
        cout << "Usage : ./lab3 <Game Name> <Deck Type> <Player Names> " << endl;
        cout << "<Game Type 2> : GoFish" << endl;
        cout << "<Deck Types> : Pinochle, Holdem, Uno" << endl;
        cout << "<Player Names> : 2 ~ 5 names for GoFish" << endl;
        return FAIL;
    }

    return SUCCESS;
}
