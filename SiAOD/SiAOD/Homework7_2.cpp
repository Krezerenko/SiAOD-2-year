#include "Homework7_2.h"

#include <iostream>

#include "Global.h"
#include "Graph.h"

void Homework7_2::Execute()
{
    Graph graph;
    std::string commandLine;
    std::vector<std::string> arguments;
    std::vector<double> distances;
    std::vector<unsigned int> nodes;
    std::cout << "Команды:\naddn, rmn, sete, adde, minp, exit\n";
    std::cout << "Введите команды:\n";
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, commandLine);
        Split(commandLine, " ", arguments);

        if (arguments.empty() || arguments[0].empty()) continue;

        if (arguments[0] == "adde")
        {
            if (arguments.size() < 4)
            {
                std::cout << "Предоставьте пару узлов и вес.\n\n";
                continue;
            }
            unsigned int index1 = std::stoi(arguments[1]);
            unsigned int index2 = std::stoi(arguments[2]);
            double weight = std::stod(arguments[3]);
            graph.AddEdge(index1, index2, weight);
            graph.Print(5);
            std::cout << '\n';
        }
        else if (arguments[0] == "addn")
        {
            unsigned int amount = 1;
            if (arguments.size() >= 2)
            {
                amount = std::stoi(arguments[1]);
            }
            graph.AddNodes(amount);
            graph.Print(5);
            std::cout << '\n';
        }
        else if (arguments[0] == "rmn")
        {
            if (arguments.size() < 2)
            {
                std::cout << "Предоставьте индекс узла для удаления.\n\n";
                continue;
            }
            unsigned int index = std::stoi(arguments[1]);
            graph.RemoveNode(index);
            graph.Print(5);
            std::cout << '\n';
        }
        else if (arguments[0] == "print")
        {
            graph.Print(5);
            std::cout << '\n';
        }
        else if (arguments[0] == "minp")
        {
            if (arguments.size() < 2)
            {
                std::cout << "Предоставьте индекс начального узла.\n\n";
                continue;
            }
            unsigned int start = std::stoi(arguments[1]);
            graph.LeastDistances(start, distances, nodes);
            for (int i = 0; i < distances.size(); ++i)
            {
                std::cout << i << ": " << distances[i] << ' ' << nodes[i] << '\n';
            }
            std::cout << '\n';
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

Homework7_2::Homework7_2(const std::string& name) : Task(name)
{
}
