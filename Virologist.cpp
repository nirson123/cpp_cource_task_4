//
// Created by nir son on 03/05/2021.
//

#include "Virologist.hpp"

using namespace pandemic;
using namespace std;

Virologist::Virologist(Board &board, const string &city) :
Player(board, city, "Virologist")
{
}

Virologist::~Virologist() = default;

Player &Virologist::treat(const string &city) {
   if(board.cities.find(city) == board.cities.end()){
       throw invalid_argument{"city " + city + " not on board!"};
   }
   if(city != current_city){
       if(cards.find(city) != cards.end()){
           cards.erase(city);
       }
       else{
           throw invalid_argument{"player does not have the right card!"};
       }
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
