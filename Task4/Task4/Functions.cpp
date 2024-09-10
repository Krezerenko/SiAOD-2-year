#include "Functions.h"
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