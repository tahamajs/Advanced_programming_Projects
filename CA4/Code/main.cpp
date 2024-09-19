#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int const NOT_VALID = -1;
int const DEFULT_VALUE = 0;
const string EMPLOYEES_CSV_FILE_NAME = "/employees.csv";
const string SALARY_CONFIG_CSV_FILE_NAME = "/salary_configs.csv";
const string TEAMS_CSV_FILE_NAME = "/teams.csv";
const string WORKING_HOURS_CSV_FILE_NAME = "/working_hours.csv";
const string DASH = "-";
const char C_DASH = '-';
const string KAMA = ",";
const string DOLAR_CHAR = "$";
const string SPACE = " ";
const int NUMBER_OF_LEVELS = 4;
const int ONE_HANDRED = 100;
const int DAY_NUMBERS = 30;
const int MAX_OF_INT = 999999999;
const int NUMBER_OF_HOURS = 24;
const int ARGUMENT_NUMBER = 6;
const string NOT_AVALABLE = "N/A";
const string PERCENTAGE = "%";

vector<string> split_by_commas(string str);

class LevelConsts
{
private:
    string level[NUMBER_OF_LEVELS];
    int base_salery[NUMBER_OF_LEVELS];
    int salery_per_hour[NUMBER_OF_LEVELS];
    int salery_per_extra_hour[NUMBER_OF_LEVELS];
    int official_working_hour[NUMBER_OF_LEVELS];
    double task_persentage[NUMBER_OF_LEVELS];

public:
    void set_level_config(vector<string> config_vec, int i);

    int level_number(string _level);

    int get_base_salary(string _level);

    int get_salery_per_hour(string _level);

    int get_salery_per_extra_hour(string _level);

    int get_official_working_hour(string _level);

    int get_task_persentage(string _level);

    void show_salary_config(string _level);
};

class WorkingHoursPerDay
{
private:
    vector<pair<int, int>> intervals;

public:
    int get_total_work_per_day();

    bool set_interval(int first, int second);

    void delete_intervel()
    {
        intervals.clear();
    }

    bool is_work_in_time(int _time);
};

class employee
{
private:
    int emp_id;
    string emp_name;
    string emp_level;
    int emp_age;
    int emp_team_id = NOT_VALID;
    int total_working_hours;
    int number_of_absent_days;
    double total_earn;
    double salery_earn;
    double bonus_earn = DEFULT_VALUE;
    double task_pay = DEFULT_VALUE;
    double bonus_persentage = DEFULT_VALUE;
    WorkingHoursPerDay working_hours_per_day[DAY_NUMBERS];
    LevelConsts *level_consts;

public:
    employee(LevelConsts *_level_const, int _id, string _name, int _age, string _level);

    void print_emp();

    void set_bonus_team(int _bonus_persentage);

    int get_total_work_per_month();

    bool set_day_interval(vector<string> day_interval_vec);

    int get_absent_days();

    int get_days_number_work_in_time(int time);

    int get_emp_id()
    {
        return emp_id;
    }

    void set_team_id(int _team_ID)
    {
        emp_team_id = _team_ID;
    }

    string get_emp_name()
    {
        return emp_name;
    }

    void calculate_total_hour()
    {
        total_working_hours = get_total_work_per_month();
    }

    double get_total_earning()
    {
        return total_earn;
    }

    int get_total_WH_day(int day_num)
    {
        return working_hours_per_day[day_num - 1].get_total_work_per_day();
    }

    void delete_interval(int day_num);

    void set_earn();
};

class Team
{
private:
    vector<int> team_members;
    int team_id;
    int team_head_id;
    int bonus_min_working_hours;
    int total_team_WH = DEFULT_VALUE;
    int bonus_working_hours_max_variance;
    double average_members_WH = DEFULT_VALUE;
    int Bonus = DEFULT_VALUE;
    vector<employee *> team_emps;

public:
    void set_team(vector<string> team_info, vector<employee *> all_emp);

