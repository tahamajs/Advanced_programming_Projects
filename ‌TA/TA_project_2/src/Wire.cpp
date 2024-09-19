//
// Created by tahamajs on 8/21/24.
//
#include "../include/Wire.hpp"

Wire::Wire(int inputWireNumber): inputNumbers(inputWireNumber){
    //
}

Wire::~Wire(){
    //
}

void Wire::addWire(shared_ptr<WireStructure> wire_){

    for(auto wire : wires){
        if(wire->wireId == wire_->wireId){
            throw DuplicateID();
        }
    }

    wires.push_back(wire_);
}

bool Wire::isMoudle_GateValid(string MGId){
    bool valid = true;
    for(auto wire : wires){
        if(wire->elementId == MGId && !wire->isValid){
            valid = false;
            break;
        }
    }
    return valid;
}

void Wire::addConnection(shared_ptr<Connection> connection){
    bool isnotValid = true;

    for (const auto& wire : wires) {
        for (const auto& wwire : wires) {
            if (wire->wireId == connection->inWire && wwire->wireId == connection->outWire) {
                isnotValid = false;
                break;
            }
        }
    }
    if (isnotValid) {
        for (const auto& wire : wires) {
            if ((isWireConnected(connection->inWire) && !isWireOut(connection->inWire)) ||
                (isWireConnected(connection->outWire) && !isWireOut(connection->outWire))) {
                throw InvalidConnection();
            }
        }
    }



    connections.push_back(connection);
}

bool Wire::isMoudle_GateReadyValid(string MGId){
    bool valid = true;
    for(auto wire : wires) {
//        cout << "wire->elementId: " << wire->elementId << " wire->isValid: " << wire->isValid << " wire->isOutput: " << wire->isOutput << " wire->value: " << wire->value << endl;
        if (wire->elementId == MGId && !wire->isValid && !wire->isOutput) {
            valid = false;
            break;
        } else if (wire->elementId == MGId && wire->isValid && wire->isOutput) {
            valid = false;
            break;
        }

    }
    return valid;
}

void Wire::updateWireValues(vector<pair<string, LogicValue>> wireValues){
    for(auto wireValue : wireValues){
        updateWireValue(wireValue.first, wireValue.second);
    }
}

string Wire::getOutputWire(string MGId){
    for(auto wire : wires){
        if(wire->elementId == MGId && wire->isOutput){
            return wire->wireId;
        }
    }

    throw IDNotFound();
}

void Wire::setWireValues(vector<pair<string, LogicValue>> wireValues){
    for(auto wireValue : wireValues){
        setWireValue(wireValue.first, wireValue.second);
    }
}

void Wire::setWireValue(string wireId, LogicValue value){
    if(isWireOut(wireId)){
        throw InvalidInput();
    }

}

void Wire::updateWireValue(string wireId, LogicValue value) {
    bool found = false;

    for (auto& wire : wires) {
        if (wire->wireId == wireId) {
//            cout << "wire->wireId: " << wire->wireId << " wire->elementId: " << wire->elementId << " wire->value: " << wire->value << " wire->inputIndex: " << wire->inputIndex << " wire->isOutput: " << wire->isOutput << " wire->isModule: " << wire->isModule << " wire->isValid: " << wire->isValid << " value: " << value << endl;
            wire->value = value;
            wire->isValid = true;
            found = true;
            break;
        }
    }

    if (!found) {
        throw IDNotFound();
    }

    for (const auto& connection : connections) {
        if (connection->inWire == wireId || connection->outWire == wireId) {
            for (auto& wire : wires) {
                if ((wire->wireId == connection->outWire && connection->inWire == wireId) ||
                    (wire->wireId == connection->inWire && connection->outWire == wireId)) {
//                    cout << "wire->wireId: " << wire->wireId << " wire->elementId: " << wire->elementId << " wire->value: " << wire->value << " wire->inputIndex: " << wire->inputIndex << " wire->isOutput: " << wire->isOutput << " wire->isModule: " << wire->isModule << " wire->isValid: " << wire->isValid << endl;
                    wire->value = value;
                    wire->isValid = true;
                }
            }
        }
    }


}

void Wire::updateInputWires(vector<LogicValue> values){
    if (inputNumbers != values.size()){
        throw InvalidInput();
    }
    if(inputNumbers != values.size()){
        throw InvalidInput();
    }
    for(int i = 0; i < values.size(); i++){
        updateWireValue("in" + to_string(i), values[i]);
    }

}

void Wire::setInputWires(int numOfinputs){
    for(int i = 0; i < numOfinputs; i++){
        shared_ptr<WireStructure> wire = make_shared<WireStructure>();
        wire->wireId = "in" + to_string(i);
        wire->elementId = SELF_MODULE;
        wire->value = LogicValue::Z;
        wire->inputIndex = i;
        wire->isOutput = false;
        wire->isModule = false;
        wire->isValid = false;
        wires.push_back(wire);
    }
    shared_ptr<WireStructure> wire = make_shared<WireStructure>();
    wire->wireId = OUT_WIRE;
    wire->elementId = SELF_MODULE;
    wire->value = LogicValue::Z;
    wire->inputIndex = -1;
    wire->isOutput = true;
    wire->isModule = false;
    wire->isValid = false;
    wires.push_back(wire);


}

void Wire::makeNoCWireValid(){
    for(auto wire : wires){

        if (!isWireConnected(wire->wireId) && !wire->isValid && !isWireOut(wire->wireId)){
            wire->isValid = true;
        }
    }
}

void Wire::showWireValue(string wireId){
    for(auto wire : wires){
        if(wire->wireId == wireId){
            cout << "Wire " << wireId << " has value: " << changeLogicValueToString(wire->value) << endl;
            break;
        }
    }
}

LogicValue Wire::getWireValue(string wireId){
    for(auto wire : wires){
        if(wire->wireId == wireId){
            return wire->value;
        }
    }
    return LogicValue::Z;
}

void Wire::showAllWireValues(){
    for(auto wire : wires){
        cout << "Wire " << wire->wireId << " has value: " << changeLogicValueToString(wire->value) << " and is connected to " << wire->elementId << "isvalid" << wire->isValid << endl;
    }
}

void Wire::showAllConnections(){
    for(auto connection : connections){
        cout << "Connection from " << connection->inWire << " to " << connection->outWire << endl;
    }
}

void Wire::showAllWires(){
    for(auto wire : wires){
        cout << "Wire " << wire->wireId << " is connected to " << wire->elementId << " and has value: " << changeLogicValueToString(wire->value) << endl;
    }
}

bool Wire::isWireConnected(string wireId){
    for(auto connection : connections){
        if(connection->inWire == wireId || connection->outWire == wireId){
            return true;
        }
    }
    return false;
}

bool Wire::isWireOut(string wireId){
    for(auto wire : wires){
        if(wire->wireId == wireId && wire->isOutput){
            return true;
        }
    }
    return false;
}

bool Wire::isWireExist(string wireId){
    for(auto wire : wires){
        if(wire->wireId == wireId){
            return true;
        }
    }
    return false;
}

