#include "../include/QuestionManager.h"
#include <iostream>

int main(int argc, char *argv[])
{

    const string filePath = argv[1];

    if (argc != 2)
    {
        cerr << "Usage: " << argv[0] << " <file_path>" << std::endl;
        return EXIT_FAILURE;
    }

    QuestionManager questionManager(filePath);
    questionManager.runQuiz();

    return EXIT_SUCCESS;
}
