//
// Created by tahamajs on 8/16/24.
//

#include "../include/GateNand.hpp"


GateNand::GateNand(int numOfInputs) : Gate(numOfInputs)
{

}


LogicValue GateNand::compute(vector<LogicValue> inputs) {
    if (inputs.size() != numOfInputs) {
        throw invalid_argument("Invalid number of inputs");
    }

    for (int i = 0; i < inputs.size(); i++) {
        if (inputs[i] == LogicValue::Z) {
            return LogicValue::Z;
        } else if (inputs[i] == LogicValue::ZERO) {
            return LogicValue::ONE;
        }
    }


    return LogicValue::ZERO;
}





