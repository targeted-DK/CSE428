// GoFishGame_T.cpp
// Author : Donggyu Kim, donggyukim@wustl.edu
// Go Fish Game Template source file for different deck types
#include "GoFishGame_T.h"

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <type_traits>

#define START_COUNTER 0
#define EDGE_CASE 0
#define SUCCESS 0
#define OFFSET_ONE 1
#define OFFSET_THREE 3
#define SMALL_GAME_PLAYER_NUM 2
#define SMALL_GAME_CARDS 7
#define LARGE_GAME_CARDS 5
#define NUM_CARDS_FOR_BOOK 4

using namespace std;

template <>
GoFishGame<Suit, TexasholdemRank, Texasholdem>::GoFishGame(int argc, const char *argv[]) : Game(argc, argv)
{

    // 16.The body of the constructor should check that there are at least 4 cards of each rank in the deck, and if not it should throw an exception.
    // Design Implementation : I created an array of ranks using undefined value, as all decks have undefined as the last enum value in its enum struct.
    // index refers to each rank, so I can safely add each card with a certain rank by converting enum value to int by using static cast
    // Then, as suggested by the instructions, I used count_if and lambda function as a predicate to check if there are at least 4 cards for each rank.
    this->total_player_num = argc - OFFSET_THREE;

    int count_rank_cards[static_cast<int>(TexasholdemRank::undefined)] = {START_COUNTER};
    this->go_fish_game_deck = Texasholdem();
    this->player_hands.resize(this->total_player_num);
    this->player_books_count.resize(this->total_player_num);
    this->books.resize(this->total_player_num);
    this->names.resize(this->total_player_num);

    for (int player = OFFSET_THREE; player < argc; player++)
    {
        CardSet<Suit, TexasholdemRank> new_hand;
        this->player_hands.push_back(new_hand);
        this->names.at(player - OFFSET_THREE) = argv[player];
    }

    for (auto it = go_fish_game_deck.begin(); it < go_fish_game_deck.end(); it++)
    {

        count_rank_cards[static_cast<int>(it->rank)]++;
    }

    bool not_enough_cards = count_if(count_rank_cards, (count_rank_cards + static_cast<int>(TexasholdemRank::undefined)), [](int i)
                                     { return i < 4; });

    if (not_enough_cards)
    {

        throw std::invalid_argument("Not enough cards to play Go Fish Game in the Texasholdem deck");
    }
};

template <>
GoFishGame<Color, UnoRank, Uno>::GoFishGame(int argc, const char *argv[]) : Game(argc, argv)
{

    this->total_player_num = argc - OFFSET_THREE;
    int count_rank_cards[static_cast<int>(UnoRank::undefined)] = {START_COUNTER};
    this->go_fish_game_deck = Uno();
    this->player_hands.resize(this->total_player_num);
    this->player_books_count.resize(this->total_player_num);
    this->books.resize(this->total_player_num);
    this->names.resize(this->total_player_num);

    for (int player = OFFSET_THREE; player < argc; player++)
    {

        CardSet<Color, UnoRank> new_hand;
        this->player_hands.push_back(new_hand);
        this->names.at(player - OFFSET_THREE) = argv[player];
    }

    for (auto it = go_fish_game_deck.begin(); it < go_fish_game_deck.end(); it++)
    {

        count_rank_cards[static_cast<int>(it->rank)]++;
    }

    bool not_enough_cards = count_if(count_rank_cards, (count_rank_cards + static_cast<int>(UnoRank::undefined)), [](int i)
                                     { return i < 4; });

    if (not_enough_cards)
    {

        throw std::invalid_argument("Not enough cards to play Go Fish Game in the Uno deck");
    }



}

template <>
GoFishGame<Suit, PinochleRank, Pinochle>::GoFishGame(int argc, const char *argv[]) : Game(argc, argv)
{

    this->total_player_num = argc - OFFSET_THREE;

    int count_rank_cards[static_cast<int>(PinochleRank::undefined)] = {START_COUNTER};
    this->go_fish_game_deck = Pinochle();
    this->player_hands.resize(this->total_player_num);
    this->player_books_count.resize(this->total_player_num);
    this->books.resize(this->total_player_num);
    this->names.resize(this->total_player_num);

    for (int player = OFFSET_THREE; player < argc; player++)
    {
         cout << "current player : "<< player << endl; 
        CardSet<Suit, PinochleRank> new_hand;
        this->player_hands.push_back(new_hand);
        this->names.at(player - OFFSET_THREE) = argv[player];
    }

    for (auto it = go_fish_game_deck.begin(); it < go_fish_game_deck.end(); it++)
    {

        count_rank_cards[static_cast<int>(it->rank)]++;
    }

    bool not_enough_cards = count_if(count_rank_cards, (count_rank_cards + static_cast<int>(PinochleRank::undefined)), [](int i)
                                     { return i < 4; });

    if (not_enough_cards)
    {

        throw std::invalid_argument("Not enough cards to play Go Fish Game in the Pinochle deck");
    }
}

