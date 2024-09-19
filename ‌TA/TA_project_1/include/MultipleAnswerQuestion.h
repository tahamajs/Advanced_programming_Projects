#ifndef MULTIPLEANSWERQUESTION_H
#define MULTIPLEANSWERQUESTION_H

#include "Question.h"
#include <vector>
#include "../include/Exceptions.h"
#include <set>

class MultipleAnswerQuestion : public Question
{
public:
    MultipleAnswerQuestion(const string &text, const vector<string> &choices, const vector<int> &correctAnswers, int number);
    MultipleAnswerQuestion &operator=(const MultipleAnswerQuestion &other);
    void display() const override;
    bool validateAnswer(const string &userAnswer) override;
    const string &getQuestionAnswer() const override;

private:
    vector<string> choices;
    vector<int> correctAnswers;
};

#endif
