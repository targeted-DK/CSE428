// PinochleGame.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// source file for PinochleGame class derived from Game class.
#include "PinochleGame.h"
#include "Game.h"
#include <memory>

#define SUCCESS 0
#define START_COUNTER 0
#define PLAY_AGAIN 1
#define OFFSET 2
#define PACKET 3

PinochleGame::PinochleGame(int argc, const char *argv[]) : Game(argc, argv)
{
    int curr_player = START_COUNTER;
    int total_num_players = argc - OFFSET;
    while (curr_player < total_num_players)
    {

        CardSet<Suit, PinochleRank> new_hand;
        this->hands.push_back(new_hand);
        curr_player++;
    }
}

void PinochleGame::deal()
{

    int card_counter = START_COUNTER;
    int curr_player = START_COUNTER;
    int total_num_players = this->hands.size();


    while (!this->pino_deck.is_empty())
    {
        if (card_counter == PACKET)
        {

            curr_player++;

            if (curr_player == total_num_players)
            {
                curr_player = START_COUNTER;
            }
            card_counter = START_COUNTER;
        }
        else
        {

            this->pino_deck >> this->hands.at(curr_player);

            card_counter++;
        }
    }

    return;
}
//Design Implementation : For the readibility of play() function, I created helper functions so that each functions in play() indicates game steps.
//I added a line breaker and a game name indicator for the visilibity of lines and game information.
int PinochleGame::play()
{
    int user_input_result = PLAY_AGAIN;

    while (user_input_result == PLAY_AGAIN)
    {
        cout << endl;
        cout << "Current Game Played : Pinochle with 4 players" << endl;
        this->pino_deck.shuffle();
        this->deal();
        this->printPlayerHands();
        this->collectPlayerCards();

        user_input_result = this->askIfDone();
    }

    return user_input_result;
};


//Helper function that prints each player's CardSet
void PinochleGame::printPlayerHands(){

   for (size_t player = START_COUNTER; player < this->hands.size(); player++) 
    {
        cout << "[    " << this->names.at(player) << "'s cards    ]" << endl;
        this->hands.at(player).print(cout, 5);
        cout << endl;
        cout << endl;
      
    }
}

//Helper function that collects player's CardSet
void PinochleGame::collectPlayerCards(){

   for (size_t player = START_COUNTER; player < this->hands.size(); player++) {
     
             this->pino_deck.collect(this->hands.at(player));
    }
}