    void spleat_by_$(string str);

    void compleat_emps_vector(vector<employee *> all_emp, int _team_id);

    void Print_team();

    void report_team_salary();

    void set_team_WH();

    void set_bonus_percentage(int _bonus_percentage);

    int get_team_id()
    {
        return team_id;
    }

    int get_team_average_members_WH()
    {
        return average_members_WH;
    }

    int get_total_WH();

    bool is_total_WH_valid();

    bool is_WH_variance_valid();
};

class AllEmployees
{
private:
    vector<employee *> all_employees;
    LevelConsts level_const;
    vector<Team *> all_teams;
    int numebr_of_team_in_vector(int _id);

    void read_teams_info(string file_name);

    bool is_day_valid(int sday, int eday);

    bool is_time_valid(int stime, int etime);

    double get_avarage_working_in_time(int _time);

    int get_total_hours_per_day(int day_num);

    void read_employees_info(string file_name);

    void read_level_info(string file_name);

    void read_working_hours_info(string file_name);

public:
    AllEmployees(string folder_name);

    int get_total_work();

    int number_of_empID_in_vector(int _emp_ID);

    void report_employee_salary(int emp_ID);

    void show_salary_config(string _level)
    {
        level_const.show_salary_config(_level);
    }

    void delete_working_hours(int emp_num, int day_num)
    {
        if (number_of_empID_in_vector(emp_num) != NOT_VALID)
        {
            if (day_num > DAY_NUMBERS || day_num <= 0)
            {
                cout << "INVALID_ARGUMENTS" << endl;
                return;
            }

            all_employees[number_of_empID_in_vector(emp_num)]->delete_interval(day_num);
            cout << "OK" << endl;
        }
        else
        {
            cout << "EMPLOYEE_NOT_FOUND" << endl;
        }
    }

    void add_working_hours(string employee_id, string day, string period_start, string period_end);

    void report_team_salary(int team_num);

    void report_total_hours_per_day(int sDay, int eDay);

    void report_employee_per_hour(int stime, int etime);

    void report_salaries();

    void Update_salary_config(vector<string> level_config_vec);

    void update_team_bonus(int _team_id, int _bonus_percentage);

    void find_teams_for_bonus();
};

int main(int argc, char *argv[])
{
    AllEmployees factory(argv[1]);
    string sTemp;
    int employeeID;

    while (cin >> sTemp)
    {
        if (sTemp == "report_salaries")
        {
            factory.report_salaries();
        }
        else if (sTemp == "report_employee_salary")
        {
            cin >> employeeID;
            factory.report_employee_salary(employeeID);
        }
        else if (sTemp == "report_team_salary")
        {
            cin >> employeeID;
            factory.report_team_salary(employeeID);
        }
        else if (sTemp == "report_total_hours_per_day")
        {
            int stratDay, endDay;
            cin >> stratDay >> endDay;
            factory.report_total_hours_per_day(stratDay, endDay);
        }
        else if (sTemp == "report_employee_per_hour")
        {
            int stratHour, endHour;
            cin >> stratHour >> endHour;
            factory.report_employee_per_hour(stratHour, endHour);
        }
        else if (sTemp == "show_salary_config")
        {
            string level;
            cin >> level;
            factory.show_salary_config(level);
        }
        else if (sTemp == "update_salary_config")
        {
            string temp;
            vector<string> salary_vec;
            for (int i = 0; i < ARGUMENT_NUMBER; i++)
            {
                cin >> temp;
                salary_vec.push_back(temp);
            }
            factory.Update_salary_config(salary_vec);
        }
        else if (sTemp == "add_working_hours")
        {
            string employee_id, day, period_start, period_end;
            cin >> employee_id >> day >> period_start >> period_end;
            factory.add_working_hours(employee_id, day, period_start, period_end);
        }
        else if (sTemp == "delete_working_hours")
        {
            int employee_id, day;
            cin >> employee_id >> day;
            factory.delete_working_hours(employee_id, day);
        }
        else if (sTemp == "update_team_bonus")
        {
            int team_id, bonus_percentage;
            cin >> team_id >> bonus_percentage;
            factory.update_team_bonus(team_id, bonus_percentage);
        }
        else if (sTemp == "find_teams_for_bonus")
        {
            factory.find_teams_for_bonus();
        }
        else
        {
            cout << "404 NOT_FOUND" << endl;
        }
    }
}

