//
// Created by nir son on 01/05/2021.
//

#ifndef CPP_TASK_4_PLAYER_HPP
#define CPP_TASK_4_PLAYER_HPP

#include <set>
#include <string>

#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"

namespace pandemic {
    class Player {

    protected:
        Board& board;
        std::set<std::string> cards;
        std::string current_city;
        std::string role_;

        Player(Board& board, const std::string& city, const std::string& role);

        ~Player();

        virtual void go_to(const std::string& city);

    public:
        virtual Player& drive(const std::string& city);

        virtual Player& fly_direct(const std::string&city);

        virtual Player& fly_charter(const std::string& city);

        virtual Player& fly_shuttle(const std::string& city);

        virtual Player& build();

        virtual Player& discover_cure(const Color& color);

        virtual Player& treat(const std::string&city);

        Player& take_card(const std::string& city);

        std::string role() const ;
    };
}

#endif //CPP_TASK_4_PLAYER_HPP
