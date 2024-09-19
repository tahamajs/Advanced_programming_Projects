#ifndef TA_PROJECT_CONSTANT_H
#define TA_PROJECT_CONSTANT_H

#include <string>
using namespace std;
const string FILE_PATH = "./Inputs/input.txt";
const string ANSWER_TYPE = "submit_answer";
const string FINISH_TYPE = "finish_exam";

const string SINGLE_ANSWER_TYPE_QUESTION = "single_answer";
const string MULTIPLE_ANSWER_TYPE_QUESTION = "multiple_answer";
const string SHORT_ANSWER_TYPE_QUESTION = "short_answer";

const string FINAL_GRADE_TEXT = "Final grade: ";

const string INVELID_QUESTION_TYPE = "Invalid question type in file.";
const string UNABLE_TO_OPEN_FILE = "Error: Unable to open file.";

const string CORRECT_ANSWER = " correct";
const string WRONG_ANSWER = " wrong | correct answer: ";
const string NO_ANSWER = " no answer | correct answer: ";
const string ANSWER = "Your answer: ";

const string QUESTION_CORRECT_TEXT = "correct answer.";
const string QUESTION_WRONG_TEXT = "wrong answer.";

enum Question_State
{
    correct,
    wrong,
    no_answer
};

#endif
