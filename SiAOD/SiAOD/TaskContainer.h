#pragma once
#include"Task.h"
#include <string>
#include<vector>

class TaskContainer : public Task
{
protected:
	std::vector<Task*> _tasks;
public:
	TaskContainer(std::string name);
	const std::vector<Task*>& Tasks();
    void Execute() override;
	void ExecuteFormatted(const std::string& text =
        "Введите номер задания. Доступные номера:\n|Ввод: |Неверный номер задания. Повторите ввод: \n") override;
};

