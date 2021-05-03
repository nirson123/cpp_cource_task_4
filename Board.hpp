//
// Created by nir son on 01/05/2021.
//

#ifndef CPP_TASK_4_BOARD_HPP
#define CPP_TASK_4_BOARD_HPP

#include <string>
#include <set>
#include <map>
#include <iostream>

#include "City.hpp"
#include "Color.hpp"

namespace pandemic {
    class Board {


        public:

            std::map<std::string, City> cities;

            bool is_red_cure_discovered, is_black_cure_discovered, is_yellow_cure_discovered, is_blue_cure_discovered;

            Board();

            ~Board();

            int &operator[](const std::string& city);

            bool is_clean();

            void remove_cures();

        friend std::ostream& operator<<(std::ostream& os, const Board& board);
    };

}
#endif //CPP_TASK_4_BOARD_HPP