void LevelConsts::set_level_config(vector<string> config_vec, int i)
{
    level[i] = config_vec[0];
    if (config_vec[1] != DASH)
    {
        base_salery[i] = stoi(config_vec[1]);
    }
    if (config_vec[2] != DASH)
    {
        salery_per_hour[i] = stoi(config_vec[2]);
    }
    if (config_vec[3] != DASH)
    {
        salery_per_extra_hour[i] = stoi(config_vec[3]);
    }
    if (config_vec[4] != DASH)
    {
        official_working_hour[i] = stoi(config_vec[4]);
    }
    if (config_vec[5] != DASH)
    {
        task_persentage[i] = stoi(config_vec[5]);
    }
}

int LevelConsts::level_number(string _level)
{
    int NumOfPos = NOT_VALID;
    for (int i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        if (_level == level[i])
        {
            NumOfPos = i;
        }
    }
    return NumOfPos;
}

int LevelConsts::get_base_salary(string _level)
{
    int NumOfPos = NOT_VALID;
    for (int i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        if (_level == level[i])
        {
            NumOfPos = i;
        }
    }
    return base_salery[NumOfPos];
}

int LevelConsts::get_salery_per_hour(string _level)
{
    int NumOfPos = NOT_VALID;
    for (int i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        if (_level == level[i])
        {
            NumOfPos = i;
        }
    }
    return salery_per_hour[NumOfPos];
}

int LevelConsts::get_salery_per_extra_hour(string _level)
{
    int NumOfPos = NOT_VALID;
    for (int i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        if (_level == level[i])
        {
            NumOfPos = i;
        }
    }
    return salery_per_extra_hour[NumOfPos];
}

int LevelConsts::get_official_working_hour(string _level)
{
    int NumOfPos = NOT_VALID;
    for (int i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        if (_level == level[i])
        {
            NumOfPos = i;
        }
    }
    return official_working_hour[NumOfPos];
}

int LevelConsts::get_task_persentage(string _level)
{
    int NumOfPos = NOT_VALID;
    for (int i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        if (_level == level[i])
        {
            NumOfPos = i;
        }
    }
    return task_persentage[NumOfPos];
}

void LevelConsts::show_salary_config(string _level)
{
    int NumOfPos = NOT_VALID;
    for (int i = 0; i < NUMBER_OF_LEVELS; i++)
    {
        if (_level == level[i])
        {
            NumOfPos = i;
        }
    }
    if (NumOfPos == NOT_VALID)
    {
        cout << "INVALID_LEVEL" << endl;
        return;
    }
    cout << "Base Salary: " << base_salery[NumOfPos] << endl
         << "Salary Per Hour: " << salery_per_hour[NumOfPos] << endl
         << "Salary Per Extra Hour: " << salery_per_extra_hour[NumOfPos] << endl
         << "Official Working Hours: " << official_working_hour[NumOfPos] << endl
         << "Tax: " << task_persentage[NumOfPos] << PERCENTAGE << endl;
}

int WorkingHoursPerDay::get_total_work_per_day()
{
    int total_day_hour = DEFULT_VALUE;
    for (auto i : intervals)
    {
        total_day_hour += i.second - i.first;
    }
    return total_day_hour;
}

bool WorkingHoursPerDay::set_interval(int first, int second)
{
    for (auto x : intervals)
    {
        if ((x.first < first && x.second > first) || (x.first < second && x.second > second))
        {
            return false;
        }
        if ((x.first >= first && x.second <= second))
        {
            return false;
        }
    }

    intervals.push_back(make_pair(first, second));
    return true;
}

