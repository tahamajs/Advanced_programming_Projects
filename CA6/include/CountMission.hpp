#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../include/Mission.hpp"

using namespace std;


class CountMission : public Mission{
private:
    int TargetNumber;
    int CompleteNumber = 0;
    bool check_mission_complete(Trip &_trip);
    
public:

    CountMission(const CountMission& other) : Mission(other)
    {
        TargetNumber = other.TargetNumber;
    }
    CountMission(int _mission_id ,int _start_time_stamp , int _end_time_stemp , int _Reward_amount , int _target_number);
    bool Add_trip(Trip &_trip );


};
