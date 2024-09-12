#include "HomeworkSelector.h"
#include "Homework5_1.h"
#include <iostream>
#include <string>

using namespace std;

HomeworkSelector::HomeworkSelector()
{
	_homeworks = { Homework5_1("5.1") };
}

void HomeworkSelector::Start()
{
	string hwName;
	Homework* foundHomework;

	cout << "������� ����� ������.\n��������� ������:\n";

	for (auto hw : _homeworks)
	{
		cout << hw.Name() << "\n";
	}
	cout << "����: ";
	do
	{
		getline(cin, hwName);
		auto it = find_if(_homeworks.begin(), _homeworks.end(), [hwName](Homework& hw) {return hw.Name() == hwName; });
		if (it == _homeworks.end())
		{
			cout << "�������� ����� ������.\n��������� ����: ";
		}
		else
		{
			foundHomework = &(*it);
			break;
		}
	} while (true);

	cout << "������� ����� �������.\n��������� ������:\n";

	for (auto task : foundHomework->Tasks())
	{
		cout << task->Name() << "\n";
	}
	cout << "����: ";
	do
	{
		getline(cin, hwName);
		auto it = find_if(foundHomework->Tasks().begin(), foundHomework->Tasks().end(), [hwName](const Task* t) { return t->Name() == hwName; });
		if (it == foundHomework->Tasks().end())
		{
			cout << "�������� ����� �������.\n��������� ����: ";
		}
		else
		{
			cout << "\n";
			(*it)->Execute();
			break;
		}
	} while (true);

	cout << "��������� ���������.\n";
}
