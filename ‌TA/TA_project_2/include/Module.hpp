//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_MODULE_HPP
#define TA_PROJECT_2_MODULE_HPP

#include "Constant.hpp"
#include "Gate.hpp"
#include "GateAnd.hpp"
#include "GateNot.hpp"
#include "GateOr.hpp"
#include "GateXor.hpp"
#include "GateNand.hpp"
#include "GateNor.hpp"
#include "Wire.hpp"


class Module {
public:


    Module(int numOfInputs);
    ~Module();

    void addGate(vector<int> wiereNumbers, string gateId, GateType gateType);
    void addModule( vector<int> wiereNumbers ,string moduleId, string moduleType);

    void addConnection(pair<string , string> connection);

    LogicValue UpdateState(vector<LogicValue> inputs, vector<string> outputs);

    static vector<pair<shared_ptr<Module>, string>>& getAllModules(){return allModules ;};

    static vector<pair<shared_ptr<Module>, string>> allModules;

    static void registerModule(shared_ptr<Module> module, string moduleType);

    static bool isModuleExist(const string& moduleId) ;

    void addGate_Module(vector<int> wireNumbers, string gateId , string gateType);




protected:

    vector<LogicValue> inputs;
    LogicValue output = LogicValue::Z;
    vector<pair<shared_ptr<Gate>, string >> gates;
    vector<pair<shared_ptr<Module>, string >> modules;
    shared_ptr<Wire> wires;


    bool isInMG(string id);
    shared_ptr<Gate> createGate(GateType gateType, int numOfInputs) ;



};


#endif //TA_PROJECT_2_MODULE_HPP
