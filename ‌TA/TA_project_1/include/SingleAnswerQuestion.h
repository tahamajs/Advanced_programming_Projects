#ifndef SINGLEANSWERQUESTION_H
#define SINGLEANSWERQUESTION_H

#include "Question.h"
#include <vector>

class SingleAnswerQuestion : public Question
{
public:
    SingleAnswerQuestion(const string &text, const vector<string> &choices, int correctAnswer, int number);
    void display() const;
    bool validateAnswer(const string &userAnswer);
    const string &getQuestionAnswer() const;

private:
    vector<string> choices;
    int correctAnswer;
};

#endif
