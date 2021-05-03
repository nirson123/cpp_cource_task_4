//
// Created by nir son on 01/05/2021.
//

#include "Board.hpp"
#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <exception>

using namespace pandemic;
using namespace std;


Board::Board():
        is_red_cure_discovered(false), is_black_cure_discovered(false),
        is_yellow_cure_discovered(false), is_blue_cure_discovered(false)
{

    ifstream cities_file{"cities_map.txt"};
    if(!cities_file.is_open()){exit(1);}

    map<string, Color> colors;
    colors["Black"] = Color::Black; colors["Blue"] = Color::Blue; colors["Yellow"] = Color::Yellow; colors["Red"] = Color::Red;
    string name;
    string color;
    string nei;
    string line;

    while(getline(cities_file, line)){
        istringstream line_stream{line};
        line_stream >> name >> color;
        City city{name, colors[color]};
        while(line_stream >> nei){
            city.add_nei(nei);
        }
        this->cities[name] = city;
    }

    cities_file.close();
}

Board::~Board() = default;

int& Board::operator[](const string& city) {

    if(cities.find(city) == cities.end()){
        throw invalid_argument{"city does not exist"};
    }

    return cities[city].disease_level;
}

ostream& pandemic::operator<<(ostream& os, const Board& board) {

        bool is_any_disease = false;
        for (auto[name, city] : board.cities) {
            if (city.disease_level != 0) {
                cout << name << " : disease level = " << city.disease_level << endl;
                is_any_disease = true;
            }
        }
        if(is_any_disease){cout << "The rest of the cities are clean!" << endl << endl;}
        else{cout << "all cities are clean!!" << endl << endl;}



    bool is_any_research_centers = false;
    cout << "research centers : ";
    for(auto [name, city] : board.cities){
        if(city.has_research_center){
            cout << name + " ";
            is_any_research_centers = true;
        }
    }
    if(!is_any_research_centers){cout << "None";}
    cout << endl << endl;

    bool is_any_cure = false;
    cout << "discovered cures : ";
    if(board.is_black_cure_discovered){cout << "Black "; is_any_cure = true;}
    if(board.is_red_cure_discovered){cout << "Red "; is_any_cure = true;}
    if(board.is_yellow_cure_discovered){cout << "Yellow "; is_any_cure = true;}
    if(board.is_blue_cure_discovered){cout << "Blue "; is_any_cure = true;}
    if(!is_any_cure){cout << "None";}
    cout << endl;

    return os;
}

bool Board::is_clean(){
    for(auto [name, city] : cities){
        if(city.disease_level != 0){return false;}
    }
    return true;
}

void Board::remove_cures() {
    is_red_cure_discovered = false;
    is_black_cure_discovered = false;
    is_yellow_cure_discovered = false;
    is_blue_cure_discovered = false;
}













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

City::City(const std::string& name, const Color& color):
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


City::~City() = default;