/** 
 * collects_books for current player if there are 4 cards with same rank
 * @param player_number current player number
 * @return a boolean value if 4 cards with same rank are collected
 */
template <typename suit_type, typename rank_type, typename deck_type>
bool GoFishGame<suit_type, rank_type, deck_type>::collect_books(int player_number)
{
    int count_rank_cards[static_cast<int>(rank_type::undefined)] = {START_COUNTER};
    

    CardSet<suit_type, rank_type> &player_card_set = this->player_hands.at(player_number);
    for (Card<suit_type, rank_type> card : player_card_set)
    {
       
        count_rank_cards[static_cast<int>(card.rank)]++;
    }

    for (auto i = START_COUNTER; i < static_cast<int>(rank_type::undefined); i++)
    {
        if (count_rank_cards[i] == NUM_CARDS_FOR_BOOK)
        {

            rank_type rank = static_cast<rank_type>(i);

            // #18.Create a function object of type <bool(Card<S, R>&)> called predicate and initialize it
            function<bool(Card<suit_type, rank_type> &)> predicate = [rank](Card<suit_type, rank_type> &card) -> bool
            {
                return card.rank == rank;
            };
            this->books[player_number].collect_if(player_card_set, predicate); 
            this->player_books_count[player_number] += 1;

            return true;
        }
    }

    return false;
};

/** 
 * a step by step precedure for a single game turn for the current player
 * @param player_number current player number
 * @return a boolean value if current turn is finished or not
 */
