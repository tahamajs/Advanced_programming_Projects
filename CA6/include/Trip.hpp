#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../include/Const.hpp"
using namespace std;

class Trip
{
private:
public:
    int EndTimeStamp;
    int StartTimeStamp;
    int PlayerID;
    int TripDistance;

    Trip(int _start_time_stamp, int _end_time_stamp, int _player_id, int _Trip_distance);
};
