#include <iostream>
using namespace std ;
int main(){
    int NumOfProgramm , MaxTime , MaxLengh, NumTime ,Time=0 , AddTime=0, AddTimeLength=0;
    int flag1 = 0, flag2=0;

    cin >> NumOfProgramm;

    for (int i = 0; i < NumOfProgramm; i++)
    {
        cin >> MaxTime >> MaxLengh >> NumTime;
        AddTime=0;
        AddTimeLength = 0;
        flag1= 0;
        flag2 = 0;
        Time=0;
        for (int j = 0; j < NumTime; j++)
        {
            
            int StartTime , EndTime;
            cin >> StartTime >> EndTime;
            Time+= EndTime - StartTime;
            if ((EndTime - StartTime)>MaxLengh )
            {
                if (AddTime<((EndTime - StartTime)-MaxLengh))
                {
                    AddTime=((EndTime - StartTime)-MaxLengh);
                }
                
            }
            

        }
        if (Time> MaxTime)
        {
            AddTimeLength= Time-MaxTime;
        }
        cout << AddTimeLength << " " << AddTime << "\n";

    }
    
    return 0;
}