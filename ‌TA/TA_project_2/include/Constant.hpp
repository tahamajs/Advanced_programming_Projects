//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_CONSTANT_HPP
#define TA_PROJECT_2_CONSTANT_HPP
# include <string>
# include <vector>
# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <algorithm>
#include <memory>

#include<string>
#include "Exceptions.hpp"
#include <algorithm>




using namespace std;

const string SELF_MODULE = "SELF_MODULE" ;
const char DELIMITER = '.';
const string OUT_WIRE = "out";

const string LogicValueZero = "0";
const string LogicValueOne = "1";
const string LogicValueZ = "Z";

const string AND_GATE = "and";
const string OR_GATE = "or";
const string XOR_GATE = "xor";
const string NAND_GATE = "nand";
const string NOR_GATE = "nor";
const string NOT_GATE = "not";

const string AND_GATE_UPPER = "AND";
const string OR_GATE_UPPER = "OR";
const string XOR_GATE_UPPER = "XOR";
const string NAND_GATE_UPPER = "NAND";
const string NOR_GATE_UPPER = "NOR";
const string NOT_GATE_UPPER = "NOT";


enum LogicValue {
    ZERO = 0,
    ONE = 1,
    Z = 2
};

enum TypeElement {
    GATE = 0,
    MODULE = 1,
};

enum GateType {
    AND = 0,
    OR = 1,
    NOT = 2,
    XOR = 3,
    NAND = 4,
    NOR = 5,
    XNOR = 6,
};



struct WireStructure {
    string wireId;
    string elementId;
    LogicValue value;
    int inputIndex;
    bool isOutput;
    bool isModule;
    bool isValid = false;
};



struct New_Module_Info {
    int numOfInputs;
    string moduleType;
    vector <pair<pair<string ,string > , vector <int>>> gates_modules;
    vector<pair<string, string>> connections;
};


struct Connection {
    string inWire;
    string outWire;

};



#endif //TA_PROJECT_2_CONSTANT_HPP
