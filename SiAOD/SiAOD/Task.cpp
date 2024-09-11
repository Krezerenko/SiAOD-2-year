#include "Task.h"

Task::Task(std::string name)
{
	_name = name;
}

const std::string& Task::Name() const
{
	return _name;
}
