#include <iostream>
#include <ctype.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
int rows = 7;
int cols = 7;
int const PossibleMoves = 4;

int row_delta[] = {-2, 2, 0, 0};
int col_delta[] = {0, 0, -2, 2};

int row_delta_delete[] = {-1, 1, 0, 0};
int col_delta_delete[] = {0, 0, -1, 1};
char boardRow[7] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
string DirectionDelta[] = {"UP", "DOWN", "LEFT", "RIGHT"};

vector<pair<string, string>> Instructions;

bool checkDeleteState(vector<pair<int, int>> &myvector, int new_row_delete, int new_col_delete)
{
    for (int i = 0; i < myvector.size(); i++)
    {
        if (myvector[i] == make_pair(new_row_delete, new_col_delete))
        {
            return false;
        }
    }
    return true;
}

bool checknewState(vector<pair<int, int>> &myvector, int new_row_delete, int new_col_delete)
{
    for (int i = 0; i < myvector.size(); i++)
    {
        if (myvector[i] == make_pair(new_row_delete, new_col_delete))
        {
            return true;
        }
    }
    return false;
}

void getInput(vector<pair<int,int>> &myvector)
{
    string stemp;
    for (int i = 0; i < 7; i++)
    {
        getline(cin, stemp);
        for (int j = 0; j < 7; j++)
        {
            if (stemp[j] == 'N')
            {
                myvector.push_back(make_pair(i, j));
            }
        }
    }
}

void addInstruction(int row, int col, int state)
{
    string strTemp;
    for (int i = 0; i < 7; i++)
    {
        if (row == i)
        {
            strTemp = boardRow[i];
        }
    }
    strTemp += to_string(col + 1);
    Instructions.push_back(make_pair(strTemp, DirectionDelta[state]));
}

void deleteInstruction(){
    Instructions.pop_back();
}

//this function is for change vector back 
void checkBack(vector<pair<int, int>> &myvector, int x, int y, int px, int py)
{
    for (int i = 0; i < myvector.size(); i++)
    {
        if (myvector[i] == make_pair(x, y))
        {

            myvector[i].first -= px;
            myvector[i].second -= py;
        }
    }
}

void deletePair(vector<pair<int, int>> &myvector, int x, int y)
{
    for (int i = 0; i < myvector.size(); i++)
    {
        if (myvector[i] == make_pair(x, y))
        {
            myvector[i].first = -1;
            myvector[i].second = -1;
        }
    }
}

void printInstructions()
{
    if (Instructions.size() == 0)
    {
        cout << "Loser";
        return;
    }

    for (int i = 0; i < Instructions.size(); i++)
    {
        cout << Instructions[i].first << " " << Instructions[i].second << endl;
    }
}

// for delete from vector of pair
int delete_from_vector(vector<pair<int, int>> &myvector, int x, int y)
{
    int cnt = 0;
    for (auto i = myvector.begin(); i != myvector.end(); ++i)
    {
        cnt++;
        if (*i == make_pair(x, y))
        {
            myvector.erase(i);
            i--;
            return cnt - 1;
        }
    }
}

bool play(vector<pair<int, int>> &players)
{
    if (players.size() == 1)
    {
        if (players[0] == make_pair(3, 3))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    for (int i = players.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < PossibleMoves; j++)
        {

            int New_row = players[i].first + row_delta[j];
            int New_col = players[i].second + col_delta[j];

            int New_row_delete = players[i].first + row_delta_delete[j];
            int New_col_delete = players[i].second + col_delta_delete[j];

            if (((New_row < 2 && New_col < 2) || (New_col < 2 && New_row > 4) || (New_row < 2 && New_col > 4) || (New_row > 4 && New_col > 4)))
            {
                continue;
                ;
            }

            if (checkDeleteState(players, New_row_delete, New_col_delete))
            {
                continue;
            }

            if (checknewState(players, New_row, New_col))
            {
                continue;
            }

            addInstruction(players[i].first, players[i].second, j);

            players[i].first = New_row;
            players[i].second = New_col;
            int c = delete_from_vector(players, New_row_delete, New_col_delete);

            if (play(players))
            {
                return true;
            }

            deleteInstruction();
            checkBack(players, New_row, New_col, row_delta[j], col_delta[j]);

            players.insert(players.begin() + c, make_pair(New_row_delete, New_col_delete));
        }
    }
    return false;
}

int main()
{
    vector<pair<int,int>> players;
    getInput(players);
    play(players);
    printInstructions();
}
