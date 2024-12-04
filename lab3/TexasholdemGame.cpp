// TexasholdemGame.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// source file for TexasholdemGame class derived from Game class.
#include "TexasholdemGame.h"
#include "Game.h"
#include "CardSet_T.h"
#include <algorithm>

#define SUCCESS 0
#define START_COUNTER 0
#define PLAY_AGAIN 1
#define OFFSET 2
#define DRAW_TWO_TIMES 2
#define DRAW_THREE_TIMES 3
#define PACKET 3
#define BOARD_SIZE 5
#define HOLDEM_CARDS_NUM 5
#define HOLDEM_SUITS_NUM 5
#define HOLDEM_RANKS_NUM 13

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

TexasholdemGame::~TexasholdemGame(){}

void TexasholdemGame::deal()
{
    if (this->state == HoldEmState::preflop)
    {

        for (int i = START_COUNTER; i < DRAW_TWO_TIMES; i++)
        {

            for (size_t curr_player = START_COUNTER; curr_player < this->names.size(); curr_player++)
            {

                this->texas_deck >> this->hands.at(curr_player);
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
// Design Implementation : For the readibility of play() function, I created helper functions so that each functions in play() indicates game steps.
// I added line breakers and a game name indicator for the visibility of lines and game information.
//[      ] is added to players and BOARD so that users can easily distinguish cards that players/board owns.
int TexasholdemGame::play()
{
    int user_input_result = PLAY_AGAIN;
     
    while (user_input_result == PLAY_AGAIN)
    {

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

        //#17 - push back an instance of that struct with each player's hand and name and the undefined value.
        std::vector<TexasholdemGame::Player> player_infos;

        for (size_t player = START_COUNTER; player < this->hands.size(); player++){
           
            Player player_info(this->hands.at(player), this->names.at(player), HoldEmHandRank::undefined);
            player_infos.push_back(player_info);
        }
        //#17 - iterate through that vector and add
         for (Player& player : player_infos) {
            for (auto card : this->board.getCards()) {
                player.card_set.getCards().push_back(card);
            }
           
            player.hand_rank = holdem_hand_evaluation(player.card_set);
            cout << endl;
            cout << player.hand_rank;
            cout << endl;
           
        }

        //#17 - sort player's hand based on their hands
        std::sort(player_infos.begin(), player_infos.end());
        std::reverse(player_infos.begin(), player_infos.end());
       
        for(Player& player : player_infos){
            cout << player.player_name << " : " << player.hand_rank << endl;
            for(auto card : player.card_set.getCards()){
                cout << card.suit << card.rank << " ";
            }
            cout << endl;

        }
        cout << endl;
        cout << endl;
        this->board.getCards().size();
        this->deal();
        cout << "[    BOARD (turn)    ]" << endl;
        this->board.print(cout, BOARD_SIZE);
        cout << endl
             << endl;
        this->deal();
        cout << "[    BOARD (river)    ]" << endl;
        this->board.print(cout, BOARD_SIZE);
        cout << endl
             << endl;

        this->collectPlayerCards();
        this->collectDeckCards();

        user_input_result = this->askIfDone();
    }

    return user_input_result;
};

// Helper function that prints each player's CardSet
void TexasholdemGame::printPlayerHands()
{

    for (size_t player = START_COUNTER; player < this->hands.size(); player++)
    {
        cout << "[    " << this->names.at(player) << "'s cards    ]" << endl;
        this->hands.at(player).print(cout, 2);
        cout << endl;
    }
}

// Helper function that collects player's CardSet
void TexasholdemGame::collectPlayerCards()
{

    for (size_t player = START_COUNTER; player < this->hands.size(); player++)
    {
        for (size_t cardCount = START_COUNTER; cardCount < this->hands.at(player).getCards().size(); cardCount++)
        {

            this->texas_deck.collect(this->hands.at(player));
        }
    }
}

// Helper function that collects deck's CardSet
void TexasholdemGame::collectDeckCards()
{

    for (size_t cardCount = START_COUNTER; cardCount < this->board.getCards().size(); cardCount++)
    {

        this->texas_deck.collect(this->board);
    }
}

// #14. Declare and define a left shift operator (operator<<)
std::ostream &operator<<(std::ostream &os, const HoldEmHandRank &hand_rank)
{
    switch (hand_rank)
    {
    case HoldEmHandRank::xhigh:
        os << "x high";
        break;
    case HoldEmHandRank::pair:
        os << "One Pair";
        break;
    case HoldEmHandRank::twopair:
        os << "Two Pair";
        break;
    case HoldEmHandRank::threeofakind:
        os << "Three of a Kind";
        break;
    case HoldEmHandRank::straight:
        os << "Straight";
        break;
    case HoldEmHandRank::flush:
        os << "Flush";
        break;
    case HoldEmHandRank::fullhouse:
        os << "Full House";
        break;
    case HoldEmHandRank::fourofakind:
        os << "Four of a Kind";
        break;
    case HoldEmHandRank::straightflush:
        os << "Straight Flush";
        break;
    case HoldEmHandRank::undefined:
        os << "undefined";
        break;
    }
    return os;
}

HoldEmHandRank TexasholdemGame::holdem_hand_evaluation(const CardSet<Suit, TexasholdemRank> &holdem_player_hand)
{
    // This line uses a custom copy constructor of CardSet that performs deepcopy of a given paramete
    CardSet<Suit, TexasholdemRank> temp_card_set(holdem_player_hand);

    // Sort a new copy of CardSet
     temp_card_set.sortByRank();
     temp_card_set.sortBySuit();

    const vector<Card<Suit, TexasholdemRank>> &temp_cards = temp_card_set.getCards();

    // Check if the number of cards is exactly 5
    if (temp_card_set.getCards().size() != 5)
    {
        return HoldEmHandRank::undefined;
    }

    // straightflush
    if (isFlush(temp_cards) == HoldEmHandRank::flush && isStraight(temp_cards) == HoldEmHandRank::straight)
    {
        return HoldEmHandRank::straightflush;
    }
    // isFourOfAKind
    if (isFourOfAKind(temp_cards) == HoldEmHandRank::fourofakind)
    {
        return HoldEmHandRank::fourofakind;
    }
    // fullhouse
    if (isFullHouse(temp_cards) == HoldEmHandRank::fullhouse)
    {
        return HoldEmHandRank::fullhouse;
    }
    // flush
    if (isFlush(temp_cards) == HoldEmHandRank::flush)
    {
        return HoldEmHandRank::flush;
    }
    // straight
    if (isStraight(temp_cards) == HoldEmHandRank::straight)
    {
        return HoldEmHandRank::straight;
    }
    // threeofakind
    if (isThreeOfAKind(temp_cards) == HoldEmHandRank::threeofakind)
    {
        return HoldEmHandRank::threeofakind;
    }

    // twopair
    if (isTwoPair(temp_cards) == HoldEmHandRank::twopair)
    {
        return HoldEmHandRank::twopair;
    }

    // pair
    if (isPair(temp_cards) == HoldEmHandRank::pair)
    {
        return HoldEmHandRank::pair;
    }

    return HoldEmHandRank::xhigh;
}

// helper functions
// undefined if there are fewer or more than five cards in the hand
HoldEmHandRank TexasholdemGame::isUndefined(const vector<Card<Suit, TexasholdemRank>> &cards)
{
    if (cards.size() != 5)
    {
        return HoldEmHandRank::undefined;
    }
    return HoldEmHandRank::xhigh;
}
// checks if player's hand is straight
HoldEmHandRank TexasholdemGame::isStraight(const vector<Card<Suit, TexasholdemRank>> &cards)
{


    for (int count = 0; count < HOLDEM_CARDS_NUM - 1; count++)
    {
        //using absolute value let us check edge cases like K A 2
        if (abs(static_cast<int>(cards[count].rank) - static_cast<int>(cards[count + 1].rank)) == 1)
        {
            continue;
        }
        else
        {
            return HoldEmHandRank::undefined;
        }
    }

    return HoldEmHandRank::straight;
}


// checks if player's hand is flush
HoldEmHandRank TexasholdemGame::isFlush(const vector<Card<Suit, TexasholdemRank>> &cards)
{

    for (int count = 0; count < HOLDEM_CARDS_NUM - 1; count++)
    {
        if (cards[count].suit == cards[count + 1].suit)
        {
            continue;
        }
        else
        {
            return HoldEmHandRank::undefined;
        }
    }

    return HoldEmHandRank::flush;
}
// checks if four cards have the same rank - fourofakind
HoldEmHandRank TexasholdemGame::isFourOfAKind(const vector<Card<Suit, TexasholdemRank>> &cards)
{
    vector<int> rank_count(HOLDEM_RANKS_NUM, START_COUNTER);

    for (const auto &card : cards)
    {
        rank_count[static_cast<int>(card.rank)]++;
    }

    for (int count = 0; count < HOLDEM_CARDS_NUM; count++)
    {
        if (rank_count[count] == 4)
        {
            return HoldEmHandRank::fourofakind;
        }
    }
    return HoldEmHandRank::undefined;
}

// checks if three cards have the same rank and the other two cards have the same rank - full house
// Design Implementation : all we have to check if there are two suits with 3 cards and 2 cards respectively.
HoldEmHandRank TexasholdemGame::isFullHouse(const vector<Card<Suit, TexasholdemRank>> &cards)
{
    vector<int> rank_count(HOLDEM_RANKS_NUM, START_COUNTER);
    for (const auto &card : cards)
    {
        rank_count[static_cast<int>(card.rank)]++;
    }

    bool hasThree = false;
    bool hasTwo = false;
    for (int count = 0; count < HOLDEM_RANKS_NUM; count++)
    {
        if (rank_count[count] == 3)
        {
            hasThree = true;
        }
        else if (rank_count[count] == 2)
        {
            hasTwo = true;
        }
    }

    if (hasThree && hasTwo)
    {
        return HoldEmHandRank::fullhouse;
    }
    else
    {
        return HoldEmHandRank::undefined;
    }
}
// checks if three cards have the same rank and the other two cards are of different ranks than any other cards in the hand - three of a kind
HoldEmHandRank TexasholdemGame::isThreeOfAKind(const vector<Card<Suit, TexasholdemRank>> &cards)
{
    vector<int> rank_count(HOLDEM_RANKS_NUM, START_COUNTER);
    for (const auto &card : cards)
    {
        rank_count[static_cast<int>(card.rank)]++;
    }

    bool hasThree = false;
    int single_count = 0;
    for (int count = 0; count < HOLDEM_RANKS_NUM; count++)
    {
        if (rank_count[count] == 3)
        {
            hasThree = true;
        }
        else if (rank_count[count] == 1)
        {
            single_count++;
        }
    }

    if (hasThree && single_count == 2)
    {
        return HoldEmHandRank::threeofakind;
    }
    else
    {
        return HoldEmHandRank::undefined;
    }
}

// checks if there are two pairs of cards
HoldEmHandRank TexasholdemGame::isTwoPair(const vector<Card<Suit, TexasholdemRank>> &cards)
{
    vector<int> rank_count(HOLDEM_RANKS_NUM, START_COUNTER);
    for (const auto &card : cards)
    {
        rank_count[static_cast<int>(card.rank)]++;
    }

    int pair_count = 0;
    for (int count = 0; count < HOLDEM_RANKS_NUM; count++)
    {
        if (rank_count[count] == 2)
        {
            pair_count++;
        }
    }

    if (pair_count == 2)
    {
        return HoldEmHandRank::twopair;
    }
    else
    {
        return HoldEmHandRank::undefined;
    }
}

// checks if there is a single pair
HoldEmHandRank TexasholdemGame::isPair(const vector<Card<Suit, TexasholdemRank>> &cards)
{
    std::vector<int> rank_count(HOLDEM_RANKS_NUM, START_COUNTER);

    for (const auto &card : cards)
    {
        rank_count[static_cast<int>(card.rank)]++;
    }

    int pairCount = 0;
    for (int count = 0; count < HOLDEM_RANKS_NUM; count++)
    {
        if (rank_count[count] == 2)
        {
            pairCount++;
        }
    }

    if (pairCount == 1)
    {
        return HoldEmHandRank::pair;
    }
    else
    {
        return HoldEmHandRank::undefined;
    }
}

// #16. declare and define a non-member less than operator (operator<)
bool operator< (const TexasholdemGame::Player &lhs, const TexasholdemGame::Player &rhs)
{


    // returns true if (and only if) the value of the first object's HoldEmHandRank variable is less than that of the second object's
    if (lhs.hand_rank < rhs.hand_rank)
    {
        return true;
    }
    else if (lhs.hand_rank > rhs.hand_rank)
    {
        return false;
    }

    // create copy cardset
    CardSet<Suit, TexasholdemRank> lhs_card_set_copy(lhs.card_set);
    CardSet<Suit, TexasholdemRank> rhs_card_set_copy(rhs.card_set);

  

    //#7.you also may need to update various places in your code to use those iterators instead of the pointer to class template's protected vector member.
    vector<Card<Suit, TexasholdemRank>>::iterator lhs_cardSet_itr_begin = lhs_card_set_copy.begin();
    vector<Card<Suit, TexasholdemRank>>::iterator lhs_cardSet_itr_end = lhs_card_set_copy.end();
    vector<Card<Suit, TexasholdemRank>>::iterator rhs_cardSet_itr_begin = rhs_card_set_copy.begin();
    vector<Card<Suit, TexasholdemRank>>::iterator rhs_cardSet_itr_end = rhs_card_set_copy.end();

    std::sort(lhs_cardSet_itr_begin, lhs_cardSet_itr_end, compare_rank<Suit, TexasholdemRank>);
    std::sort(rhs_cardSet_itr_begin, rhs_cardSet_itr_end, compare_rank<Suit, TexasholdemRank>);

    reverse(lhs_cardSet_itr_begin, lhs_cardSet_itr_end);
    reverse(rhs_cardSet_itr_begin, rhs_cardSet_itr_end);


if (lhs.hand_rank == HoldEmHandRank::straightflush && rhs.hand_rank == HoldEmHandRank::straightflush) {
    return compare_straightflush(lhs_cardSet_itr_begin, rhs_cardSet_itr_begin);
}
 if (lhs.hand_rank == HoldEmHandRank::fourofakind && rhs.hand_rank == HoldEmHandRank::fourofakind) {
    return compare_fourofakind(lhs_cardSet_itr_begin, lhs_cardSet_itr_end, rhs_cardSet_itr_begin, rhs_cardSet_itr_end);
}
 if (lhs.hand_rank == HoldEmHandRank::fullhouse && rhs.hand_rank == HoldEmHandRank::fullhouse) {
    return compare_fullhouse(lhs_cardSet_itr_begin, rhs_cardSet_itr_begin);
}
 if (lhs.hand_rank == HoldEmHandRank::flush && rhs.hand_rank == HoldEmHandRank::flush) {
    return compare_flush(lhs_cardSet_itr_begin, lhs_cardSet_itr_end, rhs_cardSet_itr_begin, rhs_cardSet_itr_end);
}
 if (lhs.hand_rank == HoldEmHandRank::straight && rhs.hand_rank == HoldEmHandRank::straight) {
    return compare_straight(lhs_cardSet_itr_begin, rhs_cardSet_itr_begin);
}
 if (lhs.hand_rank == HoldEmHandRank::threeofakind && rhs.hand_rank == HoldEmHandRank::threeofakind) {
    return compare_threeofakind(lhs_cardSet_itr_begin, lhs_cardSet_itr_end, rhs_cardSet_itr_begin, rhs_cardSet_itr_end);
}
 if (lhs.hand_rank == HoldEmHandRank::twopair && rhs.hand_rank == HoldEmHandRank::twopair) {
    return compare_twopair(lhs_cardSet_itr_begin, lhs_cardSet_itr_end, rhs_cardSet_itr_begin, rhs_cardSet_itr_end);
}
 if (lhs.hand_rank == HoldEmHandRank::pair && rhs.hand_rank == HoldEmHandRank::pair) {
    return compare_pair(lhs_cardSet_itr_begin, lhs_cardSet_itr_end, rhs_cardSet_itr_begin, rhs_cardSet_itr_end);
}
 if (lhs.hand_rank == HoldEmHandRank::xhigh && rhs.hand_rank == HoldEmHandRank::xhigh) {
    return compare_xhigh(lhs_cardSet_itr_begin, lhs_cardSet_itr_end, rhs_cardSet_itr_begin, rhs_cardSet_itr_end);
}


    return false;
}

//tie breaker helper functions if both hands are xhigh
bool compare_xhigh(vector<Card<Suit, TexasholdemRank>>::iterator lhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator lhs_end, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_end)
{

    // Compare the hands card by card
    while (lhs_begin != lhs_end && rhs_begin != rhs_end) {
        if (lhs_begin->rank < rhs_begin->rank) {
            return true;
        }
        else if (lhs_begin->rank > rhs_begin->rank) {
            return false;
        }
        ++lhs_begin;
        ++rhs_begin;
    }

    return false; // Hands are equal in rank
}

//tie breaker helper functions if both hands are pairs
bool compare_pair(vector<Card<Suit, TexasholdemRank>>::iterator lhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator lhs_end, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_end)
{

    //variables to check rank of paired card in case when both players have same Holdem Rank
    TexasholdemRank lhs_pair_high = TexasholdemRank::undefined;
    TexasholdemRank rhs_pair_high = TexasholdemRank::undefined;
    // these vectors includes non-paired cards, so that we may use it to calculate xhigh
    vector<Card<Suit, TexasholdemRank>> lhs_cards_without_pair;
    vector<Card<Suit, TexasholdemRank>> rhs_cards_without_pair;

    

    while(lhs_begin != lhs_end){
       
        if(lhs_begin->rank == (lhs_begin + 1)->rank){
            lhs_pair_high = lhs_begin->rank;
            
        }
        else if(lhs_begin->rank != (lhs_begin + 1)->rank && ((lhs_begin + 1) == lhs_end)){
            lhs_cards_without_pair.push_back(*(lhs_begin+1));
        }
        else
        {
            lhs_cards_without_pair.push_back(*lhs_begin);
        }
        lhs_begin++;
    }

     while(rhs_begin != rhs_end){
        if(rhs_begin->rank == (rhs_begin + 1)->rank){
            rhs_pair_high = rhs_begin->rank;            
        }
        else if(rhs_begin->rank != (rhs_begin + 1)->rank && ((rhs_begin + 1) == rhs_end)){
            rhs_cards_without_pair.push_back(*(rhs_begin+1));
        }
        else
        {
            rhs_cards_without_pair.push_back(*rhs_begin);
        }
        rhs_begin++;
    }

    if (lhs_pair_high < rhs_pair_high)
    {
        return true;
    }
    else if (lhs_pair_high > rhs_pair_high)
    {
         return false;
    }
    else
    {
        return compare_xhigh(lhs_cards_without_pair.begin(), lhs_cards_without_pair.end(), rhs_cards_without_pair.begin(), rhs_cards_without_pair.end());
    }
}

//tie breaker helper functions if both hands are twopairs
bool compare_twopair(vector<Card<Suit, TexasholdemRank>>::iterator lhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator lhs_end, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_end)
{

    TexasholdemRank lhs_pair_first_high = TexasholdemRank::undefined;
    TexasholdemRank lhs_pair_second_high = TexasholdemRank::undefined;
    TexasholdemRank rhs_pair_first_high = TexasholdemRank::undefined;
    TexasholdemRank rhs_pair_second_high = TexasholdemRank::undefined;
    // these vectors includes non-paired cards, so that we may use it to calculate xhigh
    vector<Card<Suit, TexasholdemRank>> lhs_cards_without_pairs;
    vector<Card<Suit, TexasholdemRank>> rhs_cards_without_pairs;
   

    //Design Implementation : I am using next() here to safely check that next card is not equal to lhs_end. This is applied to rhs cardset as well.
    while(lhs_begin != lhs_end) {
  
    auto next = std::next(lhs_begin);
    if (next != lhs_end && lhs_begin->rank == next->rank) {
        // Found a pair
        if (lhs_pair_first_high == TexasholdemRank::undefined) {
            lhs_pair_first_high = lhs_begin->rank;
        } else if (lhs_pair_first_high != lhs_begin->rank && 
                   lhs_pair_second_high == TexasholdemRank::undefined) {
            lhs_pair_second_high = lhs_begin->rank;
        }
        // Skip the next card as it is part of the pair
        lhs_begin = std::next(next);
    } else {
        
        lhs_cards_without_pairs.push_back(*lhs_begin);
        ++lhs_begin;
    }
}
   
   while(rhs_begin != rhs_end) {

    auto next = std::next(rhs_begin);
    if (next != rhs_end && rhs_begin->rank == next->rank) {
        
        if (rhs_pair_first_high == TexasholdemRank::undefined) {
            rhs_pair_first_high = rhs_begin->rank;
        } else if (rhs_pair_first_high != rhs_begin->rank && 
                   rhs_pair_second_high == TexasholdemRank::undefined) {
            rhs_pair_second_high = rhs_begin->rank;
        }
        
        rhs_begin = std::next(next);
    } else {
        
        rhs_cards_without_pairs.push_back(*rhs_begin);
        ++rhs_begin;
    }
}

   
    if (lhs_pair_first_high < rhs_pair_first_high)
    {
        return true;
    }
    else if (lhs_pair_first_high == rhs_pair_first_high)
    {
        if(lhs_pair_second_high < rhs_pair_second_high){
            return true;
        } else if (lhs_pair_second_high == rhs_pair_second_high){
            return compare_xhigh(lhs_cards_without_pairs.begin(), lhs_cards_without_pairs.end(), rhs_cards_without_pairs.begin(), rhs_cards_without_pairs.end()); 
        }
    }
    return false;
}

//tie breaker helper functions if both hands are threeofakind
bool compare_threeofakind(vector<Card<Suit, TexasholdemRank>>::iterator lhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator lhs_end, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_end)
{
    TexasholdemRank lhs_three_of_a_kind_high = TexasholdemRank::undefined;
    TexasholdemRank rhs_three_of_a_kind_high = TexasholdemRank::undefined;

    // these vectors includes non-paired cards, so that we may use it to calculate xhigh
    vector<Card<Suit, TexasholdemRank>> lhs_cards_without_three_kind;
    vector<Card<Suit, TexasholdemRank>> rhs_cards_without_three_kind;

    vector<Card<Suit, TexasholdemRank>>::iterator lhs_cards_without_three_kind_begin = lhs_cards_without_three_kind.begin();
    vector<Card<Suit, TexasholdemRank>>::iterator lhs_cards_without_three_kind_end = lhs_cards_without_three_kind.end();
    vector<Card<Suit, TexasholdemRank>>::iterator rhs_cards_without_three_kind_begin = rhs_cards_without_three_kind.begin();
    vector<Card<Suit, TexasholdemRank>>::iterator rhs_cards_without_three_kind_end = rhs_cards_without_three_kind.end();


    while(lhs_begin != lhs_end-2){

        if(lhs_begin->rank == (lhs_begin+1)->rank && lhs_begin->rank == (lhs_begin+2)->rank){
            lhs_three_of_a_kind_high = lhs_begin->rank;
            // skips next two cards
            lhs_begin += 2;
        } else{
            lhs_cards_without_three_kind.push_back(*lhs_begin);
            lhs_begin++;
        }

    }
    while(rhs_begin != rhs_end-2){

        if(rhs_begin->rank == (rhs_begin+1)->rank && rhs_begin->rank == (rhs_begin+2)->rank){
            rhs_three_of_a_kind_high = rhs_begin->rank;
            // skips next two cards
            rhs_begin += 2;
        } else{
            rhs_cards_without_three_kind.push_back(*rhs_begin);
            rhs_begin++;
        }

    }
   
    if (lhs_three_of_a_kind_high < rhs_three_of_a_kind_high)
    {
        return true;
    }
    else if (lhs_three_of_a_kind_high == rhs_three_of_a_kind_high)
    {
        //@TODO - check if this has to be full house or something
        return compare_xhigh(lhs_cards_without_three_kind_begin, lhs_cards_without_three_kind_end,rhs_cards_without_three_kind_begin,rhs_cards_without_three_kind_end);
    }
    else
    {
        return false;
    }
}

//tie breaker helper functions if both hands are straight
bool compare_straight(vector<Card<Suit, TexasholdemRank>>::iterator lhs_begin, 
                  
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_begin
               ){

    
    if(lhs_begin->rank < rhs_begin->rank){
        return true;
    } else {
        return false;
    }
}

//tie breaker helper functions if both hands are flush
bool compare_flush(vector<Card<Suit, TexasholdemRank>>::iterator lhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator lhs_end, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_end){

    return compare_xhigh(lhs_begin,lhs_end,rhs_begin,rhs_end);
}

//tie breaker helper functions if both hands are fullhouse
bool compare_fullhouse(vector<Card<Suit, TexasholdemRank>>::iterator lhs_begin, 
                  
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_begin
                ){

    TexasholdemRank lhs_fullhouse_triple_high = TexasholdemRank::undefined;
    TexasholdemRank rhs_fullhouse_triple_high = TexasholdemRank::undefined;

    TexasholdemRank lhs_fullhouse_pair_high = TexasholdemRank::undefined;
    TexasholdemRank rhs_fullhouse_pair_high = TexasholdemRank::undefined;

    //Design Implementation : Given that hand has a full house and is sorted before this function call,
    //we can determine that if the rank of 2nd and 3rd card has different rank, first 2 cards is a pair and last 3 cards are triplet.
    //This also means that if the rank of 2nd and 3rd card has the same rank, first 3 cards is a triplet and last 2 cards are a pair.
    if((lhs_begin + 1)->rank == (lhs_begin + 2)->rank){
        lhs_fullhouse_triple_high = lhs_begin->rank;
        lhs_fullhouse_pair_high = (lhs_begin+3)->rank;
    } else {
        lhs_fullhouse_triple_high = (lhs_begin+2)->rank;
        lhs_fullhouse_pair_high =  lhs_begin->rank;

    }

     if((rhs_begin + 1)->rank == (rhs_begin + 2)->rank){
        rhs_fullhouse_triple_high = rhs_begin->rank;
        rhs_fullhouse_pair_high = (rhs_begin+3)->rank;
    } else {
        rhs_fullhouse_triple_high = (rhs_begin+2)->rank;
        rhs_fullhouse_pair_high =  rhs_begin->rank;

    }

    if(lhs_fullhouse_triple_high < rhs_fullhouse_triple_high){
        return true;
    }  else if(lhs_fullhouse_triple_high == rhs_fullhouse_triple_high){
            if(lhs_fullhouse_pair_high < rhs_fullhouse_pair_high){
                return true;
            } else{
                return false;
            }
    }
    else {
        return false;
    }


}

//tie breaker helper functions if both hands are straighflush
bool compare_straightflush(vector<Card<Suit, TexasholdemRank>>::iterator lhs_begin, 
                 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_begin
           ){



    if(lhs_begin->rank < rhs_begin->rank){
        return true;
    } else {
        return false;
    }

    return false;
}

//tie breaker helper functions if both hands are fourofakind
bool compare_fourofakind(vector<Card<Suit, TexasholdemRank>>::iterator lhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator lhs_end, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_begin, 
                   vector<Card<Suit, TexasholdemRank>>::iterator rhs_end){

    TexasholdemRank lhs_fourofakind_high = TexasholdemRank::undefined;
    TexasholdemRank rhs_fourofakind_high = TexasholdemRank::undefined;

    //I did not implement a case when both two players have same four of a kind, because based on structions we only draw 3 cards on the board.
     //instead of using hard coded distance between two pointers, I tried std::distance() in this case to see if it works. 
    while(std::distance(lhs_begin, lhs_end) >= 4){
        if(lhs_begin->rank == (lhs_begin +1)->rank && lhs_begin->rank == (lhs_begin +2)->rank && lhs_begin->rank == (lhs_begin +3)->rank){
            if(lhs_fourofakind_high == TexasholdemRank::undefined){
                lhs_fourofakind_high = lhs_begin->rank;
                break;
            }  
        }
        lhs_begin++;
    };

    while(std::distance(rhs_begin, rhs_end) >= 4){
        if(rhs_begin->rank == (rhs_begin +1)->rank && rhs_begin->rank == (rhs_begin +2)->rank && rhs_begin->rank == (rhs_begin +3)->rank){
            if(rhs_fourofakind_high == TexasholdemRank::undefined){
                rhs_fourofakind_high = rhs_begin->rank;
                break;
            }  
        }
        rhs_begin++;
    };
    
    if(lhs_fourofakind_high < rhs_fourofakind_high){
        return true;
    } else {
        return false;
    }

}


