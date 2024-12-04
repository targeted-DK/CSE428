// Game.h
// Author : Donggyu Kim, donggyukim@wustl.edu
// header file for Game abstract base class
#include <vector>
#include <string>

#pragma once

class Game {
    public :
        Game(int argc, const char * argv[]);
        virtual int play() = 0;
        int askIfDone();

    protected :
        std::vector<std::string> names;

};
