//
// Created by tahamajs on 8/16/24.
//

#ifndef TA_PROJECT_2_EXCEPTIONS_HPP
#define TA_PROJECT_2_EXCEPTIONS_HPP
#include <exception>
#include "Constant.hpp"


using namespace std;


class DuplicateID : public exception {
public:
    const char * what() const noexcept override ;
};


class InvalidConnection : public exception {
public:
    const char * what() const noexcept override ;
};

class IDNotFound : public exception {
public:
    const char * what() const noexcept override ;
};

class InvalidValue : public exception {
public:
    const char * what() const noexcept override ;
};

class GateNotFound : public exception {
public:
    const char * what() const noexcept override ;
};

class ModuleNotFound : public exception {
public:
    const char * what() const noexcept override ;
};

class DuplicateModule : public exception {
public:
    const char * what() const noexcept override ;
};

class CommandNotFound : public exception {
public:
    const char * what() const noexcept override ;
};

class BadCommand : public exception {
public:
    const char * what() const noexcept override ;
};

class WireConnected : public exception {
public:
    const char * what() const noexcept override ;
};

class InvalidInput : public exception {
public:
    const char * what() const noexcept override ;
};

class InvalidID : public exception {
public:
    const char * what() const noexcept override ;
};

#endif //TA_PROJECT_2_EXCEPTIONS_HPP
