//
// Created by nir son on 02/05/2021.
//

#ifndef CPP_TASK_4_OPERATIONSEXPERT_HPP
#define CPP_TASK_4_OPERATIONSEXPERT_HPP

#include "City.hpp"
#include "Player.hpp"

namespace pandemic {
    class OperationsExpert : public Player {

    public:
        OperationsExpert(Board& board, const std::string& city);

        ~OperationsExpert();

        OperationsExpert& build() override;
    };

}
#endif //CPP_TASK_4_OPERATIONSEXPERT_HPP
