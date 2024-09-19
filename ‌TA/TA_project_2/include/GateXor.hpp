//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_GATEXOR_HPP
#define TA_PROJECT_2_GATEXOR_HPP

#include "Gate.hpp"


class GateXor : public Gate {
public:
    GateXor(int numOfInputs) ;

    LogicValue compute(vector<LogicValue> inputs);
};


#endif //TA_PROJECT_2_GATEXOR_HPP
