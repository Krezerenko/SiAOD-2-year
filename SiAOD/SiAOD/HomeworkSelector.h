#pragma once
#include "TaskContainer.h"

class HomeworkSelector : TaskContainer
{
public:
	HomeworkSelector();
	void ExecuteFormatted(const std::string& text = "������� ����� ������. ��������� ������:\n|����: |�������� ����� ������. ��������� ����: \n") override;
};

