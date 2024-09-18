#include "Global.h"
#include <iostream>
#include <fstream>

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

void GenerateRandomKeys(const unsigned int maxAmount, const unsigned int keysAmount, vector<unsigned int>& buffer)
{
    buffer.clear();
    vector<bool> keyTable(maxAmount, false);
    for (unsigned int i = 0; i < keysAmount; i++)
    {
        unsigned int r = rand() % maxAmount;
        int k = 0;
        while (keyTable[(r + k) % maxAmount])
        {
            k *= -1;
            if (!keyTable[(r + k) % maxAmount])
            {
                break;
            }
            k *= -1;
            k++;
        }
        buffer.push_back((r + k) % maxAmount);
    }
}

void DisplayTimeDuration(std::chrono::steady_clock::duration duration)
{
    auto time = chrono::duration_cast<chrono::nanoseconds>(duration);
    string timeUnit = "наносекунд";
    long double convertedTime = time.count();
    if (convertedTime >= 1000)
    {
        convertedTime /= 1000;
        timeUnit = "микросекунд";
        if (convertedTime >= 1000)
        {
            convertedTime /= 1000;
            timeUnit = "милисекунд";
            if (convertedTime >= 1000)
            {
                convertedTime /= 1000;
                timeUnit = "секунд";
            }
        }
    }
    cout << "«атраченное врем€: " << convertedTime << ' ' << timeUnit << ".\n";
}
