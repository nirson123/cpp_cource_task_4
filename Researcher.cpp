//
// Created by nir son on 03/05/2021.
//

#include "Researcher.hpp"
#include "Player.hpp"

using namespace pandemic;
using namespace std;


Researcher::Researcher(Board &board, const std::string& city) :
Player(board, city, "Researcher")
{
}

Researcher::~Researcher() = default;

Researcher& Researcher::discover_cure(const Color &color) {
    static const int number_of_cards_required = 5;

    int cards_of_color = 0;
    set<string> card_to_remove;
    for(const string& city_name : cards){
        if(board.cities[city_name].color == color){cards_of_color++; card_to_remove.insert(city_name);}
        if(cards_of_color == number_of_cards_required){break;}
    }
    if(cards_of_color < number_of_cards_required){
        throw logic_error{"not enough cards"};
    }

    bool cure_discovered = false;
    switch(color){
        case Color::Black: cure_discovered = board.is_black_cure_discovered; break;
        case Color::Red: cure_discovered = board.is_red_cure_discovered; break;
        case Color::Yellow: cure_discovered = board.is_yellow_cure_discovered; break;
        case Color::Blue: cure_discovered = board.is_blue_cure_discovered; break;
    }
    if(!cure_discovered){
        for(const string& city : card_to_remove){cards.erase(city);}
        switch(color){
            case Color::Black: board.is_black_cure_discovered = true; break;
            case Color::Red: board.is_red_cure_discovered = true; break;
            case Color::Yellow: board.is_yellow_cure_discovered = true; break;
            case Color::Blue: board.is_blue_cure_discovered = true; break;
        }
    }
    return *this;
}
