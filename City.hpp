//
// Created by nir son on 01/05/2021.
//

#ifndef CPP_TASK_4_CITY_HPP
#define CPP_TASK_4_CITY_HPP

#include "Color.hpp"
#include <set>
#include <string>


namespace pandemic {

    class City{
        public:

            static std::string
                Algiers,
                Atlanta,
                Baghdad,
                Bangkok,
                Beijing,
                Bogota,
                BuenosAires,
                Cairo,
                Chennai,
                Chicago,
                Delhi,
                Essen,
                HoChiMinhCity,
                HongKong,
                Istanbul,
                Jakarta,
                Johannesburg,
                Karachi,
                Khartoum,
                Kinshasa,
                Kolkata,
                Lagos,
                Lima,
                London,
                LosAngeles,
                Madrid,
                Manila,
                MexicoCity,
                Miami,
                Milan,
                Montreal,
                Moscow,
                Mumbai,
                NewYork,
                Osaka,
                Paris,
                Riyadh,
                SanFrancisco,
                Santiago,
                SaoPaulo,
                Seoul,
                Shanghai,
                StPetersburg,
                Sydney,
                Taipei,
                Tehran,
                Tokyo,
                Washington;

            std::string name;
            std::set<std::string> neighbors;
            Color color;
            int disease_level;
            bool has_research_center;

            City(const std::string& name = "", const Color& color = Color::Black);
            City(const City& other);
            ~City();

            void add_nei(const std::string& nei_name);
    };



//    enum City {
//        Algiers,
//        Atlanta,
//        Baghdad,
//        Bangkok,
//        Beijing,
//        Bogota,
//        BuenosAires,
//        Cairo,
//        Chennai,
//        Chicago,
//        Delhi,
//        Essen,
//        HoChiMinhCity,
//        HongKong,
//        Istanbul,
//        Jakarta,
//        Johannesburg,
//        Karachi,
//        Khartoum,
//        Kinshasa,
//        Kolkata,
//        Lagos,
//        Lima,
//        London,
//        LosAngeles,
//        Madrid,
//        Manila,
//        MexicoCity,
//        Miami,
//        Milan,
//        Montreal,
//        Moscow,
//        Mumbai,
//        NewYork,
//        Osaka,
//        Paris,
//        Riyadh,
//        SanFrancisco,
//        Santiago,
//        SaoPaulo,
//        Seoul,
//        Shanghai,
//        StPetersburg,
//        Sydney,
//        Taipei,
//        Tehran,
//        Tokyo,
//        Washington
//    };
}

#endif //CPP_TASK_4_CITY_HPP
