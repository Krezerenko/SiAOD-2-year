#pragma once
#include "Task.h"
class Homework7_2 final :
    public Task
{
    void Execute() override;
public:
    explicit Homework7_2(const std::string& name);
};

