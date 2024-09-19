#include <iostream>
#include <vector>
#include <utility>
#include <strstream>
#include <sstream>
#include <algorithm>

using namespace std;

// for choosing time in week
typedef pair<int, int> timeInWeek;

// this is for times in class teacher name : class name
typedef pair<string, string> Class;

const int NUMBER_OF_DAY_IN_WEEK = 5;
string DAYS_IN_WEEK[5] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday"};

struct Time
{
    int hour;
    int minute;
};

struct teacher
{
    string teacher_name;
    vector<string> lesson;
    bool times[5][3] = {{false, false, false}, {false, false, false}, {false, false, false}, {false, false, false}, {false, false, false}};
    int numberOfDayInWeek;
};

struct lesson
{
    string lesson_name;
    int day1;
    int day2;
    bool times[5][3] = {{false, false, false}, {false, false, false}, {false, false, false}, {false, false, false}, {false, false, false}};
    bool isChoos[2] = {false, false};
    string teacher_name[2];
    pair<int, int> timeThatChoos[2];
};

void print_out_put(vector<lesson> lessons);
bool my_cmp(const lesson &a, const lesson &b);
void print_out_put(vector<lesson> lessons);
string date_to_string(int x);
void put_teachers_times_false(teacher &teacher, lesson lesson, int bell);
void getDaysForTeacher(teacher &teacherTemp, int numberOfDays);
void get_teachers_input(vector<teacher> &teachers);
void fill_bell(bool day[3], Time startTime, Time EndTime);
void set_time_for_lesson(lesson &lesson);
void print_lessons_data(vector<lesson> lessons);
void get_lesson_input(vector<lesson> &lessons);
Time string_to_time(string time);
void fill_bell_for_lessons(int day1, int day2, bool times[5][3]);
void print_teachers_data(vector<teacher> teachers);
bool check_teacher_lesson(vector<teacher> &teachers, vector<lesson> lessons, int day, int bell, int classNumber);
int cheack_lessons_with_alphabets(vector<lesson> lvec);
int cheack_teachers_with_alphabets(vector<teacher> tvec);
int choose_lesson(int day, int bell, vector<lesson> &lessons, int classNumber, vector<teacher> &teachers, vector<vector<vector<bool>>> &classs);
int check_each_teacher_with_lesson(int day, int bell, teacher teachers, string nameOfLessonThatChoos);
bool is_all_teachers_day_equal(vector<teacher> tvec);
int biggest_number_of_day(vector<teacher> tvec);
int choose_teacher(int day, int bell, vector<teacher> &teachers, lesson lesson);
int check_each_teacher_with_lesson(int day, int bell, teacher teachers, lesson lesson);
void choose(vector<teacher> &teachers, vector<lesson> &lessons, vector<vector<vector<bool>>> &classs);
void choose_chos(vector<teacher> &teachers, vector<lesson> &lessons, vector<vector<vector<bool>>> &classs);
int check_teacher_with_lesson(int day, int bell, vector<teacher> &teachers, lesson lesson, vector<vector<vector<bool>>> &classs, int classNumber);
vector<vector<vector<bool>>> make_class_board();

int main()
{

    vector<vector<vector<bool>>> bclass = make_class_board();

    vector<teacher> teachers;
    vector<lesson> lessons;

    get_teachers_input(teachers);
    get_lesson_input(lessons);

    choose(teachers, lessons, bclass);
    print_out_put(lessons);
}

vector<vector<vector<bool>>> make_class_board()
{

    vector<vector<vector<bool>>> bclass;
    vector<bool> b1vec;
    vector<vector<bool>> b2vec;

    for (int i = 0; i < 3; i++)
    {
        b1vec.push_back(true);
    }
    for (int i = 0; i < 5; i++)
    {
        b2vec.push_back(b1vec);
    }

    for (int i = 0; i < 2; i++)
    {
        bclass.push_back(b2vec);
    }
    return bclass;
}

