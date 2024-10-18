#pragma once
#include "TaskContainer.h"
class Homework6_1 final :
    public Task
{
public:
    explicit Homework6_1(const std::string& name) : Task(name)
    {
    }

    void Execute() override;
};

