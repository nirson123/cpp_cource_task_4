//
// Created by nir son on 03/05/2021.
//

#include "FieldDoctor.hpp"
using namespace pandemic;
using namespace std;

FieldDoctor::FieldDoctor(Board &board, const string &city) :
Player(board, city, "FieldDoctor")
{
}

FieldDoctor::~FieldDoctor() = default;

Player &FieldDoctor::treat(const string &city) {
    if(city != current_city && board.cities[current_city].neighbors.find(city) == board.cities[current_city].neighbors.end()){
        throw invalid_argument{"can't reach " + city + "!"};
    }

    bool cure_discovered = false;
    switch(board.cities[city].color){
        case Color::Black: cure_discovered = board.is_black_cure_discovered; break;
        case Color::Red: cure_discovered = board.is_red_cure_discovered; break;
        case Color::Yellow: cure_discovered = board.is_yellow_cure_discovered; break;
        case Color::Blue: cure_discovered = board.is_blue_cure_discovered; break;
    }

    if(board[city] == 0){
        throw logic_error{"no infection in city"};
    }
    if(cure_discovered){
        board[city] = 0;
    }
    else{
        board[city]--;
    }
    return *this;
}
