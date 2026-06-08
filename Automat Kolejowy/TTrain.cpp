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
    furthest_station = 0;
    faultyness = rand() % 6;
}

TTrain::TTrain(std::string name,int size, int start_time)
{
    this->train_id = rand();
    this->name = name;
    build_station_list(size,start_time);
    delay = 0;
    furthest_station = 0;
    faultyness = rand() % 6;
}

TTrain::TTrain()
{
    this->train_id = rand();
    delay = 0;
    set_random_name();
    furthest_station = 0;
    faultyness = rand() % 6;
}


void TTrain::set_random_name()
{
    this->name = TrainListNames[rand()%(TrainListNames.size()-1)];
}



void TTrain::set_current_time(int time)
{
    current_time = time; 
    if (get_curr_station().get_name() != get_last_station().get_name())
    {
        if (rand() % 100 < faultyness)
        {
            if (get_curr_station().get_name() == "Warszawa Centralna")
            {
                delay += 15;
            }
            delay++;
        }
        if (rand() % 100 > 98) delay--;
        if (delay < 0) delay = 0;
    }
    furthest_station = max(get_curr_station_id(),furthest_station);

    
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

void TTrain::build_station_list(int size, int start_time,TStation start_station)
{
    delay = 0;
    furthest_station = 0;
    build_station_list(size, start_time);
    StationList[0] = start_station;
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

std::string TTrain::get_station_list()
{
    std::string text =  "\nTrasa: ";
    for (int i = 0; i < static_cast<int>(station_list.size());i++)
    {
        text += "\n Stacja: ";
        text += station_list[i].get_name();
        text += " \t\t\t|| godz. odjazdu: ";
        text += to_string((departure_times[i] - departure_times[i] % 60) / 60);
        text += ":";
        if ((departure_times[i] % 60) < 10) text += "0";
        if ((departure_times[i] % 60) == 0) text += "0";
        text += to_string(departure_times[i] % 60);
        if (get_curr_station().get_name() == station_list[i].get_name())
        {
            text += "<-";
            if (delay > 0)
            {
                text += "OPOZNIONY ";
                text += to_string(delay);
                text += " MINUT";
            }
        }
    }
    return text;
}

TStation TTrain::get_curr_station()
{
    return station_list[get_curr_station_id()];
}

TStation TTrain::get_next_station()
{
    return station_list[get_next_station_id()];
}

std::string TTrain::get_curr_station_disp(bool show_time)
{
    int id = get_curr_station_id();
    std::string return_string = station_list[id].get_name();
    if (show_time)
    {
        return_string = return_string + " -> Odjazd: ";
        if (delay > 0)
        {
            return_string = return_string + "    (opozniony " + to_string(delay) + " minut) " + time_to_string(departure_times[id] + delay);
        }
        else
        {
            return_string = return_string + time_to_string(departure_times[id]);
        }
    }
    return return_string;
}

std::string TTrain::get_next_station_disp(bool show_time)
{
    int id = get_next_station_id();
    std::string return_string = station_list[id].get_name();
    if (show_time)
    {
        return_string = return_string + " -> Odjazd: ";
        if (delay > 0)
        {
            return_string = return_string + "    (opozniony " +to_string(delay) + " minut) " + time_to_string(departure_times[id] + delay);
        }
        else
        {
            return_string = return_string + time_to_string(departure_times[id]);
        }
    }
    return return_string;
}

int TTrain::get_curr_station_id()
{
    for (int i = 1; i < departure_times.size(); i++)
    {
        if (departure_times[i] > current_time - delay)
        {
            i = max(i, furthest_station);
            return (i);
        }
    }
    return (departure_times.size() - 1);
}

int TTrain::get_next_station_id()
{
    for (int i = 2; i < departure_times.size()-1; i++)
    {
        if (departure_times[i] > current_time - delay)
        {
            i = max(i, furthest_station);
            return (i+1);
        }
    }
    return (departure_times.size() - 1);
}

int TTrain::get_last_station_id()
{
    return (departure_times.size() - 1);
}

std::string TTrain::time_to_string(int tm)
{
    if (tm % 60 < 10)
    {
        return to_string((tm - tm % 60) / 60) + ":0" + to_string(tm % 60);
    }
    else if (tm % 60 == 0)
    {
        return to_string((tm - tm % 60) / 60) + ":00" + to_string(tm % 60);
    }
    else
    {
        return to_string((tm - tm % 60) / 60) + ":" + to_string(tm % 60);
    }
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