#include "Homework5_2.h"
#include "Global.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

void GenerateStudentsFile(ofstream& file, unsigned int studentsAmount, unsigned int keySize, unsigned int groupSize, unsigned int nameSize);
char* LinearFileSearch(const std::string& fileName, const unsigned int key, const unsigned int entrySize, const unsigned int keyPosition);
void PrintStudent(char* student, const unsigned int keySize, const unsigned int groupSize, const unsigned int nameSize);
void GenerateKeyTable(vector<unsigned long long>& table, ifstream& file, const unsigned int entrySize, const unsigned int keyOffset);

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
    auto start = chrono::high_resolution_clock::now();
    try
    {
        foundEntry = LinearFileSearch("students.sts", key, 64, 0);
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
    auto end = chrono::high_resolution_clock::now();
    auto duration = end - start;
    DisplayTimeDuration(duration);
}

void Homework5_2::Task3::Execute()
{
    ifstream file("students.sts", ios::binary | ios::in);
    vector<unsigned long long> keyTable;
    GenerateKeyTable(keyTable, file, 64, 0);

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
        *reinterpret_cast<int*>(idBuffer) = key;
        strncpy(idBuffer + keySize, "ИКБО-20-23", groupSize);
        strncpy(idBuffer + keySize + groupSize, nameBuffer.c_str(), nameBuffer.size());
        file.write(idBuffer, idSize);
    }

    delete idBuffer;
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
    char* entry = new char[entrySize];
    unsigned int i = 0;
    while (file.read(entry, entrySize))
    {
        unsigned int key = *reinterpret_cast<unsigned int*>(entry + keyOffset);
        *reinterpret_cast<unsigned int*>(&table[i]) = key;
        *reinterpret_cast<unsigned int*>(&table[i] + 4) = i;
        i++;
    }
}
