//
// Created by nir son on 03/05/2021.
//

#ifndef CPP_TASK_4_SCIENTIST_HPP
#define CPP_TASK_4_SCIENTIST_HPP
#include "Player.hpp"

namespace pandemic {
    class Scientist : public Player {
        public:
            int n;

            Scientist(Board &board, const std::string& city, int n);
            ~Scientist();

            Scientist& discover_cure(const Color& color) override;
    };

}
#endif //CPP_TASK_4_SCIENTIST_HPP
