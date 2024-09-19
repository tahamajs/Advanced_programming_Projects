#include "../include/DriverMissionHandler.hpp"

DriverMissionHandler::DriverMissionHandler()
{
    //
}

bool DriverMissionHandler::is_duplicate_mission_id(int _mission_id)
{
    for (auto id : All_Missions)
    {
        if (id->get_id() == _mission_id)
            return true;
    }
    return false;
}

bool DriverMissionHandler::is_time_correct(int _start_time_stamp, int _end_time_stamp)
{
    return _start_time_stamp < _end_time_stamp;
}

bool DriverMissionHandler::is_positive(int _number)
{
    if (_number > 0)
        return true;
    else
        return false;
}

bool DriverMissionHandler::is_driver_id_valid(int _drive_id)
{
    for (auto dv : All_Drivers)
    {
        if (dv->get_driver_id() == _drive_id)
        {
            return true;
        }
    }
    return false;
}

int DriverMissionHandler::add_driver(int _driver_id)
{
    Driver *driver = new Driver(_driver_id);
    All_Drivers.push_back(driver);
    return VALID_CODE;
}

Driver *DriverMissionHandler::get_driver(int _driver_id)
{
    for (auto dv : All_Drivers)
    {
        if (dv->get_driver_id() == _driver_id)
        {
            return dv;
        }
    }
    return NULL;
}

Mission *DriverMissionHandler::get_mission(int _mission_id)
{
    for (auto ms : All_Missions)
    {
        if (ms->get_id() == _mission_id)
        {
            return ms;
        }
    }
    return NULL;
}

int DriverMissionHandler::add_time_mission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_time_in_minutes)
{
    if (is_duplicate_mission_id(_mission_id))
    {
        return DUPLICATE_MISSION_ID_CODE;
    }

    if (!(is_time_correct(_start_time_stamp, _end_time_stemp) && is_positive(_Reward_amount) && is_positive(_target_time_in_minutes)))
    {
        return INVALID_ARGUMENTS_CODE;
    }

    TimeMission *timeMission = new TimeMission(_mission_id, _start_time_stamp, _end_time_stemp, _Reward_amount, _target_time_in_minutes);
    All_Missions.push_back(timeMission);
    return OK_CODE;
}

int DriverMissionHandler::add_count_mission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_number)
{
    if (is_duplicate_mission_id(_mission_id))
    {
        return DUPLICATE_MISSION_ID_CODE;
    }

    if (!(is_time_correct(_start_time_stamp, _end_time_stemp) && is_positive(_Reward_amount) && is_positive(_target_number)))
    {
        return INVALID_ARGUMENTS_CODE;
    }

    CountMission *countMission = new CountMission(_mission_id, _start_time_stamp, _end_time_stemp, _Reward_amount, _target_number);
    All_Missions.push_back(countMission);
    return OK_CODE;
}

int DriverMissionHandler::add_distance_mission(int _mission_id, int _start_time_stamp, int _end_time_stemp, int _Reward_amount, int _target_distance_in_metess)
{
    if (is_duplicate_mission_id(_mission_id))
    {
        return DUPLICATE_MISSION_ID_CODE;
    }

    if (!(is_time_correct(_start_time_stamp, _end_time_stemp) && is_positive(_Reward_amount) && is_positive(_target_distance_in_metess)))
    {
        return INVALID_ARGUMENTS_CODE;
    }

    DistanceMission *distanceMission = new DistanceMission(_mission_id, _start_time_stamp, _end_time_stemp, _Reward_amount, _target_distance_in_metess);
    All_Missions.push_back(distanceMission);
    return OK_CODE;
}

int DriverMissionHandler::assign_mission(int _mision_id, int _driver_id)
{
    if (!is_duplicate_mission_id(_mision_id))
    {
        return MISSION_NOT_FOUND_CODE;
    }

    if (!is_driver_id_valid(_driver_id))
    {
        add_driver(_driver_id);
    }
    else
    {
        Driver *driverTemp = get_driver(_driver_id);
        if (driverTemp->is_duplicated_mission_id(_mision_id))
        {
            return DUPLICATE_DRIVER_MISSION_CODE;
        }
    }

    Driver *driverTemp = get_driver(_driver_id);
    Mission *missionTemp = get_mission(_mision_id);

    TimeMission *TmissionPtr = dynamic_cast<TimeMission *>(missionTemp);
    if (TmissionPtr != NULL)
    {
        TmissionPtr = new TimeMission(*TmissionPtr);
        driverTemp->add_mission(TmissionPtr);
    }

    DistanceMission *DmissionPtr = dynamic_cast<DistanceMission *>(missionTemp);
    if (DmissionPtr != NULL)
    {
        DmissionPtr = new DistanceMission(*DmissionPtr);
        driverTemp->add_mission(DmissionPtr);
    }

    CountMission *CmissionPtr = dynamic_cast<CountMission *>(missionTemp);
    if (CmissionPtr != NULL)
    {
        CmissionPtr = new CountMission(*CmissionPtr);
        driverTemp->add_mission(CmissionPtr);
    }

    return OK_CODE;
}

vector<Mission *> DriverMissionHandler::record_ride(int _start_time_stamp, int _end_time_stamp, int _driver_id, int _distance)
{
    Driver *DriverTemp;
    DriverTemp = get_driver(_driver_id);
    if (!is_time_correct(_start_time_stamp, _end_time_stamp))
    {
        throw INVALID_ARGUMENTS_CODE;
    }

    vector<Mission *> AllMissionTemp = DriverTemp->add_record_ride(_start_time_stamp, _end_time_stamp, _distance);
    return AllMissionTemp;
    // need to complete
}

int DriverMissionHandler::missions_status_for_driver(int _driver_id)
{
    Driver *DriverTemp = get_driver(_driver_id);
    if (!DriverTemp->is_missions_empty())
    {
        return DRIVER_MISSION_NOT_FOUND_CODE;
    }

    DriverTemp->print_driver_mission();
    return VALID_CODE;
}
