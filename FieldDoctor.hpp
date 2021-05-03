//
// Created by nir son on 03/05/2021.
//

#ifndef CPP_TASK_4_FIELDDOCTOR_HPP
#define CPP_TASK_4_FIELDDOCTOR_HPP

#include "Player.hpp"

namespace pandemic {
    class FieldDoctor : public Player{
        public:
            FieldDoctor(Board& board, const std::string& city);
            ~FieldDoctor();

            Player& treat(const std::string&city) override;
    };
}

#endif //CPP_TASK_4_FIELDDOCTOR_HPP
