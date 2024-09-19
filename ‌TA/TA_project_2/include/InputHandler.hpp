//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_INPUTHANDLER_HPP
#define TA_PROJECT_2_INPUTHANDLER_HPP

#include "Constant.hpp"
#include "Circuit.hpp"
#include "Exceptions.hpp"
#include "Utils.hpp"
#include <unordered_map>



const string REQUERST_CONNECT_WIRE = "connect";
const string REQUERST_SET_VALUE = "put";
const string REQUERST_SHOW_VALUE = "print" ;
const string REQUERST_ADD_MODULES_GATES = "add";
const string REQUERST_NEW_MODULE = "new_module";
const string REQUERST_END_MODULE = "end_module";
//const char DELIMITER = '.';



const string BadExeption = "Bad Command ????";
const string END_OF_WIERES = "end";




class InputHandler {
public:
    InputHandler();
    ~InputHandler();

    void run();

private:

    void setValue();
    string changeLogicValueToString(LogicValue logicValue);
    void showValue();
    pair<pair<string,string>,vector<int>> addModules_GatesExtract();
    void addModules_Gates();
    pair<string, string> connectWireExtract();
    void connectWire();
    void newModule();
    void handle_command();



    typedef void (InputHandler::*call_func_ptr)();
    const unordered_map<string, int> gateMap = {
            {"and",  1},
            {"or",   2},
            {"not",  3},
            {"nand", 4},
            {"nor",  5},
            {"xor",  6},
    };

    const unordered_map<string, call_func_ptr> commandMap = {
            {REQUERST_CONNECT_WIRE, &InputHandler::connectWire},
            {REQUERST_SET_VALUE, &InputHandler::setValue},
            {REQUERST_SHOW_VALUE, &InputHandler::showValue},
            {REQUERST_ADD_MODULES_GATES, &InputHandler::addModules_Gates},
            {REQUERST_NEW_MODULE, &InputHandler::newModule},
    };




    Circuit* circuit;
    stringstream command_line;




};


#endif //TA_PROJECT_2_INPUTHANDLER_HPP
