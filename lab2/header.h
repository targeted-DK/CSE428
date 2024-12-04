//header.h
//Author : Donggyu Kim, donggyukim@wustl.edu
//Declares Suit enum and its operators
#include <iostream>

#pragma once

using namespace std;


enum class Suit {clubs, diamonds, hearts, spades, undefined};

std::ostream& operator<<(ostream& os, const Suit& cardsuit);

Suit& operator++(Suit& cardsuit);

