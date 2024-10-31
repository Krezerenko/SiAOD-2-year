#include "HomeworkSelector.h"
#include "Homework5_1.h"
#include "Homework5_2.h"
#include "Homework6_1.h"
#include "Homework6_2.h"
#include "Homework7_1.h"

using namespace std;

HomeworkSelector::HomeworkSelector(): TaskContainer("root")
{
    _tasks = { new Homework5_1("5.1"), new Homework5_2("5.2"), new Homework6_1("6.1"), new Homework6_2("6.2"), new Homework7_1("7.1") };
}

void HomeworkSelector::ExecuteFormatted()
{
    TaskContainer::ExecuteFormatted("������� ����� ������. ��� ������ �������� \"�����\". ��������� ������:\n|����: |�����|�������� ����� ������. ��������� ����: ");
}
