#include <iostream>
using namespace std;

void change_to_lower(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str [i] = str[i] - 'A' + 'a';
        }
    }
}

void symbols(string &str)
{
    string result;
    for (int i = 0; i < str.size(); i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z' ) || (str[i] >= 'a' && str[i] <= 'z'))
        {
            result = result + str[i];
        }
    }
    str = result;
}

bool check_palindrome(string str)
{
    int s = 0;
    int e = str.size() - 1;
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int main()
{
    string str;
    cout << "enter string: ";
    getline(cin, str);
    change_to_lower(str);
    symbols(str);
    cout << check_palindrome(str);
    return 0;
}