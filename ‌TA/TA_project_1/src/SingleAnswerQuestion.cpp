#include "../include/SingleAnswerQuestion.h"
#include <iostream>

SingleAnswerQuestion::SingleAnswerQuestion(const string &text, const vector<string> &choices, int correctAnswer, int number)
    : Question(SINGLE_ANSWER_TYPE_QUESTION, text, number), choices(choices), correctAnswer(correctAnswer) {}

void SingleAnswerQuestion::display() const
{
    cout << questionText << endl;
    for (size_t i = 0; i < choices.size(); ++i)
    {
        cout << i + 1 << ". " << choices[i] << endl;
    }
}

bool SingleAnswerQuestion::validateAnswer(const string &userAnswer)
{
    int userChoice = stoi(userAnswer);
    this->userAnswer = *new string(userAnswer);

    if (userChoice == correctAnswer)
    {
        this->setQuestionState(Question_State::correct);
    }
    else
    {
        this->setQuestionState(Question_State::wrong);
    }

    return userChoice == correctAnswer;
}

const string &SingleAnswerQuestion::getQuestionAnswer() const
{
    string *s = new string(to_string(this->correctAnswer));
    return *s;
}