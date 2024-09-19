//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_GATENOT_HPP
#define TA_PROJECT_2_GATENOT_HPP

#include "Gate.hpp"


class GateNot : public Gate {
public:
    GateNot(int numOfInputs);

    LogicValue compute(vector<LogicValue> inputs);
};


#endif //TA_PROJECT_2_GATENOT_HPP
