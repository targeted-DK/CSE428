// PinochleGame.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// source file for PinochleGame class derived from Game class.
#include "PinochleGame.h"
#include "Pinochle.h"
#include "Game.h"
#include "header.h"
#include "CardSet_T.h"
#include <memory>
#include <vector>

#define SUCCESS 0
#define START_COUNTER 0
#define PLAY_AGAIN 1
#define OFFSET 2
#define PACKET 3
// These two definitions below are used to create 2d vector to store the occurences of each card to calculate meld.
#define PINOCHLE_SUITS_NUM 5
#define PINOCHLE_RANKS_NUM 7

using namespace std;

static const unsigned int meld_points[] = {10, 20, 40, 40, 40, 60, 80, 100, 150, 300, 400, 600, 800, 1000, 1500};

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
// Design Implementation : For the readibility of play() function, I created helper functions so that each functions in play() indicates game steps.
// I added a line breaker and a game name indicator for the visilibity of lines and game information.
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

        // #13. iterate through the vector and print out the label and value of each meld that was found.
        for (size_t player = START_COUNTER; player < this->hands.size(); player++)
        {
            // creating new local variable of vector<PinochleMelds> ensures that melds from the previous game or previous player do not get carried over.
            vector<PinochleMelds> pino_melds_vector;
            this->suit_independent_evaluation(this->hands.at(player), pino_melds_vector);

            cout << "Player " << this->names.at(player) << "'s meld : " << endl;
            for (size_t meld_idx = START_COUNTER; meld_idx < pino_melds_vector.size(); meld_idx++)
            {
                cout << pino_melds_vector.at(meld_idx) << " ";
            }
            cout << endl;
        }
        this->collectPlayerCards();

        user_input_result = this->askIfDone();
    }

    return user_input_result;
};

// Helper function that prints each player's CardSet
void PinochleGame::printPlayerHands()
{

    for (size_t player = START_COUNTER; player < this->hands.size(); player++)
    {
        cout << "[    " << this->names.at(player) << "'s cards    ]" << endl;
        this->hands.at(player).print(cout, 5);
        cout << endl;
        cout << endl;
    }
}

// Helper function that collects player's CardSet
void PinochleGame::collectPlayerCards()
{

    for (size_t player = START_COUNTER; player < this->hands.size(); player++)
    {

        this->pino_deck.collect(this->hands.at(player));
    }
}