bool WorkingHoursPerDay::is_work_in_time(int _time)
{
    for (auto x : intervals)
    {
        for (int i = x.first; i < x.second; i++)
        {
            if (i == _time)
            {
                return true;
            }
        }
    }
    return false;
}

employee::employee(LevelConsts *_level_const, int _id, string _name, int _age, string _level)
{
    level_consts = _level_const;
    emp_id = _id;
    emp_name = _name;
    emp_age = _age;
    emp_level = _level;
}

bool employee::set_day_interval(vector<string> day_interval_vec)
{
    stringstream sstream;
    string first, second;
    sstream << day_interval_vec[2];
    getline(sstream, first, C_DASH);
    getline(sstream, second, C_DASH);

    bool status = working_hours_per_day[stoi(day_interval_vec[1]) - 1].set_interval(stoi(first), stoi(second));
    calculate_total_hour();
    set_earn();
    return status;
}

void employee::set_bonus_team(int _bonus_persentage)
{
    bonus_persentage = _bonus_persentage;
    set_earn();
}

int employee::get_total_work_per_month()
{
    int total_day_month = DEFULT_VALUE;
    for (auto i : working_hours_per_day)
    {
        total_day_month += i.get_total_work_per_day();
    }
    return total_day_month;
}

int employee::get_absent_days()
{
    int absent_days = DEFULT_VALUE;
    for (auto x : working_hours_per_day)
    {
        if (x.get_total_work_per_day() == DEFULT_VALUE)
        {
            absent_days++;
        }
    }
    return absent_days;
}

int employee::get_days_number_work_in_time(int time)
{
    int days_number = DEFULT_VALUE;
    for (auto x : working_hours_per_day)
    {
        if (x.is_work_in_time(time))
        {
            days_number++;
        }
    }

    return days_number;
}

void employee::delete_interval(int day_num)
{
    working_hours_per_day[day_num - 1].delete_intervel();
    calculate_total_hour();
    set_earn();
}

void employee::set_earn()
{

    if (total_working_hours > level_consts->get_official_working_hour(emp_level))
    {
        salery_earn = round(level_consts->get_official_working_hour(emp_level) * level_consts->get_salery_per_hour(emp_level) + level_consts->get_base_salary(emp_level));
        salery_earn += round((total_working_hours - level_consts->get_official_working_hour(emp_level)) * level_consts->get_salery_per_extra_hour(emp_level));
    }
    else
    {
        salery_earn = round(total_working_hours * level_consts->get_salery_per_hour(emp_level) + level_consts->get_base_salary(emp_level));
    }
    bonus_earn = salery_earn * bonus_persentage / double(ONE_HANDRED);
    salery_earn += bonus_earn;

    task_pay = (round(salery_earn) * round((level_consts->get_task_persentage(emp_level))) / double(ONE_HANDRED));
    total_earn = salery_earn - task_pay;
}

void employee::print_emp()
{

    // calculate_total_hour();
    cout << "ID: " << this->emp_id << endl;
    cout << "Name: " << this->emp_name << endl;
    cout << "Age: " << this->emp_age << endl;
    cout << "Level: " << this->emp_level << endl;
    if (emp_team_id == NOT_VALID)
    {
        cout << "Team ID: "
             << NOT_AVALABLE << endl;
    }
    else
    {
        cout << "Team ID: " << this->emp_team_id << endl;
    }

    cout << "Total Working Hours: " << this->total_working_hours << endl;
    cout << "Absent Days: " << get_absent_days() << endl;
    cout << "Salary: " << this->salery_earn - bonus_earn << endl;
    cout << "Bonus: " << round(this->bonus_earn) << endl;
    cout << "Tax: " << round(this->task_pay) << endl;
    cout << "Total Earning: " << round(this->total_earn) << endl;
}

