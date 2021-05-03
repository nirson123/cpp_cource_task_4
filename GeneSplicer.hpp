//
// Created by nir son on 03/05/2021.
//

#ifndef CPP_TASK_4_GENESPLICER_HPP
#define CPP_TASK_4_GENESPLICER_HPP

#include "Player.hpp"

namespace pandemic {
    class GeneSplicer : public Player{
        public:
            GeneSplicer(Board& board, const std::string& city);
            ~GeneSplicer();

            Player& discover_cure(const Color& color) override;
    };
}

#endif //CPP_TASK_4_GENESPLICER_HPP
