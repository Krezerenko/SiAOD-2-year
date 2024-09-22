#include "Homework5_1.h"
#include "Global.h"
#include <iostream>
#include <bitset>
#include <chrono>
#include <fstream>

using namespace std;

Homework5_1::Homework5_1(string name) : TaskContainer(name)
{
    _tasks = {
    	new Task1a("1.�"), new Task1b("1.�"), new Task1c("1.�"),
    	new Task2a("2.�"), new Task2b("2.�"), new Task2c("2.�"),
    	new Task3a("3.�"), new Task3b("3.�")};
}

void Homework5_1::Task1a::Execute()
{
    unsigned int inputAmount;
    unsigned int x;
    unsigned int mask = 1;

    cout << "������� ���������� ������ x: ";
    cin >> inputAmount;

    for (unsigned int i = 0; i < inputAmount; i++)
    {
        cout << "������� x: ";
        cin >> x;
        cout << "��������� 4-�� ���� x � 0\n";

        x = x & (~(mask << 4));
        cout << "x = " << x << "\n";
    }
}

void Homework5_1::Task1b::Execute()
{
    unsigned int inputAmount;
    unsigned int x;
    unsigned int mask = 1;

    cout << "������� ���������� ������ x: ";
    cin >> inputAmount;

    for (unsigned int i = 0; i < inputAmount; i++)
    {
        cout << "������� x: ";
        cin >> x;
        cout << "��������� 7-�� ���� x � 1\n";

        x = x | mask << 7;
        cout << "x = " << x << "\n";
    }
}

void Homework5_1::Task1c::Execute()
{

    const int n = sizeof(int) * 8;
    unsigned int x = 25;
    unsigned int mask = 1 << (n - 1);
    cout << "��������� �����: " << mask << " = " << bitset<n>(mask) << "\n";
    cout << "���������: ";

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

    cout << "������� ���������� �����: ";
    do
    {
        cin >> inputAmount;
        if (inputAmount > 8)
        {
            cout << "������� ����� ������� 8.\n";
        }
    } while (inputAmount > 8);

    InputNumbers(nums, inputAmount, 8);
    cout << "��������� �����: ";
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
    cout << "��������������� �����: ";
    OutputNumbers(nums);
}

void Homework5_1::Task2b::Execute()
{
    vector<unsigned char> nums;
    unsigned int inputAmount;

    cout << "������� ���������� �����: ";
    do
    {
        cin >> inputAmount;
        if (inputAmount > 64)
        {
            cout << "������� ����� ������� 64.\n";
        }
    } while (inputAmount > 64);

    InputNumbers(nums, inputAmount, 64);
    cout << "��������� �����: ";
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
    cout << "��������������� �����: ";
    OutputNumbers(nums);
}

void Homework5_1::Task2c::Execute()
{
    vector<unsigned char> nums;
    unsigned int inputAmount;

    nums.clear();
    cout << "������� ���������� �����: ";
    do
    {
        cin >> inputAmount;
        if (inputAmount > 64)
        {
            cout << "������� ����� ������� 64.\n";
        }
    } while (inputAmount > 64);

    InputNumbers(nums, inputAmount, 64);
    cout << "��������� �����: ";
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
    cout << "��������������� �����: ";
    OutputNumbers(nums);
}

