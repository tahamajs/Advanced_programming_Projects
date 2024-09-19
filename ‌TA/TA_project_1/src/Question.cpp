#include "../include/Question.h"

Question::Question(const string &type, const string &text, int number)
    : questionType(type), questionText(text), questionNumber(number) {}

const string &Question::getQuestionText() const
{
    return questionText;
}

Question_State Question::getQuestionState() const
{
    return questionState;
}

void Question::setQuestionState(Question_State state)
{
    questionState = state;
}

int Question::getQuestionNumber() const
{
    return questionNumber;
}

void Question::setQuestionText(const string &questionText)
{
    Question::questionText = questionText;
}

const string &Question::getUserAnswer() const
{
    return userAnswer;
}