template <typename suit_type, typename rank_type, typename deck_type>
bool GoFishGame<suit_type, rank_type, deck_type>::turn(int player_number)
{

    int user_input_player_number = -1;
    int user_input_rank_type;


    cout << "--------Current hands and books of player name(number #)-------- " << endl
         << endl;

    for (auto cur_player_num = START_COUNTER; cur_player_num < this->total_player_num; cur_player_num++)
    {
        if (find(this->lost_players.begin(), this->lost_players.end(), cur_player_num) != this->lost_players.end())
        {
            cout << "Player " << this->names[cur_player_num] << "(number " << cur_player_num << ")"
                 << "'s hands and books : [This player is eliminated from the game.]" << endl;
        }
        else
        {
            cout << "Player " << this->names[cur_player_num] << "(number " << cur_player_num << ")"
                 << "'s hands and books : " << endl;
        }

        cout << "Hand : ";
        for (const auto &card : player_hands[cur_player_num].getCards())
        {
            cout << card << " ";
        }

        cout << endl;

        CardSet<suit_type, rank_type> &player_book = this->books[cur_player_num];
        cout << "Books Collected : " << this->player_books_count[cur_player_num] << endl;

        int book_counter = START_COUNTER;
        for (Card<suit_type, rank_type> &card : player_book)
        {
            if (book_counter == START_COUNTER)
            {
                cout << card.rank << " : ";
            }
            cout << card << " ";
            book_counter++;
            if (book_counter == NUM_CARDS_FOR_BOOK)
            {
                book_counter = START_COUNTER;
                cout << endl;
            }
        }
        cout << endl;
        cout << "-------------------------------------------------------- " << endl
             << endl;
    }
    cout << endl;
    cout << "[ Game Log ]" << endl;

    cout << "Player " << this->names.at(player_number) << "(number " << player_number << ")"
         << "'s turn. " << endl;
    cout << endl;

    if (find(this->lost_players.begin(), this->lost_players.end(), player_number) != this->lost_players.end())
    {
        cout << "Player " << this->names[player_number] << "(number " << player_number << ")"
             << " is eliminated from the game. Skipping this player..." << endl;
        return false;
    }
    cout << "Enter the player number from 0 to " << this->total_player_num - OFFSET_ONE << " to ask cards from :";
    cin >> user_input_player_number;

    while (user_input_player_number >= this->total_player_num || user_input_player_number < EDGE_CASE || player_number == user_input_player_number || find(this->lost_players.begin(), this->lost_players.end(), user_input_player_number) != this->lost_players.end())
    {

        cout << endl;
        cout << "[ Game Log ]" << endl;

        // https://stackoverflow.com/questions/27003967/how-to-check-if-cin-is-int-in-c
        // Dealing with issue where loop runs infinitely when the user mistakenly enters non-numeric value
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            user_input_player_number = -1;
        }
        if (player_number == user_input_player_number)
        {
            cout << "You cannot ask yourself for cards" << endl;
        }
        else if (find(this->lost_players.begin(), this->lost_players.end(), user_input_player_number) != this->lost_players.end())
        {
            cout << "This player is eliminated from this game." << endl;
        }
        else
        {
            cout << "Invalid player number." << endl;
        }
        cout << endl;
        cout << "Enter the player number to ask from 0 to " << this->total_player_num - OFFSET_ONE << " :";
        cin >> user_input_player_number;
    }

    // https://en.cppreference.com/w/cpp/types/is_same
    cout << endl;
    cout << "[ Game Log ]" << endl;
    if (is_same<rank_type, PinochleRank>::value)
    {
        cout << "Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask" << endl;

        cin >> user_input_rank_type;
        auto input_rank = static_cast<PinochleRank>(user_input_rank_type);

        while (!(input_rank == PinochleRank::nine || input_rank == PinochleRank::jack || input_rank == PinochleRank::queen ||
                 input_rank == PinochleRank::king || input_rank == PinochleRank::ten || input_rank == PinochleRank::ace))
        {
            cout << "Invalid rank type." << endl;
            cout << "Enter the rank of card in Pinochle (nine (0), jack (1), queen (2), king (3), ten (4), ace (5)) to ask" << endl;
            cin >> user_input_rank_type;
            input_rank = static_cast<PinochleRank>(user_input_rank_type);
        }
    }

    else if (is_same<rank_type, TexasholdemRank>::value)
    {
        cout << "Enter the rank of card in Texasholdem (two (0), three (1), four (2), five (3), six (4), seven (5), eight (6), nine (7), jack (8), queen (9), king (10), ten (11), ace (12)) to ask" << endl;
        cout << "Ex) integer 0 indicates Rank of Two in Texasholdem" << endl;
        cin >> user_input_rank_type;
        auto input_rank = static_cast<TexasholdemRank>(user_input_rank_type);

        while (!(input_rank == TexasholdemRank::two || input_rank == TexasholdemRank::three || input_rank == TexasholdemRank::four || input_rank == TexasholdemRank::five ||
                 input_rank == TexasholdemRank::six || input_rank == TexasholdemRank::seven || input_rank == TexasholdemRank::eight || input_rank == TexasholdemRank::nine ||
                 input_rank == TexasholdemRank::jack || input_rank == TexasholdemRank::queen ||
                 input_rank == TexasholdemRank::king || input_rank == TexasholdemRank::ten || input_rank == TexasholdemRank::ace))
        {
            cout << "Invalid rank type." << endl;
            cout << "Enter the rank of card in Texasholdem (two (0), three (1), four (2), five (3), six (4), seven (5), eight (6), nine (7), jack (8), queen (9), king (10), ten (11), ace (12)) to ask" << endl;
            cout << "Ex) integer 0 indicates Rank of Two in Texasholdem" << endl;
            cin >> user_input_rank_type;
            input_rank = static_cast<TexasholdemRank>(user_input_rank_type);
        }
    }

    else if (is_same<rank_type, UnoRank>::value)
    {
        cout << "Enter the rank of card in Uno (zero (0), one (1), two (2), three (3), four (4), five (5), six (6), seven (7), eight (8), nine (9), skip(S) (10), reverse(R) (11), drawtwo(D2) (12), drawfour(D4) (13), wild(W) (14), blank(B) (15)) to ask" << endl;

        cin >> user_input_rank_type;
        auto input_rank = static_cast<UnoRank>(user_input_rank_type);

        while (!(input_rank == UnoRank::zero || input_rank == UnoRank::one || input_rank == UnoRank::two ||
                 input_rank == UnoRank::three || input_rank == UnoRank::four || input_rank == UnoRank::five ||
                 input_rank == UnoRank::six || input_rank == UnoRank::seven || input_rank == UnoRank::eight ||
                 input_rank == UnoRank::nine ||
                 input_rank == UnoRank::skip || input_rank == UnoRank::reverse ||
                 input_rank == UnoRank::drawtwo || input_rank == UnoRank::drawfour || input_rank == UnoRank::wild ||
                 input_rank == UnoRank::blank))
        {
            cout << "Invalid rank type." << endl;
            cout << "Enter the rank of card in Uno (zero (0), one (1), two (2), three (3), four (4), five (5), six (6), seven (7), eight (8), nine (9), skip(S) (10), reverse(R) (11), drawtwo(D2) (12), drawfour(D4) (13), wild(W) (14), blank(B) (15)) to ask" << endl;
            cin >> user_input_rank_type;
            input_rank = static_cast<UnoRank>(user_input_rank_type);
        }
    }

    CardSet<suit_type, rank_type> &my_set = this->player_hands.at(player_number);
    CardSet<suit_type, rank_type> &other_set = this->player_hands.at(user_input_player_number);


    bool gotCard = false;
    if (!my_set.is_empty())
    {
        gotCard = my_set.request(other_set, static_cast<rank_type>(user_input_rank_type));
        if (other_set.is_empty())
        {
            this->lost_players.push_back(user_input_player_number);
            cout << "Player " << this->names[user_input_player_number] << "(number " << user_input_player_number << ")"
                 << " is eliminated from the game!" << endl;
        }
    }

    if (gotCard)
    {
        cout << endl;
        cout << "[ Game Log ]" << endl;
        cout << "Player " << this->names.at(player_number) << "(number " << player_number << ")"
             << " collected rank of " << static_cast<rank_type>(user_input_rank_type) << " card from player " << this->names.at(user_input_player_number) << endl;
        cout << endl;

        while (collect_books(player_number))
        {
             // This is left empty to indicate that the same player keeps playing after collecting books
        }
        //Player plays another turn
        return true; 
    }
    else
    {

        if (!this->go_fish_game_deck.is_empty())
        {
            cout << endl;
            cout << "[ Game Log ]" << endl;
            cout << "Player " << this->names.at(player_number) << "(number " << player_number << ") called "
                 << "Go Fish!" << endl;

            this->go_fish_game_deck >> this->player_hands.at(player_number);
            int old_book_num = this->player_books_count.at(player_number);

            auto drawnCard = player_hands[player_number].getCards()[player_hands[player_number].getCards().size() - 1];
            cout << "Player " << this->names.at(player_number) << "(number " << player_number << ") draws a card " << drawnCard << " from the deck" << endl;
            
            cout << "Cards left in the Deck : " << this->go_fish_game_deck.end() - this->go_fish_game_deck.begin() << " cards." << endl
                 << endl;

            while (collect_books(player_number))
            {
                // This is left empty to indicate that the same player keeps playing after collecting books
            }

            // After moving the a book from the player's hand into their collection of books, return true.
            if (this->player_books_count.at(player_number) != old_book_num)
            {
                return false; 
            }

            return false;
        }

        // game ends
        else
        {
            return false;
        }
    }
}

