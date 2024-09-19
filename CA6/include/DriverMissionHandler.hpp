#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../include/Mission.hpp"
#include "../include/Driver.hpp"
#include "../include/DistanceMission.hpp"
#include "../include/TimeMission.hpp"
#include "../include/CountMission.hpp"
#include "../include/Const.hpp"

using namespace std;

class DriverMissionHandler
{
private:
    vector<Mission *> All_Missions;
    vector<Driver *> All_Drivers;

    bool is_duplicate_mission_id(int _mission_id);
    bool is_time_correct(int _start_time_stamp, int _end_time_stamp);
    bool is_positive(int _number);
    bool is_driver_id_valid(int _drive_id);
    int add_driver(int _driver_id);
    Driver *get_driver(int _driver_id);
    Mission *get_mission(int _mission_id);

public:
    DriverMissionHandler();
    int add_time_mission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_time_in_minutes);
    int add_count_mission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_number);
    int add_distance_mission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_distance_in_metess);
    int assign_mission(int _mision_id, int _driver_id);
    vector<Mission *> record_ride(int _start_time_stamp, int _end_time_stamp, int _driver_id, int _distance);
    int missions_status_for_driver(int _driver_id);
};