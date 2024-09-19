#ifndef QUIZHANDLER_H
#define QUIZHANDLER_H

#include "Question.h"
#include <vector>
#include <fstream>
#include "constant.h"
#include "MultipleAnswerQuestion.h"
#include "ShortAnswerQuestion.h"
#include "SingleAnswerQuestion.h"
#include <sstream>
#include <memory>

using namespace std;

class QuestionManager
{
public:
    QuestionManager(const string &filePath);
    ~QuestionManager();

    void startQuiz();
    void reportResults() const;
    bool isAllquestionsAnswered() const;
    void runQuiz();

private:
    vector<shared_ptr<Question>> questions;
    stringstream command_line;
    bool isQuizRunning = true;
    int correctAnswers;

    shared_ptr<Question> processSingleAnswerQuestion(ifstream &file, int questionNumber);
    shared_ptr<Question> processMultipleAnswerQuestion(ifstream &file, int questionNumber);
    shared_ptr<Question> processShortAnswerQuestion(ifstream &file, int questionNumber);

    void reportQuestion() const;
};

#endif
