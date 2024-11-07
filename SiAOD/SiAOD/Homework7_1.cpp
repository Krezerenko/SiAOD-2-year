#include "Homework7_1.h"

#include <iostream>

#include "BinaryTree.h"
#include "Global.h"

void Homework7_1::Execute()
{
    std::string city;
    std::cout << "Введите корневой город дерева: ";
    std::cin >> city;
    std::cin.get();
    BinaryTree tree(city);
    std::string commandLine;
    std::vector<std::string> arguments;
    std::vector<std::string> elements;
    std::cout << "Команды:\ninsert, trin, trlv, find, print, mean, exit\n";
    std::cout << "Введите команды:\n";
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
                std::cout << "Предоставьте название города.\n\n";
                continue;
            }
            city = arguments[1];
            int distance = tree.Find(city, 0);
            if (distance < 0)
            {
                std::cout << "Город не найден.\n\n";
            }
            else
            {
                std::cout << "Расстояние до города: " << distance << "\n\n";
            }
        }
        else if (arguments[0] == "insert")
        {
            if (arguments.size() < 2)
            {
                std::cout << "Предоставьте название города.\n\n";
                continue;
            }
            city = arguments[1];
            tree.Insert(city);
            tree.Print(10, 0);
            std::cout << '\n';
        }
        else if (arguments[0] == "trin")
        {
            tree.TraverseInOrder(elements);
            for (auto element : elements)
            {
                std::cout << element + '\n';
            }
            std::cout << '\n';
            elements.clear();
        }
        else if (arguments[0] == "trlv")
        {
            tree.TraverseLevelOrder(elements);
            for (auto element : elements)
            {
                std::cout << element + '\n';
            }
            std::cout << '\n';
            elements.clear();
        }
        else if (arguments[0] == "print")
        {
            tree.Print(10, 0);
            std::cout << '\n';
        }
        else if (arguments[0] == "mean")
        {
            std::cout << tree.Average() << "\n\n";
        }
        else if (arguments[0] == "exit")
        {
            return;
        }
        else
        {
            std::cout << "Неверная команда.\n\n";
        }
    }
}

Homework7_1::Homework7_1(const std::string& name): Task(name)
{
}
