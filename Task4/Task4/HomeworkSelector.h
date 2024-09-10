#pragma once
#include "Homework.h"
#include <string>
#include<vector>


class HomeworkSelector
{
	std::vector<Homework> _homeworks;
public:
	HomeworkSelector();
	void Start();
};

