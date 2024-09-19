cmake_minimum_required(VERSION 3.28)
project(TA_project_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(TA_project_2 src/main.cpp
        include/Exceptions.hpp
        include/Exceptions.hpp
        src/GateNand.cpp
        include/Constant.hpp
        include/GateAnd.hpp
        src/Utils.cpp
        src/Module.cpp
        src/GateXor.cpp
        src/GateOr.cpp
        src/GateNot.cpp
        src/GateNor.cpp
        src/GateAnd.cpp
        src/Gate.cpp
        src/Exceptions.cpp
        include/InputHandler.hpp
        include/Gate.hpp
        include/Circuit.hpp
        src/Circuit.cpp
        src/InputHandler.cpp
        include/Utils.hpp
        include/Wire.hpp
        src/Wire.cpp)
