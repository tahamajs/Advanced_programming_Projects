//
// Created by tahamajs on 8/16/24.
//

#include "../include/Exceptions.hpp"

const char* DuplicateID::what() const noexcept {
    return "duplicate ID";
}

const char* InvalidConnection::what() const noexcept {
    return "invalid connection";
}

const char* IDNotFound::what() const noexcept {
    return "ID not found";
}

const char* InvalidValue::what() const noexcept {
    return "invalid value";
}

const char* GateNotFound::what() const noexcept {
    return "gate not found";
}

const char* ModuleNotFound::what() const noexcept {
    return "module not found";
}

const char* DuplicateModule::what() const noexcept {
    return "this module already exists";
}

const char* CommandNotFound::what() const noexcept {
    return "command not found";
}

const char* BadCommand::what() const noexcept {
    return "bad command";
}

const char* WireConnected::what() const noexcept {
    return "wire is connected";
}

const char* InvalidInput::what() const noexcept {
    return "invalid input";
}


const char* InvalidID::what() const noexcept {
    return "invalid input";
}


