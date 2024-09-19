//
// Created by tahamajs on 8/16/24.
//

#include "../include/Circuit.hpp"

Circuit::Circuit() : Module(0){
    //
}

Circuit::~Circuit() {
    //
}

void Circuit::createModule(New_Module_Info moduleInfo) {
    if (Module::isModuleExist(moduleInfo.moduleType)) {
        throw DuplicateModule();
    }

    auto newModule = make_shared<Module>(moduleInfo.numOfInputs);

    for (const auto& gateInfo : moduleInfo.gates_modules) {
        const auto& wireNumbers = gateInfo.second;
        const auto& type_name = gateInfo.first;

        newModule->addGate_Module(wireNumbers, type_name.second, type_name.first);
    }

    for (const auto& connection : moduleInfo.connections) {
        newModule->addConnection(connection);
    }

    Module::registerModule(newModule, moduleInfo.moduleType);
}

void Circuit::set_other_inputs(string wireIDs, LogicValue value) {
    other_inputs.push_back(make_pair(wireIDs, value));
}

LogicValue Circuit::UpdateState( vector<string> outputGM){
    vector<string> next_get_outputGM;
    if (outputGM.size() > 1) {
        next_get_outputGM.assign(outputGM.begin() + 1, outputGM.end());
    } else if (outputGM.size() == 1) {
        if (!isInMG(outputGM[0])) {
            throw InvalidID();
        }
    }

//    wires->showAllWireValues();

    wires->updateWireValues(other_inputs);
//    wires->showAllWireValues();

    wires->makeNoCWireValid();
//    wires->showAllWireValues();


    for (int i = 0; i < modules.size() + gates.size(); i++) {
        for (auto& module : modules) {
            if (wires->isMoudle_GateReadyValid(module.second)) {
                if (outputGM.size() == 1 && module.second == outputGM[0]) {
                    return module.first->UpdateState(wires->getMGInputValues(module.second), next_get_outputGM);
                }
                wires->updateWireValue(wires->getOutputWire(module.second), module.first->UpdateState(wires->getMGInputValues(module.second), next_get_outputGM));
//                wires->showAllWireValues();

            }
        }
        for (auto& gate : gates) {
            if (wires->isMoudle_GateReadyValid(gate.second)) {
                if (outputGM.size() == 1 && gate.second == outputGM[0]) {
                    return gate.first->compute(wires->getMGInputValues(gate.second));
                }
                wires->updateWireValue(wires->getOutputWire(gate.second), gate.first->compute(wires->getMGInputValues(gate.second)));
            }
        }
    }


    return wires->getWireValue(OUT_WIRE);


}