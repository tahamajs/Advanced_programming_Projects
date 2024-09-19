//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_GATE_HPP
#define TA_PROJECT_2_GATE_HPP

# include "Constant.hpp"

class Gate {
public:
    Gate(int numOfInputs) : numOfInputs(numOfInputs) {}

    virtual LogicValue compute(vector<LogicValue> inputs) = 0;

    virtual ~Gate() = default;

protected:
    int numOfInputs;
};
#endif //TA_PROJECT_2_GATE_HPP
