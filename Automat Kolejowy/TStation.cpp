#include<iostream>
#include<vector>
#include "TStation.h"

using namespace std;

TStation::TStation(std::string name)
{   
    this->station_name = name;

    // generate a seeded id based on name || TO DO
    this->station_id = rand();
}

vector<TStation> StationList = 
{
    TStation("Bydgoszcz"),
    TStation("Warszawa Centralna"),
    TStation("Katowice"),
    TStation("Kutno"),
    TStation("Wroclaw"),
    TStation("Krakow"),
    TStation("Poznan"),
    TStation("Gdansk"),
    TStation("Gdynia"),
    TStation("Rzeszow"),
    TStation("Lodz"),
    TStation("Wieden"),
    TStation("Berlin"),
    TStation("Krzeszowice"),
    TStation("Londyn (ten w polsce)"),
    TStation("Wies"),
    TStation("Bohumin"),
    TStation("Bochnia"),
    TStation("Praga"),
    TStation("Koziogorki"),
    TStation("Wejcherowo"),
    TStation("Tarnow"),
    TStation("Lowczowek"),
    TStation("Krasnik"),
    TStation("Monachium"),
    TStation("Miajimo"),
    TStation("Nowy jork (w polsce)"),
    TStation("Walencja"),
    TStation("Rzym"),
    TStation("Trojmiasto"),
    TStation("Szczecin"),
    TStation("Mala wies"),
    TStation("Szczebrzeszyn"),
    TStation("Kostuchna"),
    TStation("Piotrowice"),
    TStation("Swietochlowice"),
    TStation("Bedzin"),
    TStation("Ruda Slaska"),
    TStation("Myslowice"),
    TStation("Czestochowa"),
    TStation("Siemianowice Slaskie"),
    TStation("Sosnowiec"),
    TStation("Torun"),
    TStation("Zakopane")

};
