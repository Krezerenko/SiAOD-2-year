#include "TaskContainer.h"
#include "Global.h"
#include <iostream>

using namespace std;

TaskContainer::TaskContainer(string name): Task(name)
{
}

const vector<Task*>& TaskContainer::Tasks()
{
	return _tasks;
}

void TaskContainer::Execute()
{
    for (auto task : _tasks)
    {
        task->Execute();
    }
}

void TaskContainer::ExecuteFormatted(const string& text)
{
	vector<string> parts;
	Split(text, "|", parts);

	string taskName;
	if (!parts.empty()) 
		cout << parts[0];

	for (auto task : _tasks)
	{
		cout << task->Name() << "\n";
	}
	if (parts.size() >= 2) 
		cout << parts[1];

	do
	{
		getline(cin, taskName);
		auto it = find_if(_tasks.begin(), _tasks.end(), [taskName](const Task* t) { return t->Name() == taskName; });
		if (it == _tasks.end())
		{
			if (parts.size() >= 3) 
				cout << parts[2];
		}
		else
		{
			cout << "\n";
			(*it)->ExecuteFormatted();
			break;
		}
	} while (true);
}
