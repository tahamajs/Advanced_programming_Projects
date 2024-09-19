//
// Created by tahamajs on 8/16/24.
//

#include "../include/Module.hpp"
Module::Module(int numOfInputs){

    inputs.resize(numOfInputs);
    std::fill(inputs.begin(), inputs.end(), LogicValue::Z);
    output = LogicValue::Z;

    wires = make_shared<Wire>(numOfInputs);
    wires->setInputWires(numOfInputs);

}

Module::~Module() {
    //
}



LogicValue Module::UpdateState(vector<LogicValue> inputs, vector<string> outputs) {
    vector<string> next_gen_output;
    if (outputs.size() > 1) {
        for (int i = 1; i < outputs.size(); i++) {
            next_gen_output.push_back(outputs[i]);
        }
    }else if(outputs.size() == 1){
        if(!isInMG(outputs[0])){
            throw IDNotFound();
        }
    }

//    wires->showAllWireValues();

    wires->updateInputWires(inputs);
//    wires->showAllWireValues();

    wires->makeNoCWireValid();
//    wires->showAllWireValues();



    for(int i= 0 ; i < modules.size() + gates.size(); i++){
        for (auto& module : modules){

            if(wires->isMoudle_GateReadyValid(module.second)){

                if(outputs.size() == 1 ){
                    if (module.second == outputs[0])
                        return module.first->UpdateState(wires->getMGInputValues(module.second), next_gen_output);
                }
                wires->updateWireValue(wires->getOutputWire(module.second), module.first->UpdateState(wires->getMGInputValues(module.second), next_gen_output));
            }
        }

        for (auto& gate : gates){

            if(wires->isMoudle_GateReadyValid(gate.second)){
                if(outputs.size() == 1){

                    if (gate.second == outputs[0] )
                        return gate.first->compute(wires->getMGInputValues(gate.second));
                }
                wires->updateWireValue(wires->getOutputWire(gate.second), gate.first->compute(wires->getMGInputValues(gate.second)));
            }
        }




    }

    return wires->getWireValue(OUT_WIRE);

}






void Module::addConnection(pair<string , string> connection){

    wires->addConnection(make_shared<Connection>(Connection{connection.first, connection.second}));

}


shared_ptr<Gate> Module::createGate(GateType gateType, int numOfInputs) {

    switch (gateType) {
        case GateType::XOR:
            return make_shared<GateXor>(numOfInputs);
        case GateType::NOT:
            return make_shared<GateNot>(numOfInputs);
        case GateType::NAND:
            return make_shared<GateNand>(numOfInputs);
        case GateType::NOR:
            return make_shared<GateNor>(numOfInputs);
        case GateType::AND:
            return make_shared<GateAnd>(numOfInputs);
        case GateType::OR:
            return make_shared<GateOr>(numOfInputs);
        default:
            throw invalid_argument("Invalid gate type");
    }
}



void Module::addGate(vector<int> wiereNumbers, string gateId , GateType gateType){
    shared_ptr<Gate> gate = createGate(gateType, wiereNumbers.size()-1);
    gates.push_back(make_pair(gate, gateId));


    for (int i = 0; i < wiereNumbers.size()-1; i++) {
        wires->addWire(make_shared<WireStructure>(WireStructure{to_string(wiereNumbers[i]), gateId, LogicValue::Z, i, false, false}));
    }
    wires->addWire(make_shared<WireStructure>(WireStructure{to_string(wiereNumbers[wiereNumbers.size() - 1]), gateId, LogicValue::Z, 0, true, false}));

}


void Module::addModule( vector<int> wiereNumbers,string moduleId, string moduleType) {
    auto it = find_if(allModules.begin(), allModules.end(), [&moduleType](const pair<shared_ptr<Module>, string>& element) { return element.second == moduleType; });

    if (it != allModules.end()) {
        auto newModule = make_shared<Module>(*it->first); // Create a copy of the module
        modules.push_back(make_pair(newModule, moduleId));
    } else {
        throw ModuleNotFound();
    }

    for (int i = 0; i < wiereNumbers.size()-1; i++) {
        wires->addWire(make_shared<WireStructure>(WireStructure{to_string(wiereNumbers[i]), moduleId, LogicValue::Z, i, false, true}));
    }
    wires->addWire(make_shared<WireStructure>(WireStructure{to_string(wiereNumbers[wiereNumbers.size() - 1]), moduleId, LogicValue::Z, 0, true, true}));

}


std::vector<std::pair<std::shared_ptr<Module>, std::string>> Module::allModules;


void Module::registerModule(shared_ptr<Module> module, string moduleType) {

    allModules.push_back(make_pair(module, moduleType));

}

void Module::addGate_Module(vector<int> wireNumbers, string gateId , string gateType){
//    cout << "Adding gate/module with ID: " << gateId << " and type: " << gateType << endl;

    if (gateType == AND_GATE || gateType == AND_GATE_UPPER) {
//        cout << "Adding AND gate." << endl;
        addGate(wireNumbers, gateId, GateType::AND);
    } else if (gateType == OR_GATE || gateType == OR_GATE_UPPER) {
//        cout << "Adding OR gate." << endl;
        addGate(wireNumbers, gateId, GateType::OR);
    } else if (gateType == XOR_GATE || gateType == XOR_GATE_UPPER) {
//        cout << "Adding XOR gate." << endl;
        addGate(wireNumbers, gateId, GateType::XOR);
    } else if (gateType == NAND_GATE || gateType == NAND_GATE_UPPER) {
//        cout << "Adding NAND gate." << endl;
        addGate(wireNumbers, gateId, GateType::NAND);
    } else if (gateType == NOR_GATE || gateType == NOR_GATE_UPPER) {
//        cout << "Adding NOR gate." << endl;
        addGate(wireNumbers, gateId, GateType::NOR);
    } else if (gateType == NOT_GATE || gateType == NOT_GATE_UPPER) {
//        cout << "Adding NOT gate." << endl;
        addGate(wireNumbers, gateId, GateType::NOT);
    } else {
//        cout << "Adding module." << endl;
        addModule(wireNumbers, gateId, gateType);
    }
}


bool Module::isModuleExist(const string& moduleId) {
    auto it = std::find_if(allModules.begin(), allModules.end(),
                           [&moduleId](const std::pair<std::shared_ptr<Module>, std::string>& element) {
                               return element.second == moduleId;
                           });
    return it != allModules.end();
}


bool Module::isInMG(string id){
    for(auto gate : gates){
        if(gate.second == id){
            return true;
        }
    }
    for(auto module : modules){
        if(module.second == id){
            return true;
        }
    }
    return false;
}



