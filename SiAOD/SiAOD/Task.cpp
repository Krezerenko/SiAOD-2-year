#include "Task.h"
#include "Global.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


Task::Task(const string& name)
{
	_name = name;
}

const string& Task::Name() const
{
	return _name;
}

void Task::Execute()
{
}

void Task::ExecuteFormatted(const std::string& text)
{
	vector<string> parts;
	Split(text, "|", parts);
	if (parts.size() >= 2)
	{
	    cout << parts[0] << _name << parts[1];
	}
	Execute();
	cout << "\n";
}

void Task::ExecuteFormatted()
{
	ExecuteFormatted("Задание |\n");
}
