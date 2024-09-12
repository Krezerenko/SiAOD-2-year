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

	cout << "Введите номер работы.\nДоступные номера:\n";

	for (auto hw : _homeworks)
	{
		cout << hw.Name() << "\n";
	}
	cout << "Ввод: ";
	do
	{
		getline(cin, hwName);
		auto it = find_if(_homeworks.begin(), _homeworks.end(), [hwName](Homework& hw) {return hw.Name() == hwName; });
		if (it == _homeworks.end())
		{
			cout << "Неверный номер работы.\nПовторите ввод: ";
		}
		else
		{
			foundHomework = &(*it);
			break;
		}
	} while (true);

	cout << "Введите номер задания.\nДоступные номера:\n";

	for (auto task : foundHomework->Tasks())
	{
		cout << task->Name() << "\n";
	}
	cout << "Ввод: ";
	do
	{
		getline(cin, hwName);
		auto it = find_if(foundHomework->Tasks().begin(), foundHomework->Tasks().end(), [hwName](const Task* t) { return t->Name() == hwName; });
		if (it == foundHomework->Tasks().end())
		{
			cout << "Неверный номер задания.\nПовторите ввод: ";
		}
		else
		{
			cout << "\n";
			(*it)->Execute();
			break;
		}
	} while (true);

	cout << "Программа завершена.\n";
}
