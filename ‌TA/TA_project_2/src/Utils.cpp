//
// Created by tahamajs on 8/16/24.
//

#include "../include/Utils.hpp"

vector<string> splitByDelimiter(string str){
    vector<string> result;
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == DELIMITER)
        {
            result.push_back(temp);
            temp = "";
        }
        else
        {
            temp += str[i];
        }
    }
    result.push_back(temp);
    return result;
}

string changeLogicValueToString(LogicValue value){
    if (value == LogicValue::ZERO)
    {
        return "0";
    }
    else if (value == LogicValue::ONE)
    {
        return "1";
    }
    else
    {
        return "X";
    }
}

