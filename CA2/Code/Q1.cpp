#include <iostream>
#include <ctype.h> 
#include <vector>
#include <algorithm>

using namespace std;


//first max 
void func(vector <int> &vecInt ,int x,int state=0 ,int lastValue=0){
    int s=state;
    int stateInVec = vecInt.size()-x-1;
    int i=1;//defult value of i is 1   -> for one step

    if ( x<0 )
    {
        return ;
    }

    if (s == 0)//max
    {
        i=max(lastValue,vecInt[stateInVec]);
        s=1;
    }else{//min
        i=min(lastValue,vecInt[stateInVec]);
        s=0;
    }
    cout << vecInt[stateInVec] << " " ;
    if (vecInt[stateInVec]==0 && lastValue==0)
    {
        return;
    }
    
    
    func(vecInt,x-i,s,vecInt[stateInVec]);
    
    
}


int main(){

    vector <int> vecInt ;
    int n;
    int iTemp;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> iTemp;
        vecInt.push_back(iTemp);
    }
    
    
    func(vecInt,vecInt.size()-1);
    
}