employee *read_emp(string line, LevelConsts *level_const)
{
    vector<string> fields = split_by_commas(line);
    employee *emp = new employee(level_const, stoi(fields[0]), fields[1], stoi(fields[2]), fields[3]);
    return emp;
}

void Team::set_team(vector<string> team_info, vector<employee *> all_emp)
{
    team_id = stoi(team_info[0]);
    team_head_id = stoi(team_info[1]);
    bonus_min_working_hours = stoi(team_info[3]);
    bonus_working_hours_max_variance = stoi(team_info[4]);
    spleat_by_$(team_info[2]);
    compleat_emps_vector(all_emp, team_id);
}

void Team::spleat_by_$(string str)
{
    int start_pos = 0;
    while (start_pos < str.length())
    {
        int comma_pos = str.find(DOLAR_CHAR, start_pos);
        if (comma_pos == string::npos)
        {
            team_members.push_back(stoi(str.substr(start_pos)));
            break;
        }
        team_members.push_back(stoi(str.substr(start_pos, comma_pos - start_pos)));
        start_pos = comma_pos + 1;
    }
    // return result;
}

void Team::compleat_emps_vector(vector<employee *> all_emp, int _team_id)
{
    for (auto x : all_emp)
    {
        for (int i = 0; i < team_members.size(); i++)
        {
            if (team_members[i] == x->get_emp_id())
            {
                team_emps.push_back(x);
                x->set_team_id(_team_id);

                // break;
            }
        }
    }
}

void Team::Print_team()
{
    cout << "Team_ID : " << team_id;
    cout << endl;
    cout << "Team_Head_ID : " << team_head_id;
    cout << endl;
    cout << "bonus_min_working_hours : " << bonus_min_working_hours;
    cout << endl;
    cout << "bonus_working_hours_max_variance : " << bonus_working_hours_max_variance;
    cout << endl;
    cout << "All Emp_id : ";
    cout << team_members.size();
    for (employee *ll : team_emps)
    {
        cout << ll->get_emp_name() << " : " << ll->get_emp_id() << endl;
    }
    cout << "--------------------------" << endl
         << endl;
}

void Team::report_team_salary()
{
    set_team_WH();
    cout << "ID: " << team_id;
    cout << endl;
    cout << "Head ID: " << team_head_id;
    cout << endl;
    cout << "Head Name: " << team_emps[team_id - 1]->get_emp_name();
    cout << endl;
    cout << "Team Total Working Hours: " << total_team_WH;
    cout << endl;
    cout << "Average Member Working Hours: ";
    printf("%.1f", average_members_WH);
    cout << endl;
    cout << "Bonus: " << round(Bonus);
    cout << endl
         << "---" << endl;

    for (auto x : team_emps)
    {
        cout << "Member ID: " << x->get_emp_id() << endl;
        cout << "Total Earning: " << round(x->get_total_earning()) << endl;
        cout << "---" << endl;
    }
}

void Team::set_team_WH()
{
    total_team_WH = 0;
    for (auto x : team_emps)
    {
        total_team_WH += x->get_total_work_per_month();
    }
    average_members_WH = double(total_team_WH) / double(team_emps.size());
}

int Team::get_total_WH()
{
    set_team_WH();
    return total_team_WH;
}

void Team::set_bonus_percentage(int _bonus_percentage)
{
    Bonus = _bonus_percentage;
    for (auto x : team_emps)
    {
        x->set_bonus_team(_bonus_percentage);
    }
}

bool Team::is_total_WH_valid()
{
    set_team_WH();
    return total_team_WH > bonus_min_working_hours;
}

bool Team::is_WH_variance_valid()
{
    set_team_WH();
    int variance;

    for (auto x : team_emps)
    {
        variance += ((x->get_total_work_per_month() - average_members_WH) * (x->get_total_work_per_month() - average_members_WH));
    }
    variance /= team_emps.size();

    return variance < bonus_working_hours_max_variance;
}

