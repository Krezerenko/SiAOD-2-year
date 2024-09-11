#pragma once
#include <string>

class Task
{
protected:
	std::string _name;
public:
	Task(std::string name);
	virtual ~Task() = default;

	const std::string& Name() const;
	virtual void Execute() = 0;
};

