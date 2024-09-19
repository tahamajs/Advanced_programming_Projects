//
// Created by tahamajs on 8/16/24.
//

#include "../include/GateNot.hpp"


GateNot::GateNot(int numOfInputs) : Gate(numOfInputs) {
    //
}

LogicValue GateNot::compute(vector<LogicValue> inputs) {

    if (inputs[0] == LogicValue::Z) {
        return LogicValue::Z;
    }

    return (inputs[0] == LogicValue::ONE) ? LogicValue::ZERO : LogicValue::ONE;
}
