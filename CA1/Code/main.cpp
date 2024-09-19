
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>

#define MAX_LEN 20
using namespace std;

int showLongestNote(vector<vector<string>> note);
void printByDay(vector<vector<string>> note, string temp);
void printBestDay(vector<vector<string>> note);
void printNote(vector<vector<string>> note, int x);
void printShortNote(vector<vector<string>> note, int x);
vector<int> spliteStringToInt(string time);
string oldestDayDateToString(vector<vector<int>> oldNum);
vector<vector<int>> makeMinDateVector(vector<int> vec, vector<vector<string>> note);
string calculateBest(int max, vector<int> vec, vector<vector<string>> note);
int countCharOfNote(vector<string> note);
void printByDayShort(vector<vector<string>> note, string temp);

int main()
{
    // this vector is for all nots that save in vector of vector of string
    vector<vector<string>> note;
    // temp of each word in input
    string sTemp, lineTemp = " ";
    int isKeyWord;
    int bigNoteLength;

    // number of note
    int noteCounter = -1;

    while (!cin.eof())
    {
        isKeyWord = 0;
        getline(cin, lineTemp);
        stringstream x(lineTemp);
        while (x >> sTemp)
        {
            if (sTemp == "start_day")
            {
                // start to write new note
                note.push_back(vector<string>());
                noteCounter++;
            }
            else if (sTemp == "show_day")
            {
                isKeyWord = 1;
                x >> sTemp;
                printByDay(note, sTemp);
            }
            else if (sTemp == "show_the_longest_day")
            {
                isKeyWord = 1;
                bigNoteLength = showLongestNote(note);
                // printShortNote(note, bigNoteLength);
            }
            else if (sTemp == "show_the_best_day")
            {
                isKeyWord = 1;
                printBestDay(note);
            }
            else
            {
                note[noteCounter].push_back(sTemp);
            }
        }
        if (!isKeyWord)
        {
            note[noteCounter].push_back("\n");
        }
    }
    return 0;
}

// return number of lingest note
int showLongestNote(vector<vector<string>> note)
{
    int lengthTemp = 0;
    string stemp;
    vector<int> listOfSum;
    int numberOfNote = 0;
    for (int i = 0; i < note.size(); i++)
    {
        listOfSum.push_back(countCharOfNote(note[i]));
        if (lengthTemp < countCharOfNote(note[i]))
        {
            lengthTemp = countCharOfNote(note[i]);
            numberOfNote = i;
        }
    }
    stemp = calculateBest(countCharOfNote(note[numberOfNote]), listOfSum, note);
    printByDayShort(note, stemp);
    return numberOfNote;
}

// show by day
void printByDay(vector<vector<string>> note, string temp)
{
    for (int i = 0; i < note.size(); i++)
    {
        if (note[i][0] == temp)
        {
            printNote(note, i);
        }
    }
}

// for calculate best day
void printBestDay(vector<vector<string>> note)
{
    ifstream MyFile("positive-words.txt");
    vector<string> files;
    vector<int> listOfSum;
    // for each word of file
    string stemp;
    int sumOfSame = 0;
    int maxSumOfSame = 0;
    int numberOfNote = 0;
    while (MyFile.tellg() != (-1))
    {
        MyFile >> stemp;
        files.push_back(stemp);
    }
    for (int i = note.size() - 1; i >= 0; i--)
    {
        sumOfSame = 0;

        for (int j = 0; j < note[i].size(); j++)
        {
            for (int k = 0; k < files.size(); k++)
            {

                if (note[i][j] == files[k])
                {
                    sumOfSame++;
                }
            }
        }
        listOfSum.push_back(sumOfSame);

        if (maxSumOfSame <= sumOfSame)
        {
            maxSumOfSame = sumOfSame;
            numberOfNote = i;
        }
    }
    reverse(listOfSum.begin(), listOfSum.end());
    stemp = calculateBest(maxSumOfSame, listOfSum, note);
    printByDayShort(note, stemp);
}

