#include "Homework6_1.h"

#include <iostream>
#include <string>
#include <vector>

#include "BankInfo.h"
#include "HashTable.h"

void Homework6_1::Execute()
{
    HashTable<BankInfo> table(10);
    table.Insert(1234567, BankInfo("������ �����", "�������� ������������ 78"));
    table.Insert(1234576, BankInfo("������� ������", "�������� ������������ 78"));
    table.Insert(2134567, BankInfo("���� ����", "�������� ������������ 78"));
    table.Insert(1324567, BankInfo("���� ����", "�������� ������������ 78"));
    table.Insert(1235467, BankInfo("����� ����", "�������� ������������ 78"));
    std::cout << "�������� �������:\n" << table;
    std::string commandLine;
    std::vector<std::string> arguments;
    unsigned int key;
    std::cout << "�������:\ninsert, delete, find, rehash, print, exit\n";
    std::cout << "������� �������:\n";
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, commandLine);
        Split(commandLine, " ", arguments);

        if (arguments.empty() || arguments[0].empty()) continue;

        if (arguments[0] == "find")
        {
            if (arguments.size() < 2)
            {
                std::cout << "������������ ����.\n\n";
                continue;
            }
            key = std::stoi(arguments[1]);
            const BankInfo* info = table.Find(key);
            if (info == nullptr)
            {
                std::cout << "������ �� �������.\n\n";
            }
            else
            {
                std::cout << "��������� ������: " << *info << "\n\n";
            }
        }
        else if (arguments[0] == "insert")
        {
            if (arguments.size() < 4)
            {
                std::cout << "������������ ����, ��� � �����.\n\n";
                continue;
            }
            key = std::stoi(arguments[1]);
            table.Insert(key, BankInfo(arguments[2], arguments[3]));
            std::cout << table << '\n';
        }
        else if (arguments[0] == "delete")
        {
            if (arguments.size() < 2)
            {
                std::cout << "������������ ����.\n\n";
                continue;
            }
            key = std::stoi(arguments[1]);
            table.Delete(key);
            std::cout << table << '\n';
        }
        else if (arguments[0] == "rehash")
        {
            if (arguments.size() < 2)
            {
                std::cout << "������������ ����� ������.\n\n";
                continue;
            }
            unsigned int newSize = std::stoi(arguments[1]);
            table.Rehash(newSize);
            std::cout << table << '\n';
        }
        else if (arguments[0] == "print")
        {
            std::cout << table << '\n';
        }
        else if (arguments[0] == "exit")
        {
            return;
        }
        else
        {
            std::cout << "�������� �������.\n\n";
        }
    }
}
