#include "../include/CountMission.hpp"

bool CountMission::check_mission_complete(Trip &_trip)
{
    if (TargetNumber <= CompleteNumber)
    {
        Status = true;
        EndTimeStamp = _trip.EndTimeStamp;
        return true;

    }
    return false;
}

CountMission::CountMission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_number)
{
    MissionID = _mission_id;
    StartTimeStamp = _start_time_stamp;
    EndTimeStamp = _end_time_stemp;
    RewardAmount = _Reward_amount;
    TargetNumber = _target_number;
}

bool CountMission::Add_trip(Trip &_trip)
{
    if (!is_trip_valid(_trip))
        return false;
    bool PreviousState = Status;

    CompleteNumber++;
    return check_mission_complete(_trip) && !PreviousState;
}