// for print notes
void printNote(vector<vector<string>> note, int x)
{

    for (int i = 2; i < note[x].size(); i++)
    {
        if (note[x][i] != "\n")
        {
            if (note[x][i + 1] == "\n")
            {
                cout << note[x][i];
            }
            else
            {
                cout << note[x][i] << " ";
            }
        }
        else
        {
            cout << note[x][i];
        }
    }
}

// for print shorter of notes
void printShortNote(vector<vector<string>> note, int numberOfNote)
{
    int countOfChar = 0;
    if (countCharOfNote(note[numberOfNote]) > MAX_LEN)
    {
        cout << note[numberOfNote][0];
        cout << note[numberOfNote][1];
        for (int i = 2; i < (MAX_LEN + 1); i++)
        {
            if (note[numberOfNote][i] != "\n")
            {
                for (auto x : note[numberOfNote][i])
                {
                    if (countOfChar < MAX_LEN)
                    {
                        printf("%c", x);
                        countOfChar++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (countOfChar >= MAX_LEN)
                {
                    break;
                }
                printf(" ");
                countOfChar++;
            }
            else
            {
                for (auto x : note[numberOfNote][i])
                {
                    if (countOfChar < MAX_LEN)
                    {
                        printf("%c", x);
                        countOfChar++;
                    }
                    else
                    {
                        break;
                    }
                }
                if (countOfChar >= MAX_LEN)
                {
                    break;
                }

                printf(" ");
                countOfChar++;
            }
        }
        cout << "..."
             << "\n";
    }
    else
    {
        cout << note[numberOfNote][0];
        cout << note[numberOfNote][1];
        for (int i = 2; i < note[numberOfNote].size(); i++)
        {
            if (note[numberOfNote][i] != "\n")
            {
                if (i == (note[numberOfNote].size() - 2))
                {
                    cout << note[numberOfNote][i];
                }
                else
                {
                    cout << note[numberOfNote][i] << " ";
                }
            }
            else
            {
                cout << note[numberOfNote][i];
            }
        }
    }
}

string calculateBest(int max, vector<int> vec, vector<vector<string>> note)
{
    // vectro for list of numbers that has same name
    vector<int> numOfVec;

    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == max)
        {
            numOfVec.push_back(i);
        }
    }

    vector<vector<int>> minDateVector = makeMinDateVector(numOfVec, note);

    return oldestDayDateToString(minDateVector);
}

// make 2d vector of
vector<vector<int>> makeMinDateVector(vector<int> vec, vector<vector<string>> note)
{
    vector<vector<int>> date;

    for (int i = 0; i < vec.size(); i++)
    {
        date.push_back(spliteStringToInt(note[vec[i]][0]));
        date[i].push_back(i); // for day // mounth // year // number of state
    }
    return date;
}

// for change each string to int to date as a vector of int ;
vector<int> spliteStringToInt(string time)
{
    vector<int> times;
    string year;
    string month;
    string day;
    int countOfChar = 0;
    stringstream timeStream(time);
    getline(timeStream, day, '/');
    getline(timeStream, month, '/');
    timeStream >> year;
    times.push_back(stoi(year));
    times.push_back(stoi(month));
    times.push_back(stoi(day));
    return times;
}

string oldestDayDateToString(vector<vector<int>> oldNum)
{
    string stemp;
    sort(oldNum.begin(), oldNum.end());
    stemp += to_string(oldNum[0][2]);
    stemp += '/';
    stemp += to_string(oldNum[0][1]);
    stemp += '/';
    stemp += to_string(oldNum[0][0]);

    return stemp;
}

// for count of each note
int countCharOfNote(vector<string> note)
{
    int sumOfChar = 0;
    for (size_t i = 2; i < (int)note.size() - 1; i++)
    {
        sumOfChar += note[i].size();
    }
    return sumOfChar;
}

// for print short of it
void printByDayShort(vector<vector<string>> note, string dateOfNote)
{
    for (int i = 0; i < note.size(); i++)
    {
        if (note[i][0] == dateOfNote)
        {
            printShortNote(note, i);
        }
    }
}
