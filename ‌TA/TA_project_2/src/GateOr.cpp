//
// Created by tahamajs on 8/16/24.
//

#include "../include/GateOr.hpp"



GateOr::GateOr(int numOfInputs) : Gate(numOfInputs) {
    //
}


LogicValue GateOr::compute(vector<LogicValue> inputs){
    if (inputs.size() != numOfInputs){
        throw invalid_argument("Invalid number of inputs");

    }
    LogicValue result = LogicValue::Z ;
    for (int i = 0; i < inputs.size(); i++){
        if (inputs[i] == LogicValue::Z){
            result = LogicValue::Z;
            break;
        }
        else if (inputs[i] == LogicValue::ONE){
            result = LogicValue::ONE;
        }

    }
    return result;





}


