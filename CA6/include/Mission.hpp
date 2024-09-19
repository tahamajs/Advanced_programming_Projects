#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "../include/Trip.hpp"

using namespace std;

class Mission
{
private:
protected:
    int MissionID;
    int StartTimeStamp;
    int EndTimeStamp;
    bool Status = false;
    int RewardAmount;

    virtual bool check_mission_complete(Trip &_trip) = 0;

    bool is_trip_valid(Trip &_trip)
    {
        return StartTimeStamp <= _trip.StartTimeStamp && EndTimeStamp >= _trip.EndTimeStamp;
    }

    Mission() = default;

    Mission(const Mission &other)
    {
        MissionID = other.MissionID;
        StartTimeStamp = other.StartTimeStamp;
        EndTimeStamp = other.EndTimeStamp;
        Status = other.Status;
        RewardAmount = other.RewardAmount;
    }

    Mission &operator=(const Mission &other)
    {
        if (this != &other)
        {
            MissionID = other.MissionID;
            StartTimeStamp = other.StartTimeStamp;
            EndTimeStamp = other.EndTimeStamp;
            Status = other.Status;
            RewardAmount = other.RewardAmount;
        }
        return *this;
    }

public:
    virtual bool Add_trip(Trip &_trip) = 0;

    int get_id() { return MissionID; }
    int get_start_time_stamp() const { return StartTimeStamp; }
    int get_end_time_stamp() const { return EndTimeStamp; }
    int get_reward_amount() { return RewardAmount; }
    bool get_status() { return Status; }
};