// #12. Declare and define a private suit_independent_evaluation member function
void PinochleGame::suit_independent_evaluation(const CardSet<Suit, PinochleRank> &pino_player_hand, vector<PinochleMelds> &pino_melds_vector)
{
    // This line uses a custom copy constructor of CardSet that performs deepcopy of a given parameter.
    CardSet<Suit, PinochleRank> temp_card_set(pino_player_hand);
    
    // Sort a new copy of CardSet
    temp_card_set.sortByRank();
    temp_card_set.sortBySuit();

    PinochleMelds meld = PinochleMelds::dix;

    vector<Card<Suit, PinochleRank>> CardSet<Suit, PinochleRank>::*ptrToMember = temp_card_set.get_cards_pointer();
    vector<Card<Suit, PinochleRank>> &cards = temp_card_set.*ptrToMember;

    // vector<Card<Suit, PinochleRank>>* cards = get_cards_pointer(temp_card_set);

    // I created a 2d array with two nested vectors that stores number of each card occurrences to caculate meld
    // Each row :  {clubs, diamonds, hearts, spades, undefined};
    // Each col :  {nine, jack, queen, king, ten, ace, undefined};
    vector<vector<int>> card_matrix(PINOCHLE_SUITS_NUM, std::vector<int>(PINOCHLE_RANKS_NUM, 0));

    for (const auto &card : cards)
    {
        card_matrix[static_cast<int>(card.suit)][static_cast<int>(card.rank)]++;
    }
    int ace_count = 0;
    int king_count = 0;
    int queen_count = 0;
    int jack_count = 0;
    //these booleans keep track whether hand contains single card of each suit
    bool one_ace_per_suit = true;
    bool one_king_per_suit = true;
    bool one_queen_per_suit = true;
    bool one_jack_per_suit = true;

    for (int suit = 0; suit < PINOCHLE_SUITS_NUM; suit++)
    {
        int suit_ace_count = card_matrix[suit][static_cast<int>(PinochleRank::ace)];
        int suit_king_count = card_matrix[suit][static_cast<int>(PinochleRank::king)];
        int suit_queen_count = card_matrix[suit][static_cast<int>(PinochleRank::queen)];
        int suit_jack_count = card_matrix[suit][static_cast<int>(PinochleRank::jack)];

        ace_count += suit_ace_count;
        king_count += suit_king_count;
        queen_count += suit_queen_count;
        jack_count += suit_jack_count;

        if (suit_ace_count != 1)
        {
            one_ace_per_suit = false;
        }
        if (suit_king_count != 1)
        {
            one_king_per_suit = false;
        }
        if (suit_queen_count != 1)
        {
            one_queen_per_suit = false;
        }
        if (suit_jack_count != 1)
        {
            one_jack_per_suit = false;
        }
    }

    // special cases
    int jack_diamonds_count = card_matrix[static_cast<int>(Suit::diamonds)][static_cast<int>(PinochleRank::jack)];
    int queen_spades_count = card_matrix[static_cast<int>(Suit::spades)][static_cast<int>(PinochleRank::queen)];

    // thousandaces for all 8 aces (A♠ A♠ A♥ A♥ A♦ A♦ A♣ A♣)
    if (ace_count == 8)
    {
        meld = PinochleMelds::thousandaces;
    }
    // hundredaces for an ace of each suit (A♠ A♥ A♦ A♣) but not if the hand has thousandaces
    else if (ace_count == 4 && one_ace_per_suit)
    {
        meld = PinochleMelds::hundredaces;
    }

    if (meld != PinochleMelds::dix)
    {
        pino_melds_vector.push_back(meld);
    }

    // eighthundredkings for all 8 kings (K♠ K♠ K♥ K♥ K♦ K♦ K♣ K♣)
    if (king_count == 8)
    {
        meld = PinochleMelds::eighthundredkings;
    }
    // eightykings for a king of each suit (K♠ K♥ K♦ K♣) but not if the hand has eighthundredkings
    else if (king_count == 4 && one_king_per_suit)
    {
        meld = PinochleMelds::eightykings;
    }
    if (meld != PinochleMelds::dix)
    {
        pino_melds_vector.push_back(meld);
    }

    // sixhundredqueens for all 8 queens (Q♠ Q♠ Q♥ Q♥ Q♦ Q♦ Q♣ Q♣)
    if (queen_count == 8)
    {
        meld = PinochleMelds::sixhundredqueens;
    }
    // sixtyqueens for a queen of each suit (Q♠ Q♥ Q♦ Q♣) but not if the hand has sixhundredqueens
    else if (queen_count == 4 && one_queen_per_suit)
    {
        meld = PinochleMelds::sixtyqueens;
    }
    if (meld != PinochleMelds::dix)
    {
        pino_melds_vector.push_back(meld);
    }

    // fourhundredjacks for all 8 jacks (J♠ J♠ J♥ J♥ J♦ J♦ J♣ J♣)
    if (jack_count == 8)
    {
        meld = PinochleMelds::fourhundredjacks;
    }
    // fortyjacks for a jack of each suit (J♠ J♥ J♦ J♣) but not if the hand has fourhundredjacks
    else if (jack_count == 8 && one_jack_per_suit)
    {
        meld = PinochleMelds::fortyjacks;
    }
    if (meld != PinochleMelds::dix)
    {
        pino_melds_vector.push_back(meld);
    }

    // doublepinochle for two jacks of diamonds and two queens of spades (J♦ J♦ Q♠ Q♠)
    if (jack_diamonds_count == 2 && queen_spades_count == 2)
    {
        meld = PinochleMelds::doublepinochle;
    }
    // pinochle for a jack of diamonds and a queen of spades (J♦ Q♠) but not if the hand has doublepinochle
    else if (jack_diamonds_count == 1 && queen_spades_count == 1)
    {
        meld = PinochleMelds::pinochle;
    }

    if (meld != PinochleMelds::dix)
    {
        pino_melds_vector.push_back(meld);
    }
}
// #11. Declare and define a left shift operator (operator<<)
ostream &operator<<(std::ostream &os, const PinochleMelds &meld)
{

    string meld_str;

    switch (meld)
    {
    case PinochleMelds::dix:
        meld_str = "dix";
        break;
    case PinochleMelds::offsuitmarriage:
        meld_str = "offsuitmarriage";
        break;
    case PinochleMelds::fortyjacks:
        meld_str = "fortyjacks";
        break;
    case PinochleMelds::pinochle:
        meld_str = "pinochle";
        break;
    case PinochleMelds::insuitmarriage:
        meld_str = "insuitmarriage";
        break;
    case PinochleMelds::sixtyqueens:
        meld_str = "sixtyqueens";
        break;
    case PinochleMelds::eightykings:
        meld_str = "eightykings";
        break;
    case PinochleMelds::hundredaces:
        meld_str = "hundredaces";
        break;
    case PinochleMelds::insuitrun:
        meld_str = "insuitrun";
        break;
    case PinochleMelds::doublepinochle:
        meld_str = "doublepinochle";
        break;
    case PinochleMelds::fourhundredjacks:
        meld_str = "fourhundredjacks";
        break;
    case PinochleMelds::sixhundredqueens:
        meld_str = "sixhundredqueens";
        break;
    case PinochleMelds::eighthundredkings:
        meld_str = "eighthundredkings";
        break;
    case PinochleMelds::thousandaces:
        meld_str = "thousandaces";
        break;
    case PinochleMelds::insuitdoublerun:
        meld_str = "insuitdoublerun";
        break;
    }

    os << meld_str << " " << meld_points[static_cast<int>(meld)];

    return os;
}