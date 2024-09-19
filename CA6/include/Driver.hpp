#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../include/Mission.hpp"
#include "../include/Trip.hpp"
#include "../include/Util.hpp"

using namespace std;

class Driver
{
private:
    int DriverID;
    vector<Mission *> All_missions;
    Util *UtilFunctions;
public:
    Driver(int _driver_id);

    int get_driver_id();
    bool is_duplicated_mission_id(int _mission_id);
    void add_mission(Mission *_mission);
    vector<Mission *> add_record_ride(int _start_time_stamp, int _end_time_stamp, int _time_distance);
    void print_driver_mission();
    bool is_missions_empty();
};
