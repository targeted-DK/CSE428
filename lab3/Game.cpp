// Game.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// source file for Game abstract base class
#include "Game.h"

#include <iostream>

using namespace std;

#define program_name 0
#define game_name 1
#define name_index 2
#define START_COUNTER 0
#define OFFSET 2
#define SUCCESS 0
#define PLAY_AGAIN 1

Game::Game(int argc, const char * argv[]){

    for(int player = START_COUNTER + OFFSET ; player < argc; player++){

        this->names.push_back(argv[player]);
    }
}


//Design Implementation : System messages were written in a way that gives clear instructions to the user what to input(yes/no), y and n also counts.
int Game::askIfDone(){

        cout << "Do you want to end current Game? (yes/no)" << endl;
        while(true){
            string user_input;
            getline(cin, user_input);

         if(user_input == "y" || user_input == "yes"){

            return SUCCESS;
         } else if(user_input == "n" || user_input == "no"){

            return PLAY_AGAIN;
         } else {
            cout << "Please answer in yes or no";
            continue;
         }
         
        }
};


