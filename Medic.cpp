//
// Created by nir son on 03/05/2021.
//

#include "Medic.hpp"

using namespace pandemic;
using namespace std;

Medic::Medic(Board &board, const string &city) :
Player(board, city, "Medic")
{
}

Medic::~Medic() = default;

void Medic::go_to(const string& city) {
    Player::go_to(city);
    if(board.cities[city].color == Color::Red && board.is_red_cure_discovered){board[city] = 0;}
    if(board.cities[city].color == Color::Black && board.is_black_cure_discovered){board[city] = 0;}
    if(board.cities[city].color == Color::Blue && board.is_blue_cure_discovered){board[city] = 0;}
    if(board.cities[city].color == Color::Yellow && board.is_yellow_cure_discovered){board[city] = 0;}
}

Medic& Medic::treat(const std::string& city) {
    if(city != current_city){
        throw invalid_argument{"not in " + city + "!"};
    }

    if(board[current_city] == 0){
        throw logic_error{"no infection in city"};
    }
        board[current_city] = 0;
    return *this;
}
