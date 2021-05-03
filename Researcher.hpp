//
// Created by nir son on 03/05/2021.
//

#ifndef CPP_TASK_4_RESEARCHER_HPP
#define CPP_TASK_4_RESEARCHER_HPP
#include "Player.hpp"
namespace pandemic {
    class Researcher : public Player {
        public:
            Researcher(Board& board, const std::string& city);
            ~Researcher();

            Researcher& discover_cure(const Color& color) override;
    };
}

#endif //CPP_TASK_4_RESEARCHER_HPP
