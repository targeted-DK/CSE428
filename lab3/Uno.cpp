// Uno.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// Uno game source file
#include "Uno.h"
#include "Card_T.h"
#include "Deck_T.h"

#define START_COUNTER 0
#define ADD_TWO_CARDS 2
#define ADD_FOUR_CARDS 4
#define UNO_COLORS 4

using namespace std;

Uno::Uno()
{

    // #15. one red, one blue, one green, and one yellow card of rank zero;
    for (Color uno_color = Color::red; uno_color < Color::black; ++uno_color)
    {

        this->cards.push_back(Card<Color, UnoRank>(uno_color, UnoRank::zero));
    }

    // #15. two red, two blue, two green, and two yellow cards of each rank one through drawtwo;
    for (int i = START_COUNTER; i < ADD_TWO_CARDS; i++)
    {
        for (Color uno_color = Color::red; uno_color < Color::black; ++uno_color)
        {
            for (UnoRank uno_rank = UnoRank::one; uno_rank < UnoRank::drawfour; ++uno_rank)
            {

                this->cards.push_back(Card<Color, UnoRank>(uno_color, uno_rank));
            }
        }
    }

    // #15. four black cards of each rank drawfour through blank.
    for (int i = START_COUNTER; i < ADD_FOUR_CARDS; i++)
    {
        Color uno_color = Color::black;
        for (UnoRank uno_rank = UnoRank::drawfour; uno_rank < UnoRank::undefined; ++uno_rank)
        {

            this->cards.push_back(Card<Color, UnoRank>(uno_color, uno_rank));
        }
    }
}

UnoRank &operator++(UnoRank &unoRank)
{
    switch (unoRank)
    {
    case UnoRank::zero:
        unoRank = UnoRank::one;
        break;
    case UnoRank::one:
        unoRank = UnoRank::two;
        break;
    case UnoRank::two:
        unoRank = UnoRank::three;
        break;
    case UnoRank::three:
        unoRank = UnoRank::four;
        break;
    case UnoRank::four:
        unoRank = UnoRank::five;
        break;
    case UnoRank::five:
        unoRank = UnoRank::six;
        break;
    case UnoRank::six:
        unoRank = UnoRank::seven;
        break;
    case UnoRank::seven:
        unoRank = UnoRank::eight;
        break;
    case UnoRank::eight:
        unoRank = UnoRank::nine;
        break;

    case UnoRank::nine:
        unoRank = UnoRank::skip;
        break;

    case UnoRank::skip:
        unoRank = UnoRank::reverse;
        break;

    case UnoRank::reverse:
        unoRank = UnoRank::drawtwo;
        break;

    case UnoRank::drawtwo:
        unoRank = UnoRank::drawfour;
        break;
    case UnoRank::drawfour:
        unoRank = UnoRank::wild;
        break;
    case UnoRank::wild:
        unoRank = UnoRank::blank;
        break;
    case UnoRank::blank:
        unoRank = UnoRank::undefined;
        break;

    case UnoRank::undefined:
        break;
    };

    return unoRank;
}
ostream &operator<<(ostream &os, const UnoRank &unoRank)
{
    switch (unoRank)
    {
    case UnoRank::zero:
        os << "0";
        break;
    case UnoRank::one:
        os << "1";
        break;
    case UnoRank::two:
        os << "2";
        break;
    case UnoRank::three:
        os << "3";
        break;
    case UnoRank::four:
        os << "4";
        break;
    case UnoRank::five:
        os << "5";
        break;
    case UnoRank::six:
        os << "6";
        break;
    case UnoRank::seven:
        os << "7";
        break;
    case UnoRank::eight:
        os << "8";
        break;
    case UnoRank::nine:
        os << "9";
        break;
    case UnoRank::skip:
        os << "S";
        break;
    case UnoRank::reverse:
        os << "R";
        break;
    case UnoRank::drawtwo:
        os << "D2";
        break;
    case UnoRank::drawfour:
        os << "D4";
        break;

    case UnoRank::wild:
        os << "W";
        break;
    case UnoRank::blank:
        os << "B";
        break;
    case UnoRank::undefined:
        os << "?";
        break;
    }

    return os;
}

Color &operator++(Color &color)
{
    switch (color)
    {
    case Color::red:
        color = Color::blue;
        break;
    case Color::blue:
        color = Color::green;
        break;
    case Color::green:
        color = Color::yellow;
        break;
    case Color::yellow:
        color = Color::black;
        break;
    case Color::black:
        color = Color::undefined;
        break;
    case Color::undefined:
        break;
    };

    return color;
}
ostream &operator<<(ostream &os, const Color &color)
{

    switch (color)
    {
    case Color::red:
        os << "R";
        break;
    case Color::blue:
        os << "B";
        break;
    case Color::green:
        os << "G";
        break;
    case Color::yellow:
        os << "Y";
        break;
    case Color::black:
        os << "B";
        break;
    case Color::undefined:
        os << "?";
        break;
    }

    return os;
}