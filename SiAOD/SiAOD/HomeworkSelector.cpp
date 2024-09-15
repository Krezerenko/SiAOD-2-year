#include "HomeworkSelector.h"
#include "Homework5_1.h"
#include <iostream>
#include <string>

using namespace std;

HomeworkSelector::HomeworkSelector(): TaskContainer("root")
{
    _tasks = { new Homework5_1("5.1") };
}

void HomeworkSelector::ExecuteFormatted(const std::string& text)
{
    TaskContainer::ExecuteFormatted(text);
}
