// lab1.cpp
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

#include <iostream>
#include <memory>
#include <cstring>

using namespace std;

#define SUCCESS 0
#define FAIL 1
#define GAME_NAME 1
#define PLAYER_NAMES 2
#define PINO_REQUIRED 4
#define TEXAS_MIN_REQUIRED 2
#define TEXAS_MAX_REQUIRED 9

//Design Implementation : Both Pinochle and HoldEm, and its lower case versions are accepted.
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
    }
  catch (const runtime_error &e)
    {
        cerr << "Exception caught: " << e.what() << endl;
        return nullptr;
    }
   

    return current_game;
}

//Design Implementation : When user does not input correct number of arguments and wrong game name, helper messages are printed to help users.
int main(int argc, const char *argv[])
{
     shared_ptr<Game> p;
        if(argc == 1){
            cout << "Usage : ./lab1 <Game Name> <Player Names> " << endl;
            cout << "<Game Name> : Pinochle, HoldEm" << endl;
            cout << "<Player Names> : 4 names for Pinochole, 2 ~ 9 names for HoldEm" << endl;

            return FAIL;
        }
    
        //https://stackoverflow.com/questions/2603039/warning-comparison-with-string-literals-results-in-unspecified-behaviour
        if(strcmp(argv[GAME_NAME], "Pinochle") == 0){
           
            if(argc - 2 == PINO_REQUIRED){
               
               p = create(argc, argv);
            } else{
                cout << "Error : Wrong number of players. Pinochle should have 4 players." << endl;
                return FAIL;
                
            }

        } else if(strcmp(argv[GAME_NAME], "HoldEm")==0){
            
            if(argc - 2 >= TEXAS_MIN_REQUIRED || argc - 2 <= TEXAS_MAX_REQUIRED){
                p = create(argc, argv);
            } else{

                cout <<"Error : Wrong number of players. Holdem should have players between 2 and 9." << endl;
                return FAIL;
                
            }
        } else {

            cout << "Usage : ./lab1 <Game Name> <Player Names> " << endl;
            cout << "<Game Name> : Pinochle, HoldEm" << endl;
            cout << "<Player Names> : 4 names for Pinochole, 2 ~ 9 names for HoldEm" << endl;

            return FAIL;
        }
   
    if(p){
        p->play();
    }

    return SUCCESS;
   
    
}

