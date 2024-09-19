#include "../include/Exceptions.h"

const char *DOUBLE_ANSWER_EXPLANATION_TEXT = "The answer is double.";
const char *OUT_OF_RANGE_EXPLANATION_TEXT = "The answer is out of range.";
const char *INVALID_INPUT_EXPLANATION_TEXT = "The input is invalid.";

const char *DoubleAnswerException::what() const noexcept
{
    return DOUBLE_ANSWER_EXPLANATION_TEXT;
}

const char *OutOfRangeException::what() const noexcept
{
    return OUT_OF_RANGE_EXPLANATION_TEXT;
}

const char *InvalidInputException::what() const noexcept
{
    return INVALID_INPUT_EXPLANATION_TEXT;
}
