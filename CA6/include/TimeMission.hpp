#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../include/Mission.hpp"
using namespace std;

class TimeMission : public Mission
{
private:
    int TargetTimeInMinutes;
    int CompleteTimeInMinutes = 0;

    bool check_mission_complete(Trip &_trip);

public:
    TimeMission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_time_in_minutes);

    TimeMission(const TimeMission &other) : Mission(other)
    {
        TargetTimeInMinutes = other.TargetTimeInMinutes;
    }

    bool Add_trip(Trip &_trip);
};
