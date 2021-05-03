//
// Created by nir son on 02/05/2021.
//

#include "City.hpp"

using namespace pandemic;
using namespace std;


        std::string
            City::Algiers = "Algiers",
            City::Atlanta = "Atlanta",
            City::Baghdad = "Baghdad",
            City::Bangkok = "Bangkok",
            City::Beijing = "Beijing",
            City::Bogota = "Bogota",
            City::BuenosAires = "BuenosAires",
            City::Cairo = "Cairo",
            City::Chennai = "Chennai",
            City::Chicago = "Chicago",
            City::Delhi = "Delhi",
            City::Essen = "Essen",
            City::HoChiMinhCity = "HoChiMinhCity",
            City::HongKong = "HongKong",
            City::Istanbul = "Istanbul",
            City::Jakarta = "Jakarta",
            City::Johannesburg = "Johannesburg",
            City::Karachi = "Karachi",
            City::Khartoum = "Khartoum",
            City::Kinshasa = "Kinshasa",
            City::Kolkata = "Kolkata",
            City::Lagos = "Lagos",
            City::Lima = "Lima",
            City::London = "London",
            City::LosAngeles = "LosAngeles",
            City::Madrid = "Madrid",
            City::Manila = "Manila",
            City::MexicoCity = "MexicoCity",
            City::Miami = "Miami",
            City::Milan = "Milan",
            City::Montreal = "Montreal",
            City::Moscow = "Moscow",
            City::Mumbai = "Mumbai",
            City::NewYork = "NewYork",
            City::Osaka = "Osaka",
            City::Paris = "Paris",
            City::Riyadh = "Riyadh",
            City::SanFrancisco = "SanFrancisco",
            City::Santiago = "Santiago",
            City::SaoPaulo = "SaoPaulo",
            City::Seoul = "Seoul",
            City::Shanghai = "Shanghai",
            City::StPetersburg = "StPetersburg",
            City::Sydney = "Sydney",
            City::Taipei = "Taipei",
            City::Tehran = "Tehran",
            City::Tokyo = "Tokyo",
            City::Washington = "Washington";

    void City::add_nei(const std::string& nei_name) {
        neighbors.insert(nei_name);
    }

    City::City(std::string name, Color color):
        name(name), color(color), disease_level(0), has_research_center(false)
    {
    }

    City::City(const City &other) {
        this->name = other.name;
        this->neighbors = set<string>(other.neighbors);
        this->color = other.color;
        this->disease_level = other.disease_level;
        this->has_research_center = other.has_research_center;
    }

    City::City() {
        City("", Color::Black);
    }


    City::~City() = default;