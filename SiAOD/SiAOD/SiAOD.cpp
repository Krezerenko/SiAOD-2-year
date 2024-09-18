#include <Windows.h>
#include "HomeworkSelector.h"
#include <iostream>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto selector = HomeworkSelector();
    selector.ExecuteFormatted();
}
