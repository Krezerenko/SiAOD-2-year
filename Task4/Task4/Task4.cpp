#include <iostream>
#include <Windows.h>
#include <bitset>
#include <vector>

using namespace std;

void PrintFirstExample(unsigned int x, unsigned int mask, unsigned int shift = 4);
unsigned int InputNumbers(vector<unsigned char>& list, unsigned int amount);
void OutputNumbers(vector<unsigned char>& list);

int main()
{
    //auto set = ~bitset<65>(0);
    //cout << set.to_ullong() << "\n";

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Задание 1.а.\n";

    unsigned int inputAmount;
    unsigned int x = 255;
    unsigned int mask = 1;

    PrintFirstExample(x, mask);

    cout << "Введите количество вводов x: ";
    cin >> inputAmount;

    for (unsigned int i = 0; i < inputAmount; i++)
    {
        cout << "Введите x: ";
        cin >> x;
        PrintFirstExample(x, mask);
    }

    cout << "\nЗадание 1.б.\n";

    unsigned int shift = 7;
    PrintFirstExample(x, mask, shift);

    cout << "\nЗадание 1.в\n";

    const int n = sizeof(int) * 8;
    x = 25;
    mask = 1 << (n - 1);
    cout << "Начальная маска: " << mask << " = " << bitset<n>(mask) <<"\n";
    cout << "Результат: ";

    for (unsigned int i = 1; i <= n; i++)
    {
        cout << ((x & mask) >> (n - i));
        mask >>= 1;
    }
    cout << "\n";


    vector<unsigned char> nums;

    cout << "\nЗадание 2.а\n";
    cout << "Введите количество чисел:\n";
    do
    {
        cin >> inputAmount;
        if (inputAmount > 64)
        {
            cout << "Введите число меньшее 64.\n";
        }
    } while (inputAmount > 64);
    
    unsigned int maxNum = InputNumbers(nums, inputAmount);
    OutputNumbers(nums);

    unsigned char charContainer;
    unsigned short int shortContainer;
    unsigned int longContainer;
    unsigned long long int longLongContainer;
    if (inputAmount <= 8 && maxNum <= 7)
    {
        charContainer = 0;
    }

    cout << "\nЗадание 2.б\n";

    cout << "\nЗадание 2.в\n";

}

void PrintFirstExample(unsigned int x, unsigned int mask, unsigned int shift)
{
    cout << "Начальное значение x: " << x << "\n";
    cout << "Начальная маска: " << mask << "\n";
    cout << "Сдвиг маски влево на " << shift << " битов\n";

    x = x & (~(mask << shift));
    cout << "x = " << x << "\n";
}

unsigned int InputNumbers(vector<unsigned char>& list, unsigned int amount)
{
    list = vector<unsigned char>();
    unsigned int maxNum;
    for (unsigned int i = 0; i < amount; i++)
    {
        unsigned int inp;
        if (inp > maxNum)
            maxNum = inp;
        cin >> inp;
        list.push_back((unsigned char)inp);
    }
    return maxNum;
}

void OutputNumbers(vector<unsigned char>& list)
{
    for (unsigned char num : list)
    {
        cout << (unsigned int)num << " ";
    }
    cout << "\n";
}
