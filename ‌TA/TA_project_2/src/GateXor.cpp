//
// Created by tahamajs on 8/16/24.
//

#include "../include/GateXor.hpp"



GateXor::GateXor(int numOfInputs) : Gate(numOfInputs) {
    //
}



LogicValue GateXor::compute(vector<LogicValue> inputs) {
    if (inputs.size() != numOfInputs) {
        throw invalid_argument("Invalid number of inputs");
    }

    LogicValue result = LogicValue::ZERO;

    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i] == LogicValue::Z) {
            return LogicValue::Z;
        } else if (inputs[i] == LogicValue::ONE) {
            result = (result == LogicValue::ZERO) ? LogicValue::ONE : LogicValue::ZERO;
        }
    }

    return result;
}


