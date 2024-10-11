#include "HomeworkSelector.h"
#include "Homework5_1.h"
#include "Homework5_2.h"
#include "Homework6_1.h"

using namespace std;

HomeworkSelector::HomeworkSelector(): TaskContainer("root")
{
    _tasks = { new Homework5_1("5.1"), new Homework5_2("5.2"), new Homework6_1("6.1") };
}

void HomeworkSelector::ExecuteFormatted()
{
    TaskContainer::ExecuteFormatted("Введите номер работы. Для выхода наберите \"выход\". Доступные номера:\n|Ввод: |выход|Неверный номер работы. Повторите ввод: ");
}
