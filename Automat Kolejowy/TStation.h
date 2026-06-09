#pragma once
#include<iostream>
#include<vector>
#include<string.h>

class TStation
{
private:
    // generated
    int station_id;
    // added from station list    
    std::string station_name;

    //experimental station position on map
    float pos_x;
    float pos_y;
    // grid -1f to 1f
public:
    // definition
    TStation(std::string station_name);

    // debug and values
    int get_id(){return station_id;};
    std::string get_name(){return station_name;};
};

extern std::vector<TStation> StationList;