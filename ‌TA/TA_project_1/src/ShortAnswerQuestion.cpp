#include "../include/ShortAnswerQuestion.h"
#include <iostream>

ShortAnswerQuestion::ShortAnswerQuestion(const string &text, const string &correctAnswer, int number)
    : Question(SHORT_ANSWER_TYPE_QUESTION, text, number), correctAnswer(correctAnswer) {}

void ShortAnswerQuestion::display() const
{
    cout << questionText << endl;
}

bool ShortAnswerQuestion::validateAnswer(const string &userAnswer)
{
    this->userAnswer = *new string(userAnswer);
    if (userAnswer == correctAnswer)
    {
        this->setQuestionState(Question_State::correct);
    }
    else
    {
        this->setQuestionState(Question_State::wrong);
    }
    return userAnswer == correctAnswer;
}

const string &ShortAnswerQuestion::getQuestionAnswer() const
{
    return correctAnswer;
}