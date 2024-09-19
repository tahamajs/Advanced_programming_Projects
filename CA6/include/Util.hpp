#pragma once
#include <iostream>
#include "Mission.hpp"
#include "Const.hpp"
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

class Util
{
private:
    //
public:
    string get_status(Mission *_mission, int &_end_time_stamp);

    static bool cmp(const Mission *_mission_1, const Mission *_mission_2)
    {
        return _mission_1->get_start_time_stamp() < _mission_2->get_start_time_stamp();
    }
    void print_missionss(vector<Mission *> AllMissions);

    void print_missionss_record_ride(vector<Mission *> AllMissions);

    void HandleError(int State);

    int count_words(const std::string &str);

    bool check_correct_input_count(string _input, int _count);
};