#include <iostream>
#include <ctype.h> 
#include <vector>
#include <algorithm>


using namespace std;
int rows=3;
int cols=3;
int solutions=0;
int const PossibleMoves = 2;

int row_delta[]={-1,0};
int col_delta[]={0,1};



void findSol(int currentRow ,int currentCol){
    if (currentRow==0 && currentCol==cols)
    {
        solutions++;
        return;
    }

    for (int move = 0; move < PossibleMoves; move++)
    {
        
        int new_row = currentRow + row_delta[move];
        int new_col = currentCol + col_delta[move];
        if (new_row > rows || new_row < 0 || new_col > cols || new_col < 0)
        {
            continue;
        }
        if ((new_col+new_row) > rows )
        {
            continue;
        }
        findSol(new_row,new_col);
        
    }
    
    
}

int main(){
    int n;
    cin >> n;
    rows=n;
    cols=n;
    findSol(n,0);
    cout << solutions;
    
}
