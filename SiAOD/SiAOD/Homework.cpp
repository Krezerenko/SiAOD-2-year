#include "Homework.h"

Homework::Homework(std::string name)
{
	_name = name;
}

const std::string& Homework::Name()
{
	return _name;
}

const std::vector<Task*>& Homework::Tasks()
{
	return _tasks;
}

void Homework::ExecuteTask(std::string taskName)
{
	auto it = std::find_if(_tasks.begin(), _tasks.end(), [taskName](Task* t) { return t->Name() == taskName; });
	if (it == _tasks.end()) return;

	(*it)->Execute();
}

void Homework::ExecuteAll()
{
	for (unsigned int i = 0; i < _tasks.size(); i++)
	{
		_tasks[i]->Execute();
	}
}
