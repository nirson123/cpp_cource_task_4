//
// Created by nir son on 03/05/2021.
//

#ifndef CPP_TASK_4_VIROLOGIST_HPP
#define CPP_TASK_4_VIROLOGIST_HPP

#include "Player.hpp"

namespace pandemic {
    class Virologist : public Player{
        public:
            Virologist(Board& board, const std::string& city);
            ~Virologist();

            Player& treat (const std::string& city) override;
    };
}

#endif //CPP_TASK_4_VIROLOGIST_HPP
