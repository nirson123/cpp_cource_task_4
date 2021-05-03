//
// Created by nir son on 01/05/2021.
//

#include "Player.hpp"
#include "Board.hpp"
#include <map>

using namespace pandemic;
using namespace std;

Player::Player(Board& board, const std::string& city, const string& role):
board(board), role_(role), current_city(city)
{
    if(board.cities.find(city) == board.cities.end()){
        throw invalid_argument{"city " + city + " is not on the board"};
    }
}

Player::~Player() = default;

Player& Player::drive(const std::string& city) {

    if(board.cities.find(city) == board.cities.end()){
        throw invalid_argument{"city " + city + " is not on the board"};
    }

    if(board.cities[current_city].neighbors.find(city) == board.cities[current_city].neighbors.end()){
        throw invalid_argument{"city " + city + " is not a neighbor of " + current_city};
    }

    go_to(city);
    return *this;
}

Player& Player::fly_direct(const std::string& city) {
    if(board.cities.find(city) == board.cities.end()){
        throw invalid_argument{"city " + city + " is not on the board"};
    }

    if(cards.find(city) == cards.end()){
        throw invalid_argument{"player does not have the right card!"};
    }

    cards.erase(city);
    go_to(city);
    return *this;
}

Player& Player::fly_shuttle(const std::string& city) {

    if(board.cities.find(city) == board.cities.end()){
        throw invalid_argument{"city " + city + " is not on the board"};
    }
    if(!board.cities[current_city].has_research_center || !board.cities[city].has_research_center){
        throw invalid_argument{"no research center"};
    }
    go_to(city);
    return *this;
}

Player& Player::fly_charter(const std::string& city) {

    if(board.cities.find(city) == board.cities.end()){
        throw invalid_argument{"city " + city + " is not on the board"};
    }

    if(cards.find(current_city) == cards.end()){
        throw invalid_argument{"player does not have the right card!"};
    }

    cards.erase(current_city);
    go_to(city);
    return *this;
}

Player& Player::build() {

    if(cards.find(current_city) == cards.end()){
        throw logic_error{"player does not have the right card!"};
    }

    if(!board.cities[current_city].has_research_center){
        cards.erase(current_city);
        board.cities[current_city].has_research_center = true;
    }
    return *this;
}


Player& Player::discover_cure(const Color& color){
    static const int number_of_cards_required = 5;
    
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

Player& Player::treat(const std::string& city) {

    if(city != current_city){
        throw invalid_argument{"not in " + city + "!"};
    }

    bool cure_discovered = false;
    switch(board.cities[current_city].color){
        case Color::Black: cure_discovered = board.is_black_cure_discovered; break;
        case Color::Red: cure_discovered = board.is_red_cure_discovered; break;
        case Color::Yellow: cure_discovered = board.is_yellow_cure_discovered; break;
        case Color::Blue: cure_discovered = board.is_blue_cure_discovered; break;
    }

    if(board[current_city] == 0){
        throw logic_error{"no infection in city"};
    }
    if(cure_discovered){
        board[current_city] = 0;
    }
    else{
        board[current_city]--;
    }
    return *this;
}

Player& Player::take_card(const std::string& city) {
    if(board.cities.find(city) == board.cities.end()){
        throw invalid_argument{"city " + city + " is not on the board"};
    }
    cards.insert(city);
    return *this;
}

std::string Player::role() const{
    return this->role_;
}

void Player::go_to(const string &city) {

    if(board.cities.find(city) == board.cities.end()){
        throw invalid_argument{"city " + city + " is not on the board"};
    }

    current_city = city;
}
