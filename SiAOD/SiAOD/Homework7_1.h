#pragma once
#include "Task.h"
class Homework7_1 final :
    public Task
{
    void Execute() override;
public:
    explicit Homework7_1(const std::string& name);
};

