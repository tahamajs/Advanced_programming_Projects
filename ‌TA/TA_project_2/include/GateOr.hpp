//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_GATEOR_HPP
#define TA_PROJECT_2_GATEOR_HPP

#include "Gate.hpp"
class GateOr : public Gate {
public:
    GateOr(int numOfInputs) ;

    LogicValue compute(vector<LogicValue> inputs);
};


#endif //TA_PROJECT_2_GATEOR_HPP
