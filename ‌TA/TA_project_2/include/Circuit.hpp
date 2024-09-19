//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_CIRCUIT_HPP
#define TA_PROJECT_2_CIRCUIT_HPP

#include "Module.hpp"
#include "Constant.hpp"


class Circuit : public Module {
public:
    Circuit() ;
    ~Circuit() ;

    void createModule(New_Module_Info moduleInfo);
    void set_other_inputs(string wireIDs, LogicValue value);
    LogicValue UpdateState(vector<string> outputGM);

private:
    vector<pair<string, LogicValue>> other_inputs;
};

#endif //TA_PROJECT_2_CIRCUIT_HPP