int AllEmployees::numebr_of_team_in_vector(int _id)
{
    for (int i = 0; i < all_teams.size(); i++)
    {
        if (all_teams[i]->get_team_id() == _id)
        {
            return i;
        }
    }
    return NOT_VALID;
}

void AllEmployees::read_teams_info(string file_name)
{
    ifstream teams_info;
    teams_info.open(file_name);
    vector<string> words_vector;

    string line;
    teams_info >> line;
    while (teams_info >> line)
    {
        // cout << line;
        words_vector = split_by_commas(line);
        Team *team_temp = new Team;
        team_temp->set_team(words_vector, all_employees);
        all_teams.push_back(team_temp);
    }
}

bool AllEmployees::is_day_valid(int sday, int eday)
{
    if (sday >= eday)
    {
        return false;
    }
    if (sday >= 1 && sday <= DAY_NUMBERS && eday >= 1 && eday <= DAY_NUMBERS)
    {
        return true;
    }
    return false;
}

bool AllEmployees::is_time_valid(int stime, int etime)
{
    if (stime >= etime)
    {
        return false;
    }
    if (stime >= 0 && stime <= NUMBER_OF_HOURS && etime >= 0 && etime <= NUMBER_OF_HOURS)
    {
        return true;
    }
    return false;
}

double AllEmployees::get_avarage_working_in_time(int _time)
{

    double sum_of_avrage = DEFULT_VALUE;
    for (auto x : all_employees)
    {
        sum_of_avrage += x->get_days_number_work_in_time(_time);
    }
    return sum_of_avrage / double(DAY_NUMBERS);
}

int AllEmployees::get_total_hours_per_day(int day_num)
{
    int total_hours_per_day = DEFULT_VALUE;
    for (auto x : all_employees)
    {
        total_hours_per_day += x->get_total_WH_day(day_num);
    }
    return total_hours_per_day;
}

void AllEmployees::read_employees_info(string file_name)
{
    ifstream stream;
    stream.open(file_name);
    string line;
    vector<string> words_vector;
    stream >> line;
    while (stream >> line)
    {
        all_employees.push_back(read_emp(line, &level_const));
    }
}

void AllEmployees::read_level_info(string file_name)
{
    ifstream level_stream;
    level_stream.open(file_name);
    vector<string> words_vector;
    string line;
    level_stream >> line;
    int i = DEFULT_VALUE;
    while (level_stream >> line)
    {
        words_vector = split_by_commas(line);
        level_const.set_level_config(words_vector, i);
        i++;
    }
}

void AllEmployees::read_working_hours_info(string file_name)
{
    ifstream working_hours_stream;
    working_hours_stream.open(file_name);
    vector<string> words_vector;

    string line;
    working_hours_stream >> line;
    while (working_hours_stream >> line)
    {
        words_vector = split_by_commas(line);

        all_employees[number_of_empID_in_vector(stoi(words_vector[0]))]->set_day_interval(words_vector);
        all_employees[number_of_empID_in_vector(stoi(words_vector[0]))]->calculate_total_hour();
    }
}

AllEmployees::AllEmployees(string folder_name)
{
    string emp_csv_name = folder_name + EMPLOYEES_CSV_FILE_NAME;
    string salary_configs_csv_name = folder_name + SALARY_CONFIG_CSV_FILE_NAME;
    string teams_csv_name = folder_name + TEAMS_CSV_FILE_NAME;
    string working_hours_csv_name = folder_name + WORKING_HOURS_CSV_FILE_NAME;
    read_level_info(salary_configs_csv_name);
    read_employees_info(emp_csv_name);
    read_working_hours_info(working_hours_csv_name);
    read_teams_info(teams_csv_name);
    for (auto x : all_employees)
    {
        x->set_earn();
    }
}

int AllEmployees::get_total_work()
{
    int sum_of_work_hours = DEFULT_VALUE;
    for (auto i : all_employees)
    {
        sum_of_work_hours += i->get_total_work_per_month();
    }

    return sum_of_work_hours;
}

