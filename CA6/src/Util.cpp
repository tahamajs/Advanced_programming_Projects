#include "../include/Util.hpp"
#include <algorithm>

string Util::get_status(Mission *_mission, int &_end_time_stamp)
{
    if (_mission->get_status())
        return COMPLETED_STATUS;
    else
    {
        _end_time_stamp = DEFULT_END_TIME_STAMP;
        return ONGIONG_STATUS;
    }
}

void Util::print_missionss(vector<Mission *> AllMissions)
{
    sort(AllMissions.begin(), AllMissions.end(), cmp);
    for (int i = 0; i < AllMissions.size(); i++)
    {
        int EndTimeStamp = AllMissions[i]->get_end_time_stamp();
        get_status(AllMissions[i], EndTimeStamp);

        cout << "mission " << AllMissions[i]->get_id() << COLON << endl;
        cout << "start timestamp: " << AllMissions[i]->get_start_time_stamp() << endl;
        cout << "end timestamp: " << EndTimeStamp << endl;
        cout << "reward: " << AllMissions[i]->get_reward_amount() << endl;
        cout << "status: " << get_status(AllMissions[i], EndTimeStamp) << endl;
        if (i != AllMissions.size() - 1)
        {
            cout << endl;
        }
    }
}

void Util::print_missionss_record_ride(vector<Mission *> AllMissions)
{

    sort(AllMissions.begin(), AllMissions.end(), cmp);
    for (int i = 0; i < AllMissions.size(); i++)
    {
        int EndTimeStamp = AllMissions[i]->get_end_time_stamp();
        get_status(AllMissions[i], EndTimeStamp);

        cout << "mission: " << AllMissions[i]->get_id() << endl;
        cout << "start timestamp: " << AllMissions[i]->get_start_time_stamp() << endl;
        cout << "end timestamp: " << EndTimeStamp << endl;
        cout << "reward: " << AllMissions[i]->get_reward_amount() << endl;
        if (i != AllMissions.size() - 1)
        {
            cout << endl;
        }
    }
}

void Util::HandleError(int State)
{
    if (State == INVALID_ARGUMENTS_CODE)
    {
        cout << INVALID_ARGUMENTS << endl;
    }
    else if (State == DUPLICATE_MISSION_ID_CODE)
    {
        cout << DUPLICATE_MISSION_ID << endl;
    }
    else if (State == MISSION_NOT_FOUND_CODE)
    {
        cout << MISSION_NOT_FOUND << endl;
    }
    else if (State == DUPLICATE_DRIVER_MISSION_CODE)
    {
        cout << DUPLICATE_DRIVER_MISSION << endl;
    }
    else if (State == VALID_CODE)
    {
        // cout << VALID << endl;
    }
    else if (State == OK_CODE)
    {
        cout << OK << endl;
    }
}

int Util::count_words(const std::string &str)
{
    std::stringstream ss(str);
    std::string word;
    int count = 0;
    while (ss >> word)
    {
        ++count;
    }
    return count;
}

bool Util::check_correct_input_count(string _input, int _count)
{
    if (count_words(_input) != _count)
        return false;
    return true;
}