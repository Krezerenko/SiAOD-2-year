#include <Windows.h>
#include "HomeworkSelector.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    auto selector = HomeworkSelector();
    selector.Start();
}
