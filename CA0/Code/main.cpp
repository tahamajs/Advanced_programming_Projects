#include <iostream>
using namespace std ;
int main(){
    int NumOfProgramm , MaxTime , MaxLengh, NumTime ,Time=0 ;
    int flag = 0;

    cin >> NumOfProgramm;

    for (int i = 0; i < NumOfProgramm; i++)
    {
        cin >> MaxTime >> MaxLengh >> NumTime;
        flag= 0;
        Time=0;
        for (int j = 0; j < NumTime; j++)
        {
            
            int StartTime , EndTime;
            cin >> StartTime >> EndTime;
            Time+= EndTime - StartTime;
            if ((EndTime - StartTime)>MaxLengh )
            {
                flag = 1;
            }
            

        }
        if (Time> MaxTime)
        {
            flag = 1;
        }
        if (flag)
        {
            cout << 0;
        }else
            cout << 1;
    }
    
    return 0;
}