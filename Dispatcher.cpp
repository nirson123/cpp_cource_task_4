//
// Created by nir son on 03/05/2021.
//

#include "Dispatcher.hpp"

using namespace pandemic;
using namespace std;

Dispatcher::Dispatcher(pandemic::Board &board, const std::string &city) :
Player(board, city, "Dispatcher")
{
}

pandemic::Dispatcher::~Dispatcher() = default;

Dispatcher& pandemic::Dispatcher::fly_direct(const std::string &city) {
    if(board.cities.find(city) == board.cities.end()){
        throw invalid_argument{"city " + city + " is not on the board"};
    }

    if(board.cities[current_city].has_research_center){
        current_city = city;
        return *this;
    }


    if(cards.find(city) == cards.end() ){
        throw invalid_argument{"player does not have the right card!"};
    }

    cards.erase(city);
    current_city = city;
    return *this;
}