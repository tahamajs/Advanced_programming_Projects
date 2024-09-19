#ifndef TA_PROJECT_EXCEPTIONS_H
#define TA_PROJECT_EXCEPTIONS_H

#include <exception>
#include "../include/constant.h"

extern const char *DOUBLE_ANSWER_EXPLANATION_TEXT;
extern const char *OUT_OF_RANGE_EXPLANATION_TEXT;
extern const char *INVALID_INPUT_EXPLANATION_TEXT;

using namespace std;

class DoubleAnswerException : public exception
{
public:
    const char *what() const noexcept override;
};

class OutOfRangeException : public exception
{
public:
    const char *what() const noexcept override;
};

class InvalidInputException : public exception
{
public:
    const char *what() const noexcept override;
};

#endif
