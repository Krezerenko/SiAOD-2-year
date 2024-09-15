#include "Global.h"
#include <iostream>

using namespace std;

void InputNumbers(vector<unsigned char>& list, unsigned int amount, unsigned int maxNum)
{
    list = vector<unsigned char>();
    for (unsigned int i = 0; i < amount; i++)
    {
        unsigned int inp;
        do
        {
            cin >> inp;
            if (inp >= maxNum)
                cout << "¬ведите число не более " << maxNum - 1 << ".\n";
        } while (inp >= maxNum);

        list.push_back((unsigned char)inp);
    }
}

void OutputNumbers(vector<unsigned char>& list)
{
    for (unsigned char num : list)
    {
        cout << (unsigned int)num << " ";
    }
    cout << "\n";
}

void Split(const std::string& text, const string& delimiter, vector<string>& tokens)
{
    tokens.clear();
    string s = text;
    size_t pos = 0;
    while ((pos = s.find(delimiter)) != string::npos) 
    {
        string token = s.substr(0, pos);
        tokens.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    tokens.push_back(s);
}