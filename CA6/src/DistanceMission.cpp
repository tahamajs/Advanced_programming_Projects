#include "../include/DistanceMission.hpp"

bool DistanceMission::check_mission_complete(Trip &_trip)
{
    if (TargetDistanceInMeters <= CompleteDistanceInMeters)
    {
        Status = true;
        EndTimeStamp = _trip.EndTimeStamp;
        return true;
    }
    return false;
}

DistanceMission::DistanceMission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_distance_in_metess)
{
    MissionID = _mission_id;
    StartTimeStamp = _start_time_stamp;
    EndTimeStamp = _end_time_stemp;
    RewardAmount = _Reward_amount;
    TargetDistanceInMeters = _target_distance_in_metess;
}

bool DistanceMission::Add_trip(Trip &_trip)
{
    if (!is_trip_valid(_trip))
        return false;
    bool PreviousState = Status;

    CompleteDistanceInMeters += _trip.TripDistance;
    return check_mission_complete(_trip) && !PreviousState;
    // return true;
}
