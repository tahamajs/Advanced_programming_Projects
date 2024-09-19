#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../include/Mission.hpp"

using namespace std;

class DistanceMission : public Mission{
private:
    int TargetDistanceInMeters;
    int CompleteDistanceInMeters = 0;
    bool check_mission_complete(Trip &_trip);

public:
    DistanceMission(int _mission_id ,int _start_time_stamp , int _end_time_stemp , int _Reward_amount , int _target_distance_in_metess);
    DistanceMission(const DistanceMission& other) : Mission(other)
    {
        TargetDistanceInMeters = other.TargetDistanceInMeters;
    }
    bool Add_trip(Trip &_trip );

};
