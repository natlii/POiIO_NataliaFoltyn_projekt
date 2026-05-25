#pragma once
#include<iostream>
#include<vector>
#include<string.h>
#include "TTrain.h"

class TDisplay
{
private:
    // accessible lists of trains
    std::vector<TTrain> all_trains;
    std::vector<TTrain> displayed_trains;

    // debug
    int elements;

    // filters list for displaying
    enum filters
    {
        NAME,
        DESTINATION,
        CURRENT,
        PASSING,
        ID,
        DELAY
    };

public:
    // definition
    TDisplay(std::vector<TTrain> trains);

    // building display list
    void build_list(std::string filter_str);
    void build_list(int filter_int);

    // accessing the lists    
    std::vector<TTrain> get_display_list();
    std::vector<TTrain> get_all_list();

    // debug get number of elements
    int get_num_elements();
    
    // debug for displaying
    void show_display_list();

    // modifying the train list
    void gen_train_list(int number);
    void reset_train_list();
    void add_to_list(TTrain train);
};
