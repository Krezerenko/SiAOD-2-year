#pragma once
#include"Task.h"
#include <string>
#include <vector>

class TaskContainer : public Task
{
protected:
	std::vector<Task*> _tasks;
	TaskContainer(std::string name);
public:
	const std::vector<Task*>& Tasks();
    void Execute() override;
	void ExecuteFormatted(const std::string& text) override;
	void ExecuteFormatted() override;
};

