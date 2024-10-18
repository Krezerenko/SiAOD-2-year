#pragma once
#include "TaskContainer.h"
class Homework6_2 final :
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

public:
    Homework6_2(const std::string& name);
};

