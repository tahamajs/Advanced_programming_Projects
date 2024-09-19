#pragma once
using namespace std;
#include <string>
const int INVALID_ARGUMENTS_CODE = -1;
const int DUPLICATE_MISSION_ID_CODE = -2;
const int MISSION_NOT_FOUND_CODE = -3;
const int DUPLICATE_DRIVER_MISSION_CODE = -4;
const int VALID_CODE = 1;
const int DRIVER_MISSION_NOT_FOUND_CODE = -5;
const int OK_CODE = 2;
const int DEFULT_END_TIME_STAMP = -1;

const string INVALID_ARGUMENTS = "INVALID_ARGUMENTS";
const string DUPLICATE_MISSION_ID = "DUPLICATE_MISSION_ID";
const string MISSION_NOT_FOUND = "MISSION_NOT_FOUND";
const string DUPLICATE_DRIVER_MISSION = "DUPLICATE_DRIVER_MISSION";
const string NOT_VALID_INSTRUCTION = "NOT VALID INSTRUCTION";
const string DRIVER_MISSION_NOT_FOUND = "DRIVER_MISSION_NOT_FOUND";
const string COMPLETED_TASK_MASSAGE = "completed missions for driver ";
const string MISSION_STATUS_MASSAGE = "missions status for driver ";
const string VALID = "";
const string OK = "OK";
const string COMPLETED_STATUS = "completed";
const string ONGIONG_STATUS = "ongoing";
const string COLON = ":";

const int MINUTE_IN_SECONDS = 60;

// Instructions
const string add_time_mission_instruction = "add_time_mission";
const string add_distance_mission_instruction = "add_distance_mission";
const string add_count_mission_instruction = "add_count_mission";
const string assign_mission_instruction = "assign_mission";
const string record_ride_instruction = "record_ride";
const string show_missions_status_instruction = "show_missions_status";
