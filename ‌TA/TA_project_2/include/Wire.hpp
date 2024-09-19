//
// Created by tahamajs on 8/21/24.
//

#ifndef TA_PROJECT_2_WIRE_HPP
#define TA_PROJECT_2_WIRE_HPP

#include "Constant.hpp"
#include "Utils.hpp"

class Wire {
public:
    Wire(int inputWireNumber);
    ~Wire();

    void addWire(shared_ptr<WireStructure> wire_);

    void addConnection(shared_ptr<Connection> connection);

    bool isMoudle_GateValid(string MGId);

    bool isMoudle_GateReadyValid(string MGId);

    void updateWireValues(vector<pair<string, LogicValue>> wireValues);

    string getOutputWire(string MGId);

    vector<LogicValue> getMGInputValues(string MGId){
        vector<LogicValue> values;
        for(auto wire : wires){
            if(wire->elementId == MGId && !wire->isOutput){
                values.push_back(wire->value);
            }
        }
        return values;
    }

    void setWireValues(vector<pair<string, LogicValue>> wireValues);

    void setWireValue(string wireId, LogicValue value);

    void updateWireValue(string wireId, LogicValue value);

    void updateInputWires(vector<LogicValue> values);

    void setInputWires(int numOfinputs);

    void makeNoCWireValid();

    void showWireValue(string wireId);

    LogicValue getWireValue(string wireId);

    void showAllWireValues();

    void showAllConnections();

    void showAllWires();




private:


    vector<shared_ptr<WireStructure>> wires;
    vector<shared_ptr<Connection>> connections;

    int inputNumbers;



    bool isWireConnected(string wireId);

    bool isWireOut(string wireId);

    bool isWireExist(string wireId);
};



#endif //TA_PROJECT_2_WIRE_HPP
