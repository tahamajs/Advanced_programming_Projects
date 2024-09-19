#ifndef SHORTANSWERQUESTION_H
#define SHORTANSWERQUESTION_H

#include "Question.h"
using namespace std;

class ShortAnswerQuestion : public Question
{
public:
    ShortAnswerQuestion(const string &text, const string &correctAnswer, int number);
    void display() const;
    bool validateAnswer(const string &userAnswer);
    const string &getQuestionAnswer() const;

private:
    string correctAnswer;
};

#endif
