#include <iostream>
#include <ctype.h>

using namespace std;

string to_upper(string &str, int cnt = -10)
{
    if (cnt == -10)
    {
        cnt = str.size() - 1;
    }

    if (cnt == -1)
    {
        return str;
    }

    if (str[cnt] >= 97 && str[cnt] <= 122)
    {
        if (!(str[cnt] >= 'A' && str[cnt] <= 'Z'))
        {
            str[cnt] -= 32;
        }
    }

    return to_upper(str, cnt - 1);
}


int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << to_upper(line) << endl;
    }
    return 0;
}