//
// Created by tahamajs on 8/16/24.
//

#include "../include/InputHandler.hpp"



InputHandler::InputHandler() {
    circuit = new Circuit();
}



InputHandler::~InputHandler() {
    delete circuit;
}


void InputHandler::setValue() {
    string wireName;
    string value;

    command_line >> wireName;
    command_line >> value;

    LogicValue logicValue;
    if (value == "0") {
        logicValue = LogicValue::ZERO;
    } else if (value == "1") {
        logicValue = LogicValue::ONE;
    } else if (value == "Z") {
        logicValue = LogicValue::Z;
    } else {
        throw InvalidValue();
    }

    circuit->set_other_inputs(wireName, logicValue);
}



void InputHandler::run() {
    string command;
    string input_line;
    while (getline(cin, input_line)) {
        try {
            command_line.clear();
            command_line.str(input_line);
            handle_command();
        } catch (const DuplicateID &e) {
            cout << e.what() << endl;
        } catch (const InvalidConnection &e) {
            cout << e.what() << endl;
        } catch (const IDNotFound &e) {
            cout << e.what() << endl;
        } catch (const InvalidValue &e) {
            cout << e.what() << endl;
        } catch (const GateNotFound &e) {
            cout << e.what() << endl;
        } catch (const ModuleNotFound &e) {
            cout << e.what() << endl;
        } catch (const DuplicateModule &e) {
            cout << e.what() << endl;
        } catch (const exception &e) {
            cout << BadExeption << endl;
        }
    }
}


string InputHandler::changeLogicValueToString(LogicValue logicValue){
    if (logicValue == LogicValue::ZERO)
    {
        return LogicValueZero;
    }
    else if (logicValue == LogicValue::ONE)
    {
        return LogicValueOne;
    }
    else if (logicValue == LogicValue::Z)
    {
        return LogicValueZ;
    }
    else
    {
        throw InvalidValue();
    }
}

void InputHandler::handle_command() {
    string Instruction;
    command_line >> Instruction;
    auto it = commandMap.find(Instruction);
    if (it != commandMap.end()) {
        (this->*(it->second))();
    } else {
        throw CommandNotFound();
    }
}

void InputHandler::showValue() {
    string Gate_ModuleID;
    command_line >> Gate_ModuleID;

    vector<string> Module_hierarchy = splitByDelimiter(Gate_ModuleID);
    cout << changeLogicValueToString(circuit->UpdateState(Module_hierarchy)) << endl;
}

void InputHandler::addModules_Gates(){
    pair<pair<string,string>,vector<int>> gateInfo = addModules_GatesExtract();
    circuit->addGate_Module(gateInfo.second , gateInfo.first.second , gateInfo.first.first );

}

pair<string, string> InputHandler::connectWireExtract(){
    string wireName1;
    string wireName2;
    command_line >> wireName1;
    command_line >> wireName2;
    return make_pair(wireName1,wireName2);

}

void InputHandler::connectWire(){
    string wireName1;
    string wireName2;
    command_line >> wireName1;
    command_line >> wireName2;
    circuit->addConnection(make_pair(wireName1, wireName2));

}

void InputHandler::newModule() {
    string moduleName;
    int numOfInputs;
    string command;

    command_line >> moduleName;
    command_line >> numOfInputs;

    New_Module_Info newModuleInfo;
    vector<pair<pair<string, string>, vector<int>>> gates_modules;

    string input_line;

    while (getline(cin, input_line)) {
        command_line.clear();
        command_line.str(input_line);
        command_line >> command;

        if (command == REQUERST_END_MODULE) {
            break;
        } else if (command == REQUERST_ADD_MODULES_GATES) {
            newModuleInfo.gates_modules.push_back(addModules_GatesExtract());
        } else if (command == REQUERST_CONNECT_WIRE) {
            newModuleInfo.connections.push_back(connectWireExtract());
        } else {
            throw CommandNotFound();
        }
    }

    newModuleInfo.numOfInputs = numOfInputs;
    newModuleInfo.moduleType = moduleName;

    circuit->createModule(newModuleInfo);
}

pair<pair<string, string>, vector<int>> InputHandler::addModules_GatesExtract() {
    string gateType_moduleName;
    string gate_moduleID;

    command_line >> gateType_moduleName;
    command_line >> gate_moduleID;

    vector<int> inputsWires_name;
    string wireName;

    while (command_line >> wireName) {
        if (wireName == END_OF_WIERES) {
            break;
        }
        inputsWires_name.push_back(stoi(wireName));
    }

    return make_pair(make_pair(gateType_moduleName, gate_moduleID), inputsWires_name);
}
