#include "Homework5_2.h"
#include "Global.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <unordered_set>

using namespace std;

Homework5_2::Homework5_2(const std::string& name) : TaskContainer(name)
{
    _tasks = { new Task1("1"), new Task2("2"), new Task3("3") };
}

void Homework5_2::Task1::Execute()
{
    ofstream file("students.sts", ios::trunc | ios::out | ios::binary);

    unsigned int studentsAmount;
    cout << "Введите количество студентов: ";
    do
    {
        cin >> studentsAmount;
        if (studentsAmount > 10000)
        {
            cout << "Введите число не большее 10000.\n";
        }
    } while (studentsAmount > 10000);

    GenerateStudentsFile(file, studentsAmount, 4, 10, 50);

    cout << "Запись информации о студентах завершена.\n";
}

void Homework5_2::Task2::Execute()
{
    unsigned int key;
    cout << "Введите ключ: ";
    cin >> key;
    char* foundEntry;
    chrono::time_point<chrono::steady_clock> start;
    chrono::time_point<chrono::steady_clock> end;
    try
    {
        start = chrono::high_resolution_clock::now();
        foundEntry = LinearFileSearch("students.sts", key, 64, 0);
        end = chrono::high_resolution_clock::now();
    }
    catch(invalid_argument& e)
    {
        cerr << "Файл не был найден.\n";
        return;
    }
    if (foundEntry == nullptr)
    {
        cout << "Ключ не найден.\n";
    }
    else
    {
        PrintStudent(foundEntry, 4, 10, 50);
    }
    auto duration = end - start;
    DisplayTimeDuration(duration);
}

void Homework5_2::Task3::Execute()
{
    ifstream file("students.sts", ios::binary | ios::in);
    vector<unsigned long long> keyTable;
    GenerateKeyTable(keyTable, file, 64, 0);
    vector<unsigned int> lookupTable;
    GenerateLookupTable(keyTable.size(), lookupTable);
    unsigned int inputKey;
    cout << "Введите ключ: ";
    cin >> inputKey;
    auto start = chrono::high_resolution_clock::now();
    unsigned int ref = BinarySearchInKeyTable(keyTable, inputKey, lookupTable);
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;

    if (ref == keyTable.size())
    {
        cout << "Ключ не найден.\n";
    }
    else
    {
        char* student = AccessFileByRef(file, ref, 64);
        PrintStudent(student, 4, 10, 50);
        delete[] student;
    }
    DisplayTimeDuration(duration);

    file.close();
}

void GenerateStudentsFile(ofstream& file, unsigned int studentsAmount, unsigned int keySize, unsigned int groupSize, unsigned int nameSize)
{
    ifstream names("names.txt");
    string nameBuffer;

    const unsigned int idSize = keySize + groupSize + nameSize;
    char* idBuffer = new char[idSize];

    vector<unsigned int> keys;
    srand(time(0));
    GenerateRandomKeys(studentsAmount * 2, studentsAmount, keys);

    for (unsigned int key : keys)
    {
        for (unsigned int i = 0; i < idSize; i++)
        {
            idBuffer[i] = 0;
        }
        getline(names, nameBuffer);
        *reinterpret_cast<unsigned int*>(idBuffer) = key;
        strncpy(idBuffer + keySize, "ИКБО-20-23", groupSize);
        strncpy(idBuffer + keySize + groupSize, nameBuffer.c_str(), nameBuffer.size());
        if (studentsAmount <= 100)
            PrintStudent(idBuffer, 4, 10, 50);
        file.write(idBuffer, idSize);
    }

    delete[] idBuffer;
    names.close();
}

char* LinearFileSearch(const string& fileName, const unsigned int key, const unsigned int entrySize, const unsigned int keyOffset)
{
    ifstream file(fileName, ios::binary | ios::in);
    if (!file)
    {
        file.close();
        throw invalid_argument("No file found with name " + fileName);
    }

    char* buffer = new char[entrySize];
    while (file.read(buffer, entrySize))
    {
        unsigned int readKey = *reinterpret_cast<unsigned int*>(buffer + keyOffset);
        if (readKey == key)
        {
            file.close();
            return buffer;
        }
    }
    file.close();
    return nullptr;
}

void PrintStudent(char* student, const unsigned int keySize, const unsigned int groupSize, const unsigned int nameSize)
{
    cout << "Номер зачетной книжки: " << *reinterpret_cast<unsigned int*>(student) << '\n';
    cout << "Номер группы: ";
    cout.write(student + keySize, groupSize) << '\n';
    cout << "ФИО: ";
    cout.write(student + keySize + groupSize, nameSize) << '\n';
}

void GenerateKeyTable(vector<unsigned long long>& table, ifstream& file, const unsigned int entrySize, const unsigned int keyOffset)
{
    table.clear();
    char* entry = new char[entrySize];
    unsigned int i = 0;
    while (file.read(entry, entrySize))
    {
        unsigned int key = *reinterpret_cast<unsigned int*>(entry + keyOffset);
        table.push_back(0);
        *reinterpret_cast<unsigned int*>(&table[i]) = key;
        *(reinterpret_cast<unsigned int*>(&table[i]) + 1) = i;
        i++;
    }
    SortKeyTable(table);
}

void SortKeyTable(vector<unsigned long long>& table)
{
    sort(table.begin(), table.end(), [](unsigned long long a, unsigned long long b)
    {
        return *reinterpret_cast<unsigned int*>(&a) < *reinterpret_cast<unsigned int*>(&b);
    });
}

void GenerateLookupTable(unsigned int len, std::vector<unsigned int>& table)
{
    table = vector<unsigned int>(static_cast<unsigned int>(log2(len)) + 3, 0);
    unsigned int power = 1;
    unsigned int count = 0;

    do
    {
        power <<= 1;
        table[count] = (len + (power >> 1)) / power;
    }
    while (table[count++] != 0);
}

unsigned int BinarySearchInKeyTable(const vector<unsigned long long>& keyTable, const unsigned int key, const vector<unsigned int>& lookupTable)
{
    unsigned int index = lookupTable[0] - 1;
    unsigned int count = 0;
    while (lookupTable[count] != 0)
    {
        if (key == *reinterpret_cast<const unsigned int*>(&keyTable[index]))
        {
            return *(reinterpret_cast<const unsigned int*>(&keyTable[index]) + 1);
        }

        if (key < *reinterpret_cast<const unsigned int*>(&keyTable[index]))
        {
            index -= lookupTable[++count];
        }
        else
        {
            index += lookupTable[++count];
        }
    }
    return keyTable.size();
}

char* AccessFileByRef(ifstream& file, const unsigned int ref, const unsigned int entrySize)
{
    file.clear();
    file.seekg(ref * entrySize, ios::beg);
    char* entry = new char[entrySize];
    file.read(entry, entrySize);
    return entry;
}
