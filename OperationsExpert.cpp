//
// Created by nir son on 02/05/2021.
//

#include "OperationsExpert.hpp"
#include "Player.hpp"

using namespace pandemic;
using namespace std;

OperationsExpert::OperationsExpert(Board &board, const string& city) :
Player(board, city, "OperationsExpert")
{
}

OperationsExpert::~OperationsExpert() = default;

OperationsExpert& OperationsExpert::build(){
    if(!board.cities[current_city].has_research_center){
        board.cities[current_city].has_research_center = true;
    }
    return *this;
}
