#include "HomeworkSelector.h"
#include "Homework5_1.h"
#include "Homework5_2.h"

using namespace std;

HomeworkSelector::HomeworkSelector(): TaskContainer("root")
{
    _tasks = { new Homework5_1("5.1"), new Homework5_2("5.2") };
}

void HomeworkSelector::ExecuteFormatted()
{
    TaskContainer::ExecuteFormatted("������� ����� ������. ��� ������ �������� \"�����\". ��������� ������:\n|����: |�����|�������� ����� ������. ��������� ����: ");
}
