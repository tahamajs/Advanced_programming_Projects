#include "../include/Driver.hpp"

Driver::Driver(int _driver_id) : DriverID(_driver_id)
{
    UtilFunctions = new Util();
    //
}

int Driver::get_driver_id()
{
    return DriverID;
}

bool Driver::is_duplicated_mission_id(int _mission_id)
{
    for (auto ms : All_missions)
    {
        if (ms->get_id() == _mission_id)
            return true;
    }
    return false;
}

void Driver::add_mission(Mission *_mission)
{
    All_missions.push_back(_mission);
}

vector<Mission *> Driver::add_record_ride(int _start_time_stamp, int _end_time_stamp, int _time_distance)
{
    vector<Mission *> AllMissionTemp;
    Trip *tripTemp = new Trip(_start_time_stamp, _end_time_stamp, this->DriverID, _time_distance);

    for (auto ms : All_missions)
    {
        
        if (ms->Add_trip(*tripTemp))
        {
            AllMissionTemp.push_back(ms);
        }
    }
    delete tripTemp;
    return AllMissionTemp;
}

void Driver::print_driver_mission()
{
    cout << MISSION_STATUS_MASSAGE << DriverID << ":" << endl;
    UtilFunctions->print_missionss(All_missions);
}

bool Driver::is_missions_empty()
{
    return All_missions.size();
}

