#include "Homework5_1.h"
#include "Functions.h"
#include <iostream>
#include <bitset>
#include <chrono>
#include <fstream>

using namespace std;

Homework5_1::Homework5_1(string name) : Homework(name)
{
    _tasks = {
    	new Task1a("1.а"), new Task1b("1.б"), new Task1c("1.в"),
    	new Task2a("2.а"), new Task2b("2.б"), new Task2c("2.в"),
    	new Task3a("3.а"), new Task3b("3.б")};
}

void Homework5_1::Task1a::Execute()
{
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
}

void Homework5_1::Task1b::Execute()
{
    cout << "\nЗадание 1.б.\n";

    unsigned int x = 255;
    unsigned int mask = 1;

    unsigned int shift = 7;
    PrintFirstExample(x, mask, shift);
}

void Homework5_1::Task1c::Execute()
{
    cout << "\nЗадание 1.в\n";

    unsigned int x = 255;
    unsigned int mask = 1;

    const int n = sizeof(int) * 8;
    x = 25;
    mask = 1 << (n - 1);
    cout << "Начальная маска: " << mask << " = " << bitset<n>(mask) << "\n";
    cout << "Результат: ";

    for (unsigned int i = 1; i <= n; i++)
    {
        cout << ((x & mask) >> (n - i));
        mask >>= 1;
    }
    cout << "\n";
}

void Homework5_1::Task2a::Execute()
{
    vector<unsigned char> nums;
    unsigned int inputAmount;

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
        charContainer |= 1 << num;
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
}

void Homework5_1::Task2b::Execute()
{
    vector<unsigned char> nums;
    unsigned int inputAmount;

    cout << "\nЗадание 2.б\n";
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
        longContainer |= (unsigned long long)1 << num;
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
}

void Homework5_1::Task2c::Execute()
{
    vector<unsigned char> nums;
    unsigned int inputAmount;

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
        charContainers[num / 8] |= 1 << num % 8;
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

void Homework5_1::Task3a::Execute()
{
    ofstream initFile("nums.txt", ios_base::trunc | ios_base::out);
    unsigned int numsAmount;
    cout << "Введите количество чисел: ";
    cin >> numsAmount;
    for (unsigned int i = 0; i < numsAmount; ++i)
    {
        initFile << numsAmount - i - 1 << "\n";
    }

    initFile.close();

    cout << "Числа записаны в файл. ";
    system("pause");

    auto start = chrono::high_resolution_clock::now();

    ifstream inFile("nums.txt", ios_base::in);
    vector<unsigned char> charContainers(numsAmount / 8);
    unsigned int buffer;

    for (unsigned int i = 0; i < numsAmount; ++i)
    {
        inFile >> buffer;
        charContainers[buffer / 8] |= 1 << (buffer % 8);
    }

    inFile.close();

    ofstream wFile("nums.txt", ios_base::trunc | ios_base::out);

    for (unsigned int i = 0; i < numsAmount; i++)
    {
        if (charContainers[i / 8] % 2)
        {
            wFile << i << "\n";
        }
        charContainers[i / 8] >>= 1;
    }

    wFile.close();

    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;

    cout << "Затраченное время: " << (chrono::duration_cast<chrono::milliseconds>(duration)).count() / 1000.0 << " с.\n";
}

void Homework5_1::Task3b::Execute()
{
    ofstream initFile("nums.txt", ios_base::trunc | ios_base::out);
    unsigned int numsAmount;
    cout << "Введите количество чисел: ";
    cin >> numsAmount;
    for (unsigned int i = 0; i < numsAmount; ++i)
    {
        initFile << numsAmount - i - 1 << "\n";
    }

    initFile.close();

    cout << "Числа записаны в файл. ";
    system("pause");

    auto start = chrono::high_resolution_clock::now();
    unsigned int memCount = 0;

    ifstream inFile("nums.txt", ios_base::in);
    vector<unsigned char> charContainers(numsAmount / 8);
    memCount += numsAmount / 8;
    unsigned int buffer;
    memCount += 4;

    for (unsigned int i = 0; i < numsAmount; ++i)
    {
        inFile >> buffer;
        charContainers[buffer / 8] |= 1 << (buffer % 8);
    }

    inFile.close();

    ofstream wFile("nums.txt", ios_base::trunc | ios_base::out);

    for (unsigned int i = 0; i < numsAmount; i++)
    {
        if (charContainers[i / 8] % 2)
        {
            wFile << i << "\n";
        }
        charContainers[i / 8] >>= 1;
    }

    wFile.close();

    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;

    cout << "Затраченное время: " << (chrono::duration_cast<chrono::milliseconds>(duration)).count() / 1000.0 << " с.\n";
    cout << "Размер использованной оперативной памяти: " << memCount / 1024.0 / 1024.0 << " Mb\n";
}

void Homework5_1::PrintFirstExample(unsigned int x, unsigned int mask, unsigned int shift)
{
    cout << "Начальное значение x: " << x << "\n";
    cout << "Начальная маска: " << mask << "\n";
    cout << "Сдвиг маски влево на " << shift << " битов\n";

    x = x & (~(mask << shift));
    cout << "x = " << x << "\n";
}
