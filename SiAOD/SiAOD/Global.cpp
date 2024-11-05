#include "Global.h"
#include <iostream>
#include <fstream>
#include <locale>

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
                cout << "Введите число не более " << maxNum - 1 << ".\n";
        } while (inp >= maxNum);

        list.push_back(static_cast<unsigned char>(inp));
    }
}

void OutputNumbers(const vector<unsigned char>& list)
{
    for (unsigned char num : list)
    {
        cout << static_cast<unsigned int>(num) << " ";
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
        keyTable[(r + k) % maxAmount] = true;
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
    cout << "Затраченное время: " << convertedTime << ' ' << timeUnit << ".\n";
}

bool IsPrime(unsigned int n)
{
    if (n <= 1) return false;
    for (int i = 2; i < sqrt(n) + 1; ++i)
    {
        if (n % i == 0) return false;
    }
    return true;
}

unsigned int GetNextPrime(unsigned int n)
{
    if (IsPrime(n)) return n;
    while (!IsPrime(++n))
    {
    }
    return n;
}

unsigned long long PowI(unsigned long long a, unsigned long long p)
{
    unsigned long long pow = 1;
    for (unsigned long long i = 0; i < p; ++i)
    {
        pow *= a;
    }
    return pow;
}

std::string ToLowercase(const std::string &a)
{
    std::string out;
    out.reserve(a.length());
    for (const char &c : a)
    {
        if (c >= 'A' && c <= 'Z')
        {
            out.push_back(c + 'a' - 'A');
            continue;
        }
        if (c >= 'А' && c <= 'Я')
        {
            out.push_back(c + 'а' - 'А');
            continue;
        }
        out.push_back(c);
    }
    return out;
}

int CompareStrings(const std::string& a, const std::string& b)
{
    std::string lowercaseA = ToLowercase(a);
    std::string lowercaseB = ToLowercase(b);
    return strcmp(lowercaseA.c_str(), lowercaseB.c_str());
}

std::string SpaceAround(const unsigned int space, const std::string& str)
{
    unsigned int len = str.length();
    unsigned int leftSpace = (space - len) / 2;
    unsigned int rightSpace = space - leftSpace - len;
    std::string out = std::string(leftSpace + rightSpace, ' ');
    out.insert(leftSpace, str);
    return out;
}
