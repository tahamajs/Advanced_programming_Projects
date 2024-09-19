cmake_minimum_required(VERSION 3.27)
project(TA_project)


include_directories(include)
set(CMAKE_CXX_STANDARD 17)

add_executable(TA_project main.cpp)


# Add the include directory
#include_directories(include)

# Define the source files
set(SOURCE_FILES src/main.cpp
        include/Question.h
        src/Question.cpp
        include/SingleAnswerQuestion.h
        src/SingleAnswerQuestion.cpp
        src/MultipleAnswerQuestion.cpp
        include/MultipleAnswerQuestion.h
        src/ShortAnswerQuestion.cpp
        include/ShortAnswerQuestion.h
        include/constant.h
        src/QuestionManager.cpp
        src/Exceptions.cpp
        include/Exceptions.h)

# Create an executable and set the output directory to 'bin'
add_executable(MyExecutable ${SOURCE_FILES})
set_target_properties(MyExecutable PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)


