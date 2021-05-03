//
// Created by nir son on 03/05/2021.
//

#include "Scientist.hpp"

using namespace pandemic;
using namespace std;

Scientist::Scientist(pandemic::Board &board, const std::string& city, int n) :
Player(board, city, "Scientist"), n(n)
{
}

Scientist::~Scientist() = default;

Scientist& Scientist::discover_cure(const pandemic::Color &color) {
    static const int number_of_cards_required = n;

    if(!board.cities[current_city].has_research_center){
        throw logic_error{"no research center in current city"};
    }

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