// for put days of each teache in time attrebute
void getDaysForTeacher(teacher &teacherTemp, int numberOfDays)
{
    string dayTemp;
    for (int i = 0; i < numberOfDays; i++)
    {
        cin >> dayTemp;
        for (int p = 0; p < NUMBER_OF_DAY_IN_WEEK; p++)
        {

            if (dayTemp == DAYS_IN_WEEK[p])
            {
                for (int c = 0; c < 3; c++)
                {
                    teacherTemp.times[p][c] = true;
                }
            }
        }
    }
}

// for each line
void get_teachers_input(vector<teacher> &teachers)
{

    string stemp;
    int itemp;
    int numberOfTeachers;

    cin >> numberOfTeachers;
    for (int i = 0; i < numberOfTeachers; i++)
    {
        teacher teacherTemp;
        cin >> stemp;
        teacherTemp.teacher_name = stemp;

        cin >> itemp;
        teacherTemp.numberOfDayInWeek = itemp;
        getDaysForTeacher(teacherTemp, itemp);

        cin >> itemp;
        for (int i = 0; i < itemp; i++)
        {
            cin >> stemp;
            teacherTemp.lesson.push_back(stemp);
        }
        teachers.push_back(teacherTemp);
    }
}

void fill_bell(bool day[3], Time startTime, Time EndTime)
{
    float sTime = startTime.hour + (float(startTime.minute) / 60);
    float eTime = EndTime.hour + (float(EndTime.minute) / 60);

    if ((sTime <= 7.5) && (eTime >= 9))
    {
        day[0] = true;
    }
    if ((sTime <= 9.5) && (eTime >= 11))
    {
        day[1] = true;
    }
    if ((sTime <= 11.5) && (eTime >= 13))
    {
        day[2] = true;
    }
}

Time string_to_time(string time)
{
    stringstream stime(time);
    Time TempTime;
    string hour, minute;
    getline(stime, hour, ':');
    getline(stime, minute);
    TempTime.hour = stoi(hour);
    TempTime.minute = stoi(minute);
    return TempTime;
}

void fill_bell_for_lessons(int day1, int day2, bool times[5][3])
{
    string startTime, endTime;
    cin >> startTime;
    cin >> endTime;
    fill_bell(times[day1], string_to_time(startTime), string_to_time(endTime));
    fill_bell(times[day2], string_to_time(startTime), string_to_time(endTime));
}

void set_time_for_lesson(lesson &lesson)
{
    string day1;
    string day2;
    vector<int> IntDaysInWeek;
    cin >> day1;
    cin >> day2;

    for (int i = 0; i < NUMBER_OF_DAY_IN_WEEK; i++)
    {
        if (DAYS_IN_WEEK[i] == day1 || DAYS_IN_WEEK[i] == day2)
        {
            IntDaysInWeek.push_back(i);
        }
    }
    lesson.day1 = IntDaysInWeek[0];
    lesson.day2 = IntDaysInWeek[1];

    fill_bell_for_lessons(IntDaysInWeek[0], IntDaysInWeek[1], lesson.times);
}

void get_lesson_input(vector<lesson> &lessons)
{
    int itemp;
    string stemp;
    int NUmOfLessons;

    cin >> NUmOfLessons;

    for (int p = 0; p < NUmOfLessons; p++)
    {
        lesson lessonTemp = {};
        cin >> stemp;
        lessonTemp.lesson_name = stemp;
        set_time_for_lesson(lessonTemp);
        lessons.push_back(lessonTemp);
    }
}

