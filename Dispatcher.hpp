//
// Created by nir son on 03/05/2021.
//

#ifndef CPP_TASK_4_DISPATCHER_HPP
#define CPP_TASK_4_DISPATCHER_HPP

#include "Player.hpp"
namespace pandemic {
    class Dispatcher : public Player {

        public:
            Dispatcher(Board &board, const std::string& city);
            ~Dispatcher();

            Dispatcher& fly_direct(const std::string&city) override;
    };
}

#endif //CPP_TASK_4_DISPATCHER_HPP
