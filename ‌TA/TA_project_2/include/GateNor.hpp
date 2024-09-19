//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_GATENOR_HPP
#define TA_PROJECT_2_GATENOR_HPP


#include "Gate.hpp"


class GateNor : public Gate {
public:
    GateNor(int numOfInputs);
    LogicValue compute(vector<LogicValue> inputs);


};


#endif //TA_PROJECT_2_GATENOR_HPP
