#pragma once
#include "TaskContainer.h"
class Homework_5_2 :
    public TaskContainer
{
    class Task1 : public Task
    {
    public:
        using Task::Task;
        void Execute() override;
    };

    class Task2 final : public Task
    {
    public:
        using Task::Task;
        void Execute() override;
    };

    class Task3 final : public Task
    {
        using Task::Task;
        void Execute() override;
    };

public:
    Homework_5_2(std::string name);
};

