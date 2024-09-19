#include "../include/MultipleAnswerQuestion.h"
#include <iostream>
#include <algorithm>

MultipleAnswerQuestion::MultipleAnswerQuestion(const string &text, const vector<string> &choices, const vector<int> &correctAnswers, int number)
    : Question(MULTIPLE_ANSWER_TYPE_QUESTION, text, number), choices(choices), correctAnswers(correctAnswers) {}

void MultipleAnswerQuestion::display() const
{
    cout << questionText << endl;
    for (size_t i = 0; i < choices.size(); ++i)
    {
        cout << i + 1 << ". " << choices[i] << endl;
    }
}

bool MultipleAnswerQuestion::validateAnswer(const string &userAnswer)
{
    set<int> userChoices;

    this->userAnswer = *new string(userAnswer);

    string temp;
    for (size_t i = 0; i < userAnswer.size(); ++i)
    {
        if (userAnswer[i] == ' ')
        {
            userChoices.insert(stoi(temp));
            temp = "";
        }
        else
        {
            temp += userAnswer[i];
        }
    }

    if (!temp.empty())
    {
        userChoices.insert(stoi(temp));
    }

    vector<int> sortedCorrectAnswers = correctAnswers;
    vector<int> userChoicesVector(userChoices.begin(), userChoices.end());

    sort(sortedCorrectAnswers.begin(), sortedCorrectAnswers.end());
    if (userChoicesVector == sortedCorrectAnswers)
    {
        this->setQuestionState(Question_State::correct);
    }
    else
    {
        this->setQuestionState(Question_State::wrong);
    }
    return userChoicesVector == sortedCorrectAnswers;
}

MultipleAnswerQuestion &MultipleAnswerQuestion::operator=(const MultipleAnswerQuestion &other)
{
    if (this != &other)
    {
        Question::operator=(other);
        choices = other.choices;
        correctAnswers = other.correctAnswers;
    }
    return *this;
}

const string &MultipleAnswerQuestion::getQuestionAnswer() const
{
    string *temp = new string();
    for (size_t i = 0; i < correctAnswers.size(); ++i)
    {
        *temp += to_string(correctAnswers[i]) + " ";
    }
    return *temp;
}