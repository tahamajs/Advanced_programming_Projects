#include <iostream>
#include "../include/InputHandler.hpp"

using namespace std;


int main()
{
    InputHandler input;
    string line;

    while (getline(cin, line))
    {
        input.update(line);
    }
}