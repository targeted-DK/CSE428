// TexasholdemGame.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// source file for TexasholdemGame class derived from Game class.
#include "TexasholdemGame.h"
#include "Game.h"

#define SUCCESS 0
#define START_COUNTER 0
#define PLAY_AGAIN 1
#define OFFSET 2
#define DRAW_TWO_TIMES 2
#define DRAW_THREE_TIMES 3
#define PACKET 3
#define BOARD_SIZE 5


TexasholdemGame::TexasholdemGame(int argc, const char *argv[]) : Game(argc, argv), state(HoldEmState::preflop)
{

    int curr_player = START_COUNTER;
    int total_num_players = argc - OFFSET;
    while (curr_player < total_num_players)
    {

        CardSet<Suit, TexasholdemRank> new_hand;
        this->hands.push_back(new_hand);
        curr_player++;
    }

}

void TexasholdemGame::deal()
{
    int counter = 0;
    if (this->state == HoldEmState::preflop)
    {
        
        for (int i = START_COUNTER; i < DRAW_TWO_TIMES; i++)
        {
                
            for (size_t curr_player = START_COUNTER; curr_player < this->names.size(); curr_player++)
            {
                
                this->texas_deck >> this->hands.at(curr_player);
                counter++;
                
            }
        }
       
        this->state = HoldEmState::flop;
    }
    else if (this->state == HoldEmState::flop)
    {
        for (size_t i = 0; i < DRAW_THREE_TIMES; i++)
        {
            
             this->texas_deck >> this->board;
        }

        this->state = HoldEmState::turn;
    }
    else if (this->state == HoldEmState::turn)
    {

        this->texas_deck >> this->board;
        this->state = HoldEmState::river;
    }
    else if (this->state == HoldEmState::river)
    {
        
        this->texas_deck >> this->board;
        this->state = HoldEmState::undefined;
    }
    else if (this->state == HoldEmState::undefined)
    {
        // Do nothing.
    }

   
    return;
}
//Design Implementation : For the readibility of play() function, I created helper functions so that each functions in play() indicates game steps.
//I added line breakers and a game name indicator for the visibility of lines and game information.
//[      ] is added to players and BOARD so that users can easily distinguish cards that players/board owns.
int TexasholdemGame::play()
{
    int user_input_result = PLAY_AGAIN;

    while(user_input_result == PLAY_AGAIN){
    cout << endl;
    cout << "Current Game Played : TexasHoldEm with " << this->names.size() << " players" << endl;   
    this->texas_deck.shuffle(); 
    this->state = HoldEmState::preflop; 
    this->deal(); 
    this->printPlayerHands(); 
    this->deal();
    cout << "[    BOARD (flop)    ]" << endl;
    this->board.print(cout, BOARD_SIZE); 
    cout << endl << endl;
     this->deal(); 
    cout << "[    BOARD (turn)    ]"  << endl;
    this->board.print(cout, BOARD_SIZE); 
    cout << endl << endl;
    this->deal(); 
    cout << "[    BOARD (river)    ]" << endl;
    this->board.print(cout, BOARD_SIZE); 
    cout << endl << endl;

    this->collectPlayerCards(); 
    this->collectDeckCards(); 

    user_input_result = this->askIfDone();

    }

    return user_input_result;
};

//Helper function that prints each player's CardSet
void TexasholdemGame::printPlayerHands(){

  
   for (size_t player = START_COUNTER; player < this->hands.size(); player++) 
    {
        cout << "[    " << this->names.at(player) << "'s cards    ]" << endl;
        this->hands.at(player).print(cout, 2);
        cout << endl;
      
    }
}

//Helper function that collects player's CardSet
void TexasholdemGame::collectPlayerCards(){

  for (size_t player = START_COUNTER; player < this->hands.size(); player++) {
        for(size_t cardCount = START_COUNTER; cardCount < this->hands.at(player).getCards().size(); cardCount++){

             this->texas_deck.collect(this->hands.at(player));
 
        }    
    }
}

//Helper function that collects deck's CardSet
void TexasholdemGame::collectDeckCards(){

     for(size_t cardCount = START_COUNTER; cardCount < this->board.getCards().size(); cardCount++){

            this->texas_deck.collect(this->board);
 
        }  
       
}

