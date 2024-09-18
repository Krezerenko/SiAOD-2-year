#pragma once
#include "TaskContainer.h"
#include <string>
#include <fstream>

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

