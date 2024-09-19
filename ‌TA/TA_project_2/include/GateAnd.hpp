//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_GATEAND_HPP
#define TA_PROJECT_2_GATEAND_HPP

#include "Gate.hpp"

class GateAnd : public Gate {
public:
    GateAnd(int numOfInputs);

    LogicValue compute(vector<LogicValue> inputs);
};


#endif //TA_PROJECT_2_GATEAND_HPP
