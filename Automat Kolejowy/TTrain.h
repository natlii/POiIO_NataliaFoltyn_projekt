#pragma once
#include<iostream>
#include<vector>
#include<string.h>
#include "TStation.h"

#define DEBUG false

class TTrain
{
private:
    // generated id
    int train_id;
    int current_time;

    // train name eg. Ślązak
    std::string name;

    // train station lists (stations, deprartures)
    std::vector<TStation> station_list;
    std::vector<int> departure_times; //in seconds

    // current delay (in seconds)
    int delay;

    // updating the train name
    void set_name(std::string name);
public:
    // definition
    TTrain(std::string name);
    TTrain(std::string name, int size, int start_time);
    TTrain();

    void set_random_name();
    void build_station_list(int size, int start_time);
    void show_station_list();
    std::string get_station_list();

    // debug and value checking
    int get_id() {return this->train_id;};
    void set_current_time(int time);
    std::string get_name() { return name; };

    //TStation get_name() {return this->name;};
    TStation get_curr_station();
    TStation get_next_station();
    TStation get_last_station(){return station_list[station_list.size()-1];};
    TStation get_index_station(int index) {return station_list[index];};

    std::string get_curr_station_disp(bool show_time);
    std::string get_next_station_disp(bool show_time);
    std::string get_last_station_disp(bool show_time);

    int get_curr_station_id();
    int get_next_station_id();
    int get_last_station_id();

    std::string time_to_string(int time);

    // delay menagement
    void add_delay(int delaya_a);
    void reset_delay();
};

extern std::vector<std::string> TrainListNames;
extern std::vector<TTrain*> TrainExtern;
