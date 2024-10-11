#pragma once
#include "TaskContainer.h"
#include <string>
#include <fstream>

void GenerateStudentsFile(std::ofstream& file, unsigned int studentsAmount, unsigned int keySize, unsigned int groupSize, unsigned int nameSize);
char* LinearFileSearch(const std::string& fileName, const unsigned int key, const unsigned int entrySize, const unsigned int keyPosition);
void PrintStudent(char* student, const unsigned int keySize, const unsigned int groupSize, const unsigned int nameSize);
void GenerateKeyTable(std::vector<unsigned long long>& table, std::ifstream& file, const unsigned int entrySize, const unsigned int keyOffset);
void SortKeyTable(std::vector<unsigned long long>& table);
void GenerateLookupTable(unsigned int len, std::vector<unsigned int>& table);
unsigned int BinarySearchInKeyTable(const std::vector<unsigned long long>& keyTable, unsigned int key, const std::vector<unsigned int>& lookupTable);
char* AccessFileByRef(std::ifstream& file, const unsigned int ref, const unsigned int entrySize);

class Homework5_2 :
    public TaskContainer
{
    class Task1 final : public Task
    {
    public:
        Task1(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

    class Task2 final : public Task
    {
    public:
        Task2(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

    class Task3 final : public Task
    {
    public:
        Task3(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };
public:
    Homework5_2(const std::string& name);
};

