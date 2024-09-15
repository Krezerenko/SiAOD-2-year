#pragma once
#include "TaskContainer.h"

class HomeworkSelector : TaskContainer
{
public:
	HomeworkSelector();
	void ExecuteFormatted(const std::string& text = "Введите номер работы. Доступные номера:\n|Ввод: |Неверный номер работы. Повторите ввод: \n") override;
};

