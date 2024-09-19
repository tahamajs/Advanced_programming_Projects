//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_GATENAND_HPP
#define TA_PROJECT_2_GATENAND_HPP


#include "Gate.hpp"

class GateNand : public Gate {
public:
    GateNand(int numOfInputs);
    LogicValue compute(vector<LogicValue> inputs);


};


#endif //TA_PROJECT_2_GATENAND_HPP
