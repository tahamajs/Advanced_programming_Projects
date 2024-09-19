#include "../include/InputHandler.hpp"

InputHandler::InputHandler()
{
}

InputHandler::~InputHandler()
{
}

void InputHandler::update(string &line)
{
    int StartTimeTemp;
    int EndTimeTemp;
    int Target;
    int RewardAmount;
    int ID;
    int State;
    stringstream SS(line);
    string word;
    SS >> word;

    if (word == add_time_mission_instruction)
    {
        if(UtilFunctions.check_correct_input_count(line,6))
        {
            SS >> ID >> StartTimeTemp >> EndTimeTemp >> Target >> RewardAmount;
            State = Snapp.add_time_mission(ID, StartTimeTemp, EndTimeTemp, RewardAmount, Target);
            
        }else
            State = INVALID_ARGUMENTS_CODE;
        UtilFunctions.HandleError(State);
    }
    else if (word == add_distance_mission_instruction)
    {
        if(UtilFunctions.check_correct_input_count(line,6))
        {
            SS >> ID >> StartTimeTemp >> EndTimeTemp >> Target >> RewardAmount;
            State = Snapp.add_distance_mission(ID, StartTimeTemp, EndTimeTemp, RewardAmount, Target);
        }
        else
            State = INVALID_ARGUMENTS_CODE;
        UtilFunctions.HandleError(State);
    }
    else if (word == add_count_mission_instruction)
    {
        if(UtilFunctions.check_correct_input_count(line,6))
        {
            SS >> ID >> StartTimeTemp >> EndTimeTemp >> Target >> RewardAmount;
            State = Snapp.add_count_mission(ID, StartTimeTemp, EndTimeTemp, RewardAmount, Target);
        }else
            State = INVALID_ARGUMENTS_CODE;
        UtilFunctions.HandleError(State);
    }
    else if (word == assign_mission_instruction)
    {
        if (UtilFunctions.check_correct_input_count(line, 3))
        {
            int DriverID;
            int MissionID;
            SS >> MissionID >> DriverID;
            State = Snapp.assign_mission(MissionID, DriverID);
        }
        else
            State = INVALID_ARGUMENTS_CODE;
        UtilFunctions.HandleError(State);
    }
    else if (word == show_missions_status_instruction)
    {
        if(UtilFunctions.check_correct_input_count(line,2))
        {
            SS >> ID;
            Snapp.missions_status_for_driver(ID);
        }else
            State = INVALID_ARGUMENTS_CODE;
        UtilFunctions.HandleError(State);
    }
    else if (word == record_ride_instruction)
    {
        if(UtilFunctions.check_correct_input_count(line,5))
        {
            int Distance;
            SS >> StartTimeTemp >> EndTimeTemp >> ID >> Distance;
            try
            {
                vector<Mission *> AllMissionTemp;
                AllMissionTemp = Snapp.record_ride(StartTimeTemp, EndTimeTemp, ID, Distance);
                cout << COMPLETED_TASK_MASSAGE << ID << ":" << endl;
                UtilFunctions.print_missionss_record_ride(AllMissionTemp);
                State = VALID_CODE;
            }
            catch (int &s)
            {
                State = s;
            }
        }
        else
            State = INVALID_ARGUMENTS_CODE;
        UtilFunctions.HandleError(State);
    }
    else
    {
        cout << NOT_VALID_INSTRUCTION << endl;
    }
    
}