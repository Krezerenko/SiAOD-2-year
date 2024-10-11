#pragma once
#include "TaskContainer.h"
class Homework6_1 :
    public Task
{
public:
    Homework6_1(std::string name) : Task(name)
    {
    }

    void Execute() override;
};

