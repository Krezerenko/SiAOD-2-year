#include <iostream>
#include <Windows.h>
#include <bitset>
#include <vector>

using namespace std;

void PrintFirstExample(unsigned int x, unsigned int mask, unsigned int shift = 4);
void InputNumbers(vector<unsigned char>& list, unsigned int amount, unsigned int maxNum);
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
    cout << "Введите количество чисел: ";
    do
    {
        cin >> inputAmount;
        if (inputAmount > 8)
        {
            cout << "Введите число меньшее 8.\n";
        }
    } while (inputAmount > 8);
    
    InputNumbers(nums, inputAmount, 8);
    cout << "Введенные числа: ";
    OutputNumbers(nums);

    unsigned char charContainer = 0;
    for (unsigned char num : nums)
    {
        charContainer |= 1 << (unsigned int)num;
    }
    nums.clear();
    for (unsigned char i = 0; i < sizeof(char) * 8; i++)
    {
        if (charContainer % 2)
        {
            nums.push_back(i);
        }
        charContainer >>= 1;
    }
    cout << "Отсортированные числа: ";
    OutputNumbers(nums);


    cout << "\nЗадание 2.б\n";
    nums.clear();
    cout << "Введите количество чисел: ";
    do
    {
        cin >> inputAmount;
        if (inputAmount > 64)
        {
            cout << "Введите число меньшее 64.\n";
        }
    } while (inputAmount > 64);

    InputNumbers(nums, inputAmount, 64);
    cout << "Введенные числа: ";
    OutputNumbers(nums);

    unsigned long long longContainer = 0;
    for (unsigned char num : nums)
    {
        longContainer |= 1 << (unsigned int)num;
    }
    nums.clear();
    for (unsigned int i = 0; i < sizeof(long long) * 8; i++)
    {
        if (longContainer % 2)
        {
            nums.push_back(i);
        }
        longContainer >>= 1;
    }
    cout << "Отсортированные числа: ";
    OutputNumbers(nums);

    cout << "\nЗадание 2.в\n";
    nums.clear();
    cout << "Введите количество чисел: ";
    do
    {
        cin >> inputAmount;
        if (inputAmount > 64)
        {
            cout << "Введите число меньшее 64.\n";
        }
    } while (inputAmount > 64);

    InputNumbers(nums, inputAmount, 64);
    cout << "Введенные числа: ";
    OutputNumbers(nums);

    vector<unsigned char> charContainers(8);
    for (unsigned char num : nums)
    {
        charContainers[num / 8] |= 1 << (unsigned int)num % 8;
    }
    nums.clear();
    for (unsigned int i = 0; i < 64; i++)
    {
        if (charContainers[i / 8] % 2)
        {
            nums.push_back(i);
        }
        charContainers[i / 8] >>= 1;
    }
    cout << "Отсортированные числа: ";
    OutputNumbers(nums);
}

void PrintFirstExample(unsigned int x, unsigned int mask, unsigned int shift)
{
    cout << "Начальное значение x: " << x << "\n";
    cout << "Начальная маска: " << mask << "\n";
    cout << "Сдвиг маски влево на " << shift << " битов\n";

    x = x & (~(mask << shift));
    cout << "x = " << x << "\n";
}

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
