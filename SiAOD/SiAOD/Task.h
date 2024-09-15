#pragma once
#include <string>

class Task
{
protected:
	std::string _name;
	Task(const std::string& name);
public:
	virtual ~Task() = default;

	const std::string& Name() const;
	virtual void Execute();
	virtual void ExecuteFormatted(const std::string& text);
	virtual void ExecuteFormatted();
};

