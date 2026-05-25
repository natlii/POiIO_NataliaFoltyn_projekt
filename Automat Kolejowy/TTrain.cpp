#include<iostream>
#include<vector>
#include <string>
#include "TStation.h"
#include "TTrain.h"
#include <algorithm>

using namespace std;

TTrain::TTrain(std::string name)
{
    this->train_id = rand();
    this->name = name;
    delay = 0;
}

TTrain::TTrain(std::string name,int size, int start_time)
{
    this->train_id = rand();
    this->name = name;
    build_station_list(size,start_time);
    delay = 0;
}

TTrain::TTrain()
{
    this->train_id = rand();
    delay = 0;
    set_random_name();
}


void TTrain::set_random_name()
{
    this->name = TrainListNames[rand()%(TrainListNames.size()-1)];
}



void TTrain::set_current_time(int time)
{
    current_time = time; 
    if(rand()%100<5) delay++;
    
    if(rand()%100>98) delay--;
    if(delay<0) delay =0;
}

void TTrain::build_station_list(int size, int start_time)
{
    int dep_time = start_time;
    size = min(size,static_cast<int>(StationList.size()));
    vector<int> used_names;
    int id;
    bool can_go = false;
    for(int i = 0; i<size;i++)
    {   
        can_go = false;
        dep_time +=  rand()%30;
        departure_times.insert(departure_times.end(),dep_time);
        while (!can_go)
        {
            id = rand()%(StationList.size());
            auto it = find(used_names.begin(),used_names.end(),id);
            if(used_names.empty() || it == used_names.end())
            {
                station_list.insert(station_list.end(),StationList[id]);
                used_names.insert(used_names.end(),id);
                can_go = true;
            }
        }
    }
}

void TTrain::show_station_list()
{
    cout <<"\n\n == LISTA STACJI ==";
    for(int i = 0; i<static_cast<int>(station_list.size());i++)
    { 
        cout << "\n Stacja: "<< station_list[i].get_name()<<" || godz. odjazdu: " <<(departure_times[i]-departure_times[i]%60)/60<<":";
        if((departure_times[i]%60) < 10) cout<<"0";
        if((departure_times[i]%60) == 0) cout<<"0";
        cout<<departure_times[i]%60;
        if(get_curr_station().get_name() == station_list[i].get_name())
        {
            cout << "<-";
            if(delay>0)
            {
                cout<<"OPOZNIONY "<< delay<<" MINUT";
            }
        } 
    }
    cout<<"\n== KONIEC LISTY STACJI ==";
}

TStation TTrain::get_curr_station()
{
    for(int i = 1; i < departure_times.size(); i++)
    {
        if(departure_times[i]>current_time-delay)
        {
            return station_list[i-1];
        }
    }
    return station_list[0];
}

TStation TTrain::get_next_station()
{
    for(int i = 0; i < departure_times.size(); i++)
    {
        if(departure_times[i]>current_time-delay)
        {
            return station_list[i];
        }
    }
    return station_list[departure_times.size()-1];
}

std::vector<std::string> TrainListNames =
{
    "Gibki Cug",
    "Slazak", 
    "Wyczolkowski", 
    "Monorail 10",
    "Fast train 16",
    "Magnolia",
    "Oscypek",
    "Łukasiewicz",
    "Express kostuchna"
};

vector<TTrain*> TrainExtern;