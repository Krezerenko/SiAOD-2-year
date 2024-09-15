#pragma once
#include "TaskContainer.h"
class Homework5_1 :
    public TaskContainer
{
    class Task1a final : public Task 
    {
    public:
        using Task::Task;
        void Execute() override;
    };

    class Task1b final : public Task
    {
    public:
        using Task::Task;
        void Execute() override;
    };

    class Task1c final : public Task
    {
    public:
        using Task::Task;
        void Execute() override;
    };

    class Task2a final : public Task
    {
    public:
        using Task::Task;
        void Execute() override;
    };

    class Task2b final : public Task
    {
    public:
        using Task::Task;
        void Execute() override;
    };

    class Task2c final : public Task
    {
    public:
        using Task::Task;
        void Execute() override;
    };

    class Task3a final : public Task
    {
        using Task::Task;
        void Execute() override;
    };

    class Task3b final : public Task
    {
        using Task::Task;
        void Execute() override;
    };

public:
    Homework5_1(std::string name);
};

