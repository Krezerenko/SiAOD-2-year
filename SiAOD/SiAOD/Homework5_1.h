#pragma once
#include "TaskContainer.h"

class Homework5_1 :
    public TaskContainer
{
    class Task1a final : public Task 
    {
    public:
        Task1a(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

    class Task1b final : public Task
    {
    public:
        Task1b(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

    class Task1c final : public Task
    {
    public:
        Task1c(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

    class Task2a final : public Task
    {
    public:
        Task2a(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

    class Task2b final : public Task
    {
    public:
        Task2b(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

    class Task2c final : public Task
    {
    public:
        Task2c(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

    class Task3a final : public Task
    {
    public:
        Task3a(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

    class Task3b final : public Task
    {
    public:
        Task3b(const std::string& name) : Task(name)
        {
        }
        void Execute() override;
    };

public:
    Homework5_1(std::string name);
};