void Homework5_1::Task3a::Execute()
{
    ofstream initFile("nums.txt", ios_base::trunc | ios_base::out);
    unsigned int numsAmount;
    cout << "������� ���������� �����: ";
    cin >> numsAmount;

    const int cBufferSize = 1024;
    char cBuffer[cBufferSize];

    unsigned int count = 0;

    for (unsigned int i = 0; i < numsAmount; ++i)
    {
        unsigned int rI = numsAmount - i - 1;
        _itoa(rI, cBuffer + count, 10);
        count += rI != 0 ? log10(rI) + 2 : 2;
        cBuffer[count - 1] = '\n';
        if (count > cBufferSize - 8)
        {
            initFile.write(cBuffer, count);
            count = 0;
        }
    }
    if (count > 0)
    {
        initFile.write(cBuffer, count);
        count = 0;
    }

    initFile.close();

    cout << "����� �������� � ����. ";
    system("pause");

    auto start = chrono::high_resolution_clock::now();

    ifstream inFile("nums.txt", ios_base::in);
    vector<unsigned char> charContainers(numsAmount / 8, 0);
    unsigned int buffer;
    string sBuffer;

    for (unsigned int i = 0; i < numsAmount; ++i)
    {
        getline(inFile, sBuffer);
        buffer = stoi(sBuffer);
        charContainers[buffer / 8] |= 1 << (buffer % 8);
    }

    inFile.close();

    ofstream wFile("nums.txt", ios_base::trunc | ios_base::out);

    for (unsigned int i = 0; i < numsAmount; i++)
    {
        if (charContainers[i / 8] % 2)
        {
            _itoa(i, cBuffer + count, 10);
            count += i != 0 ? log10(i) + 2 : 2;
            cBuffer[count - 1] = '\n';
            if (count > cBufferSize - 8)
            {
                wFile.write(cBuffer, count);
                count = 0;
            }
        }
        charContainers[i / 8] >>= 1;
    }
    if (count > 0)
    {
        wFile.write(cBuffer, count);
    }

    wFile.close();

    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;

    cout << "����������� �����: " << (chrono::duration_cast<chrono::milliseconds>(duration)).count() / 1000.0 << " �.\n";
}

void Homework5_1::Task3b::Execute()
{
    ofstream initFile("nums.txt", ios_base::trunc | ios_base::out);
    unsigned int numsAmount;
    cout << "������� ���������� �����: ";
    cin >> numsAmount;

    unsigned int memCount = 0;
    const int cBufferSize = 1024;
    char cBuffer[cBufferSize];
    memCount += cBufferSize;

    unsigned int count = 0;

    for (unsigned int i = 0; i < numsAmount; ++i)
    {
        //initFile << numsAmount - i - 1 << "\n";
        unsigned int rI = numsAmount - i - 1;
        _itoa(rI, cBuffer + count, 10);
        count += rI != 0 ? log10(rI) + 2 : 2;
        cBuffer[count - 1] = '\n';
        if (count > cBufferSize - 8)
        {
            initFile.write(cBuffer, count);
            count = 0;
        }
    }
    if (count > 0)
    {
        initFile.write(cBuffer, count);
        count = 0;
    }

    initFile.close();

    cout << "����� �������� � ����. ";
    system("pause");

    //ios::sync_with_stdio(false);

    auto start = chrono::high_resolution_clock::now();

    ifstream inFile("nums.txt", ios_base::in);
    vector<unsigned char> charContainers(numsAmount / 8, 0);
    memCount += numsAmount / 8;
    unsigned int buffer;
    string sBuffer;

    for (unsigned int i = 0; i < numsAmount; ++i)
    {
        //inFile >> buffer;
        getline(inFile, sBuffer);
        buffer = stoi(sBuffer);
        charContainers[buffer / 8] |= 1 << (buffer % 8);
    }

    inFile.close();

    ofstream wFile("nums.txt", ios_base::trunc | ios_base::out);

    for (unsigned int i = 0; i < numsAmount; i++)
    {
        if (charContainers[i / 8] % 2)
        {
            _itoa(i, cBuffer + count, 10);
            count += i != 0 ? log10(i) + 2 : 2;
            cBuffer[count - 1] = '\n';
            if (count > cBufferSize - 8)
            {
                wFile.write(cBuffer, count);
                count = 0;
            }
        }
        charContainers[i / 8] >>= 1;
    }
    if (count > 0)
    {
        wFile.write(cBuffer, count);
    }

    wFile.close();

    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;

    cout << "����������� �����: " << (chrono::duration_cast<chrono::milliseconds>(duration)).count() / 1000.0 << " �.\n";
    cout << "������ �������������� ����������� ������: " << memCount / 1024.0 / 1024.0 << " Mb\n";
}
