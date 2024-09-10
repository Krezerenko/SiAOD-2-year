#pragma once
#include <string>
#include<vector>
#include"Task.h"

class Homework
{
protected:
	std::string _name;
	std::vector<Task*> _tasks;
public:
	Homework(std::string name);
	const std::string& Name();
	const std::vector<Task*>& Tasks();

	void ExecuteTask(std::string taskName);
	void ExecuteAll();
};

