#ifndef QUESTION_H
#define QUESTION_H

#include "../include/constant.h"
#include <string>
using namespace std;

class Question
{
public:
    Question(const string &type, const string &text, int number);
    virtual ~Question() = default;
    virtual void display() const = 0;
    virtual bool validateAnswer(const string &userAnswer) = 0;

    Question_State getQuestionState() const;
    void setQuestionState(Question_State state);
    int getQuestionNumber() const;
    const string &getQuestionText() const;
    void setQuestionText(const string &questionText);
    const string &getUserAnswer() const;
    virtual const string &getQuestionAnswer() const = 0;

protected:
    string questionType;
    string questionText;
    int questionNumber;
    Question_State questionState = Question_State::no_answer;
    string userAnswer = "";

    



    


    





};

#endif