int AllEmployees::number_of_empID_in_vector(int _emp_ID)
{
    for (int i = 0; i < all_employees.size(); i++)
    {
        if (all_employees[i]->get_emp_id() == _emp_ID)
        {
            return i;
        }
    }
    return NOT_VALID;
}

void AllEmployees::report_employee_salary(int emp_ID)
{
    if (number_of_empID_in_vector(emp_ID) != NOT_VALID)
    {
        all_employees[number_of_empID_in_vector(emp_ID)]->print_emp();
    }
    else
    {
        cout << "EMPLOYEE_NOT_FOUND" << endl;
    }
}

void AllEmployees::add_working_hours(string employee_id, string day, string period_start, string period_end)
{
    if (number_of_empID_in_vector(stoi(employee_id)) != NOT_VALID)
    {
        if (!is_time_valid(stoi(period_start), stoi(period_end)))
        {
            cout << "INVALID_ARGUMENTS" << endl;
            return;
        }

        vector<string> svec;
        svec.push_back(employee_id);
        svec.push_back(day);
        svec.push_back(period_start + DASH + period_end);
        if (!all_employees[number_of_empID_in_vector(stoi(employee_id))]->set_day_interval(svec))
        {
            cout << "INVALID_INTERVAL" << endl;
            return;
        }
        cout << "OK" << endl;
    }
    else
    {
        cout << "EMPLOYEE_NOT_FOUND" << endl;
    }
}

void AllEmployees::report_team_salary(int team_num)
{
    if (numebr_of_team_in_vector(team_num) != NOT_VALID)
    {
        all_teams[numebr_of_team_in_vector(team_num)]->report_team_salary();
    }
    else
    {
        cout << "TEAM_NOT_FOUND" << endl;
    }
}

void AllEmployees::report_total_hours_per_day(int sDay, int eDay)
{
    if (!is_day_valid(sDay, eDay))
    {
        cout << "INVALID_ARGUMENTS" << endl;
        return;
    }

    vector<pair<int, int>> vec;
    int max_WH = DEFULT_VALUE;
    int min_WH = MAX_OF_INT;
    if (sDay <= DAY_NUMBERS && sDay > 0 && eDay <= DAY_NUMBERS && eDay > 0)
    {
        for (int day = sDay; day <= eDay; day++)
        {
            if (get_total_hours_per_day(day) > max_WH)
            {
                max_WH = get_total_hours_per_day(day);
            }
            if (get_total_hours_per_day(day) < min_WH)
            {
                min_WH = get_total_hours_per_day(day);
            }
            vec.push_back(make_pair(get_total_hours_per_day(day), day));
            cout << "Day #" << day << ": " << get_total_hours_per_day(day) << endl;
        }
        cout << "---" << endl;
        sort(vec.begin(), vec.end());
        double min = vec[0].first;
        int min_num = DEFULT_VALUE;
        int max_num = DEFULT_VALUE;
        double max = vec[vec.size() - 1].first;

        for (int i = 0; i < vec.size(); i++)
        {
            if (vec[i].first == min)
            {
                min_num++;
            }
            else if (vec[i].first == max)
            {
                max_num++;
            }
        }

        cout << "Day(s) with Max Working Hours: ";
        for (int i = 0; i < max_num; i++)
        {
            if (i == max_num - 1)
            {
                cout << vec[vec.size() - 1 - i].second;
            }
            else
                cout << vec[vec.size() - 1 - i].second << SPACE;
        }
        cout << endl;

        cout << "Day(s) with Min Working Hours: ";
        for (int i = 0; i < min_num; i++)
        {
            if (i == min_num - 1)
            {
                cout << vec[i].second;
            }
            else
                cout << vec[i].second << SPACE;
        }
        cout << endl;
    }
    else
    {
        cout << "INVALID_ARGUMENTS" << endl;
        return;
    }
}

