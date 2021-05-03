//
// Created by nir son on 03/05/2021.
//

#include "GeneSplicer.hpp"

using namespace pandemic;
using namespace std;

GeneSplicer::GeneSplicer(Board &board, const string &city):
Player(board, city, "GeneSplicer")
{
}

GeneSplicer::~GeneSplicer() = default;

Player &GeneSplicer::discover_cure(const Color &color) {
    static const int number_of_cards_required = 5;

    if(!board.cities[current_city].has_research_center){
        throw logic_error{"no research center in current city"};
    }

    int cards_count = 0;
    set<string> card_to_remove;
    for(const string& city_name : cards){
        cards_count++; card_to_remove.insert(city_name);
        if(cards_count == number_of_cards_required){break;}
    }
    if(cards_count < number_of_cards_required){
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