bool check_teacher_lesson(vector<teacher> &teachers, vector<lesson> lessons, int day, int bell, int classNumber)
{
    for (int i = 0; i < lessons.size(); i++)
    {
        if (lessons[i].times[day][bell] && !lessons[i].isChoos[classNumber])
        {
            for (int p = 0; p < teachers.size(); p++)
            {
                if (teachers[p].times[day][bell])
                {
                    for (int q = 0; q < teachers[p].lesson.size(); q++)
                    {
                        if (lessons[i].lesson_name == teachers[p].lesson[q])
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

int cheack_lessons_with_alphabets(vector<lesson> lvec)
{
    int iTemp = 0;
    for (int i = 0; i < lvec.size(); i++)
    {
        if (lvec[iTemp].lesson_name.compare(lvec[i].lesson_name) > 0)
        {
            iTemp = i;
        }
    }
    return iTemp;
}

int cheack_teachers_with_alphabets(vector<teacher> tvec)
{
    int iTemp = 0;
    for (int i = 0; i < tvec.size(); i++)
    {
        if (tvec[iTemp].teacher_name.compare(tvec[i].teacher_name) > 0)
        {
            iTemp = i;
        }
    }
    return iTemp;
}

int choose_lesson(int day, int bell, vector<lesson> &lessons, int classNumber, vector<teacher> &teachers, vector<vector<vector<bool>>> &classs)
{
    vector<lesson> lessonsTemp; // valid lessons in vector
    vector<int> lessonNumber;
    bool flag = false;
    // for check lessons that are currect
    for (int i = 0; i < lessons.size(); i++)
    {
        flag = false;
        if (lessons[i].times[day][bell] && !lessons[i].isChoos[classNumber])
        {

            if (check_teacher_with_lesson(day, bell, teachers, lessons[i], classs, classNumber))
            {
                lessonsTemp.push_back(lessons[i]);
                lessonNumber.push_back(i);
            }
        }
    }

    // cout << lessonsTemp.size();
    if (lessonsTemp.size() == 1)
    {
        return lessonNumber[0];
    }
    else if (lessonsTemp.size() > 1)
    {
        return lessonNumber[cheack_lessons_with_alphabets(lessonsTemp)];
    }
    else
    {
        return -1;
    }
}

// for check that we have teacher with that time and lesson or noot
int check_each_teacher_with_lesson(int day, int bell, teacher teachers, lesson lesson)
{

    for (int p = 0; p < teachers.lesson.size(); p++)
    {
        if ((teachers.lesson[p] == lesson.lesson_name) && teachers.times[lesson.day1][bell] && teachers.times[lesson.day2][bell])
        {
            return true;
        }
    }
    return false;
}

bool is_all_teachers_day_equal(vector<teacher> tvec)
{

    int iTemp = tvec[0].numberOfDayInWeek;
    for (int i = 1; i < tvec.size(); i++)
    {

        if (iTemp != tvec[i].numberOfDayInWeek)
        {
            return false;
        }
    }

    return true;
}

int biggest_number_of_day(vector<teacher> tvec)
{
    int iTemp = tvec[0].numberOfDayInWeek;
    int numberOfTeacher = 0;

    for (int i = 0; i < tvec.size(); i++)
    {
        // cout << tvec[i].teacher_name << tvec[i].numberOfDayInWeek << " ";
        if (iTemp > tvec[i].numberOfDayInWeek)
        {

            iTemp = tvec[i].numberOfDayInWeek;
            numberOfTeacher = i;
        }
    }
    // cout << numberOfTeacher << endl;

    return numberOfTeacher;
}

int choose_teacher(int day, int bell, vector<teacher> &teachers, lesson lesson)
{
    vector<teacher> teachersTemp; // valid teacher in vector
    vector<int> teachersNumber;
    bool lessonFlag = false;

    for (int i = 0; i < teachers.size(); i++)
    {
        if (check_each_teacher_with_lesson(day, bell, teachers[i], lesson))
        {
            teachersTemp.push_back(teachers[i]);
            teachersNumber.push_back(i);
        }
    }

    int numOfMin = biggest_number_of_day(teachersTemp);

    if (teachersTemp.size() == 1)
    {
        return teachersNumber[0];
    }

    vector<teacher>::iterator it1 = teachersTemp.begin();
    vector<int>::iterator it2 = teachersNumber.begin();

    //for delete all not equal to min number
    for (int i = 0; i < teachersTemp.size(); i++)
    {
        if (teachersTemp[numOfMin].numberOfDayInWeek != teachersTemp[i].numberOfDayInWeek)
        {
            teachersTemp.erase(it1);

            teachersNumber.erase(it2);
            // break;
        }
        it1++;
        it2++;
    }

    if (teachersTemp.size() == 1)
    {
        return teachersNumber[0];
    }

    if (!is_all_teachers_day_equal(teachersTemp)) // مساوی نبود
    {

        return teachersNumber[biggest_number_of_day(teachersTemp)];
    }
    // مساوی بود
    return teachersNumber[cheack_teachers_with_alphabets(teachersTemp)];
}

// for check that we have teacher with that time and lesson or noot
int check_teacher_with_lesson(int day, int bell, vector<teacher> &teachers, lesson lesson, vector<vector<vector<bool>>> &classs, int classNumber)
{
    vector<teacher> teachersTemp; // valid teacher in vector
    vector<int> teachersNumber;
    bool lessonFlag = false;

    for (int i = 0; i < teachers.size(); i++)
    {
        for (int p = 0; p < teachers[i].lesson.size(); p++)
        {
            if ((teachers[i].lesson[p] == lesson.lesson_name) && teachers[i].times[lesson.day1][bell] && teachers[i].times[lesson.day2][bell] && classs[classNumber][lesson.day1][bell] && classs[classNumber][lesson.day2][bell])
            {
                return true;
            }
        }
    }
    return false;
}

void put_teachers_times_false(teacher &teacher, lesson lesson, int bell)
{
    teacher.times[lesson.day1][bell] = false;
    teacher.times[lesson.day2][bell] = false;
}

void choose(vector<teacher> &teachers, vector<lesson> &lessons, vector<vector<vector<bool>>> &classs)
{

    int teacherNumber;
    int lessonNumber;

    for (int classNomber = 0; classNomber < 2; classNomber++)
    {
        for (int dayNomber = 0; dayNomber < 5; dayNomber++)
        {
            for (int bell = 0; bell < 3; bell++)
            {

                if (classs[classNomber][dayNomber][bell] == true)
                {

                    if (check_teacher_lesson(teachers, lessons, dayNomber, bell, classNomber))
                    {

                        // for number of teacher and lesson in this time in week

                        lessonNumber = choose_lesson(dayNomber, bell, lessons, classNomber, teachers, classs);
                        if (lessonNumber == -1)
                        {
                            continue;
                        }
                        if (check_teacher_with_lesson(dayNomber, bell, teachers, lessons[lessonNumber], classs, classNomber))
                        {
                            teacherNumber = choose_teacher(dayNomber, bell, teachers, lessons[lessonNumber]);
                            classs[classNomber][lessons[lessonNumber].day1][bell] = false;
                            classs[classNomber][lessons[lessonNumber].day2][bell] = false;
                            lessons[lessonNumber].isChoos[classNomber] = true;
                            lessons[lessonNumber].teacher_name[classNomber] = teachers[teacherNumber].teacher_name;
                            lessons[lessonNumber].timeThatChoos[classNomber] = make_pair(dayNomber, bell);
                            put_teachers_times_false(teachers[teacherNumber], lessons[lessonNumber], bell);
                        }
                    }
                }
            }
        }
    }
}

bool my_cmp(const lesson &a, const lesson &b)
{
    // smallest comes first
    return (a.lesson_name.compare(b.lesson_name)) <= 0;
}

string date_to_string(int x)
{
    string sTemp;
    if (x == 0)
    {
        sTemp = "07:30 09:00";
    }
    else if (x == 1)
    {
        sTemp = "09:30 11:00";
    }
    else if (x == 2)
    {

        sTemp = "11:30 13:00";
    }
    return sTemp;
}

void print_out_put(vector<lesson> lessons)
{
    vector<lesson> lessonsTemp = lessons;
    sort(lessonsTemp.begin(), lessonsTemp.end(), my_cmp);

    for (int i = 0; i < lessonsTemp.size(); i++)
    {
        cout << lessonsTemp[i].lesson_name << endl;
        if (lessonsTemp[i].isChoos[0])
        {
            cout << lessonsTemp[i].teacher_name[0] << ": " << date_to_string(lessonsTemp[i].timeThatChoos[0].second) << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
        if (lessonsTemp[i].isChoos[1])
        {
            cout << lessonsTemp[i].teacher_name[1] << ": " << date_to_string(lessonsTemp[i].timeThatChoos[1].second) << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }
}