void AllEmployees::report_employee_per_hour(int stime, int etime)
{
    if (!is_time_valid(stime, etime))
    {
        cout << "INVALID_ARGUMENTS" << endl;
        return;
    }

    vector<pair<double, int>> vec;
    for (int i = stime; i < etime; i++)
    {
        cout << i << DASH << i + 1 << ": " << fixed << setprecision(1) << get_avarage_working_in_time(i) << endl;
        vec.push_back(make_pair(get_avarage_working_in_time(i), i));
    }
    cout << "---" << endl;
    sort(vec.begin(), vec.end());
    double min = vec[0].first;
    int min_num = 0;
    int max_num = 0;
    double max = vec[vec.size() - 1].first;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].first == min)
        {
            min_num++;
        }
        if (vec[i].first == max)
        {
            max_num++;
        }
    }

    cout << "Period(s) with Max Working Employees: ";
    for (int i = 0; i < max_num; i++)
    {
        cout << vec[vec.size() - 1 - i].second << DASH << vec[vec.size() - 1 - i].second + 1 << SPACE;
    }
    cout << endl;

    cout << "Period(s) with Min Working Employees: ";
    for (int i = 0; i < min_num; i++)
    {
        cout << vec[i].second << DASH << vec[i].second + 1 << SPACE;
    }
    cout << endl;
}

void AllEmployees::report_salaries()
{
    for (auto x : all_employees)
    {
        cout << "ID: " << x->get_emp_id() << endl;
        cout << "Name: " << x->get_emp_name() << endl;
        cout << "Total Working Hours: " << x->get_total_work_per_month() << endl;
        cout << "Total Earning: " << round(x->get_total_earning()) << endl;
        cout << "---" << endl;
    }
}

void AllEmployees::update_team_bonus(int _team_id, int _bonus_percentage)
{
    if (numebr_of_team_in_vector(_team_id) == NOT_VALID)
    {
        cout << "TEAM_NOT_FOUND" << endl;
        return;
    }
    if (_bonus_percentage < 0 || _bonus_percentage > ONE_HANDRED)
    {
        cout << "INVALID_ARGUMENTS" << endl;
        return;
    }

    all_teams[numebr_of_team_in_vector(_team_id)]->set_bonus_percentage(_bonus_percentage);
    cout << "OK" << endl;
}

void AllEmployees::Update_salary_config(vector<string> level_config_vec)
{
    int levelnumber = level_const.level_number(level_config_vec[0]);
    if (levelnumber == NOT_VALID)
    {
        cout << "INVALID_LEVEL" << endl;
        return;
    }

    level_const.set_level_config(level_config_vec, levelnumber);
    for (auto x : all_employees)
    {
        x->set_earn();
    }
    cout << "OK" << endl;
}

bool cmp(pair<int,int> p1 , pair <int,int> p2){
    if (p1.first == p2.first)
    {
        return p1.second < p2.second ;
    }
    return p1.first < p2.first;
    

}

void AllEmployees::find_teams_for_bonus()
{
    vector<pair<int, int>> vec;
    for (auto x : all_teams)
    {

        if (x->is_total_WH_valid() && x->is_WH_variance_valid())
        {
            vec.push_back(make_pair(x->get_total_WH(), x->get_team_id()));
        }
    }
    // cout << vec.size();
    if (vec.size() == DEFULT_VALUE)
    {
        cout << "NO_BONUS_TEAMS" << endl;
        return;
    }

    sort(vec.begin(), vec.end() , cmp);

    for (auto x : vec)
    {
        cout << "Team ID: " << x.second << endl;
    }
}

vector<string> split_by_commas(string str)
{
    vector<string> result;
    int start_pos = 0;
    while (start_pos < str.length())
    {
        int comma_pos = str.find(KAMA, start_pos);
        if (comma_pos == string::npos)
        {
            result.push_back(str.substr(start_pos));
            break;
        }
        result.push_back(str.substr(start_pos, comma_pos - start_pos));
        start_pos = comma_pos + 1;
    }
    return result;
}
