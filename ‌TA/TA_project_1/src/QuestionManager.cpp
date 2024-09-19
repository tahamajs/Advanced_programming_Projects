#include "../include/QuestionManager.h"
#include <iostream>

QuestionManager::QuestionManager(const string &filePath) : correctAnswers(0)
{
    ifstream file(filePath);
    int questionNumber = 1;

    if (!file.is_open())
    {
        cerr << UNABLE_TO_OPEN_FILE << endl;
        exit(EXIT_FAILURE);
    }

    string questionType;
    string tmp;

    while (file >> questionType)
    {
        if (questionType == SINGLE_ANSWER_TYPE_QUESTION)
        {
            questions.push_back(processSingleAnswerQuestion(file, questionNumber));
        }
        else if (questionType == MULTIPLE_ANSWER_TYPE_QUESTION)
        {
            questions.push_back(processMultipleAnswerQuestion(file, questionNumber));
        }
        else if (questionType == SHORT_ANSWER_TYPE_QUESTION)
        {
            questions.push_back(processShortAnswerQuestion(file, questionNumber));
        }
        else
        {
            cerr << INVELID_QUESTION_TYPE << endl;
            exit(EXIT_FAILURE);
        }
        questionNumber++;
        file >> tmp;
    }

    file.close();
}

QuestionManager::~QuestionManager()
{
    // nothing to do here we have smart pointers
    questions.clear();
}

shared_ptr<Question> QuestionManager::processSingleAnswerQuestion(ifstream &file, int questionNumber)
{
    string questionText;
    int choicesCount;
    vector<string> choices;
    int correctAnswer;

    getline(file >> ws, questionText);
    file >> choicesCount;
    choices.resize(choicesCount);
    for (int i = 0; i < choicesCount; ++i)
    {
        getline(file >> ws, choices[i]);
    }
    file >> correctAnswer;

    return make_shared<SingleAnswerQuestion>(questionText, choices, correctAnswer, questionNumber);
}
void QuestionManager::reportResults() const
{
    reportQuestion();
    cout << FINAL_GRADE_TEXT;
    printf("%.1f", (float)correctAnswers / questions.size() * 100);
    cout << endl;
}

shared_ptr<Question> QuestionManager::processMultipleAnswerQuestion(ifstream &file, int questionNumber)
{
    string questionText;
    int choicesCount;
    vector<string> choices;
    vector<int> correctAnswers;

    getline(file >> ws, questionText);
    file >> choicesCount;
    choices.resize(choicesCount);
    for (int i = 0; i < choicesCount; ++i)
    {
        getline(file >> ws, choices[i]);
    }

    string correctAnswers_String;
    getline(file >> ws, correctAnswers_String);

    string temp;
    for (size_t i = 0; i < correctAnswers_String.size(); ++i)
    {
        if (correctAnswers_String[i] == ' ')
        {
            correctAnswers.push_back(stoi(temp));
            temp = "";
        }
        else
        {
            temp += correctAnswers_String[i];
        }
    }
    correctAnswers.push_back(stoi(temp));

    return make_shared<MultipleAnswerQuestion>(questionText, choices, correctAnswers, questionNumber);
}

shared_ptr<Question> QuestionManager::processShortAnswerQuestion(ifstream &file, int questionNumber)
{
    string questionText;
    string correctAnswer;

    getline(file >> ws, questionText);
    getline(file >> ws, correctAnswer);

    return make_shared<ShortAnswerQuestion>(questionText, correctAnswer, questionNumber);
}

void QuestionManager::reportQuestion() const
{
    for (size_t i = 0; i < questions.size(); ++i)
    {
        if (questions[i]->getQuestionState() == Question_State::correct)
        {
            cout << i + 1 << CORRECT_ANSWER << endl;
        }
        else if (questions[i]->getQuestionState() == Question_State::wrong)
        {
            cout << i + 1 << WRONG_ANSWER << questions[i]->getQuestionAnswer() << endl;
            cout << ANSWER << questions[i]->getUserAnswer() << endl;
        }
        else
        {
            cout << i + 1 << NO_ANSWER << questions[i]->getQuestionAnswer() << endl;
        }
    }
}

void QuestionManager::startQuiz()
{
    int n = questions.size();

    int Question_num;

    string tmp_answare_result;
    command_line >> tmp_answare_result;
    if (tmp_answare_result == ANSWER_TYPE)
    {
        command_line >> Question_num;
        if (Question_num > n || Question_num < 1)
        {
            throw OutOfRangeException();
        }

        if (questions[Question_num - 1]->getQuestionState() != Question_State::no_answer)
        {
            throw DoubleAnswerException();
        }

        string tmp_answare;

        getline(command_line >> ws, tmp_answare);
        if (questions[Question_num - 1]->validateAnswer(tmp_answare))
        {
            correctAnswers++;
            cout << QUESTION_CORRECT_TEXT << endl;
        }
        else
        {
            cout << QUESTION_WRONG_TEXT << endl;
        }
    }
    else if (tmp_answare_result == FINISH_TYPE)
    {
        isQuizRunning = false;
    }
    else
    {
        throw InvalidInputException();
    }
}

bool QuestionManager::isAllquestionsAnswered() const
{
    for (auto &question : questions)
    {
        if (question->getQuestionState() == Question_State::no_answer)
        {
            return false;
        }
    }
    return true;
}

void QuestionManager::runQuiz()
{
    string command;
    string input_line;
    while (!isAllquestionsAnswered() && isQuizRunning)
    {
        getline(cin, input_line);
        try
        {
            command_line.clear();
            command_line.str(input_line);
            startQuiz();
        }
        catch (const InvalidInputException &e)
        {
            cerr << e.what() << endl;
        }
        catch (const OutOfRangeException &e)
        {
            cerr << e.what() << endl;
        }
        catch (const DoubleAnswerException &e)
        {
            cerr << e.what() << endl;
        }
        catch (const exception &e)
        {
            cerr << e.what() << endl;
        }
    }
    reportResults();
}