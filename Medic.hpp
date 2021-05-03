//
// Created by nir son on 03/05/2021.
//

#ifndef CPP_TASK_4_MEDIC_HPP
#define CPP_TASK_4_MEDIC_HPP

#include "Player.hpp"

namespace pandemic {
    class Medic : public Player {
        public:
            Medic(Board& board, const std::string& city);
            ~Medic();

            void go_to(const std::string& city) override;
            Medic& treat(const std::string& city) override;

    };
}
#endif //CPP_TASK_4_MEDIC_HPP
