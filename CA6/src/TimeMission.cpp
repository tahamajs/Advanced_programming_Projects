#include "../include/TimeMission.hpp"

bool TimeMission::check_mission_complete(Trip &_trip)
{
    if (TargetTimeInMinutes <= CompleteTimeInMinutes)
    {
        Status = true;
        EndTimeStamp = _trip.EndTimeStamp;
        return true;
    }
    return false;
}

TimeMission::TimeMission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_time_in_minutes)
{
    MissionID = _mission_id;
    StartTimeStamp = _start_time_stamp;
    EndTimeStamp = _end_time_stemp;
    RewardAmount = _Reward_amount;
    TargetTimeInMinutes = _target_time_in_minutes;
}

bool TimeMission::Add_trip(Trip &_trip)
{
    if (!is_trip_valid(_trip))
        return false;
    bool PreviousState = Status;

    int MinutesOfTrip = (_trip.EndTimeStamp - _trip.StartTimeStamp) / MINUTE_IN_SECONDS;
    CompleteTimeInMinutes += MinutesOfTrip;
    return check_mission_complete(_trip) && !PreviousState;
    // return true;
}