/** 
 * a function that deals cards to each players
 * @return a boolean value if current turn is finished or not
 */
template <typename suit_type, typename rank_type, typename deck_type>
void GoFishGame<suit_type, rank_type, deck_type>::deal()
{

    this->go_fish_game_deck.shuffle();
    this->player_hands.resize(this->names.size());

    int cards_per_player = (this->names.size() > SMALL_GAME_PLAYER_NUM) ? LARGE_GAME_CARDS : SMALL_GAME_CARDS;
    
    for (int i = START_COUNTER; i < cards_per_player; i++)
    {
        for (auto &player_hand : this->player_hands)
        {
            if (!go_fish_game_deck.is_empty())
            {
                go_fish_game_deck >> player_hand;
              
            }
        }
    }
    return;
}

template <typename suit_type, typename rank_type, typename deck_type>
int GoFishGame<suit_type, rank_type, deck_type>::play()
{

    this->deal();
    bool is_game_started = true;

    int cur_round = START_COUNTER;
    while (is_game_started)
    {
        
        for (auto player = START_COUNTER; player < this->total_player_num; player++)
        {

            // Keep running game until a round ends or there is only 1 player left
            while (this->turn(player))
            {
                collect_books(player);
                if (this->total_player_num - this->lost_players.size() < 2)
                {
                    is_game_started = false;
                    break;
                }
            }
        }

        cout << "Round " << cur_round << " has ended. " << endl;
        cur_round++;
        cout << "-------------------------------------------------------- " << endl;
       

        if ((this->go_fish_game_deck.is_empty()))
        {
            cout << "Deck ran out of cards! Game Ends. Calculating final scores..." << endl;

            is_game_started = false;
        } else if((this->total_player_num - this->lost_players.size() < 2)){
            cout << "Only one player remains in this game. Game Ends. Calculating final scores..." << endl;
             is_game_started = false;
        }
    }

    // https://en.cppreference.com/w/cpp/algorithm/max_element
    int high_score = *std::max_element(player_books_count.begin(), player_books_count.end());

    vector<int> check_tie;

    for (auto player = START_COUNTER; player < this->total_player_num; player++)
    {
        if (this->player_books_count.at(player) == high_score)
        {
            check_tie.push_back(player);
        }
    }

    cout << "           RESULT          " << endl;
    cout << "===================================" << endl;
    for (size_t player = START_COUNTER; player < check_tie.size(); player++)
    {
        cout << "Player " << this->names.at(player) << "(" << player << ") : "
             << " collected most books"
             << "(" << high_score << " books)" << endl;
    }
    cout << "===================================" << endl;

    return SUCCESS;
}
