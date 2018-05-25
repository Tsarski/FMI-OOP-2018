#pragma once
#include "stdafx.h"
#include "TaskManagement.h"

void newTask(Calendar &calendar)
{
	int type = 0;
	size_t day = 0;
	size_t month = 0;

	while (type < 1 || type>3)
	{
		std::cout << "What type of task do you want?" << std::endl;   
		std::cout<<"   Enter 1 for Business Task\n   Enter 2 for University task\n   Enter 3 for Entertainment Task: "; 
		std::cin >> type;
	}
	while (month < 1 || month>12)
	{
		std::cout << "Enter the number of the month of your task: ";
		std::cin >> month;
	}
	if (month == 2)
	{
		while (day < 1 || day>28)
		{
			std::cout << "Enter the date of the task: ";
			std::cin >> day;
			std::cin.ignore();
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		while (day < 1 || day>30)
		{
			std::cout << "Enter the date of the task: ";
			std::cin >> day;
			std::cin.ignore();
		}
	}
	else
	{
		while (day < 1 || day>31)
		{
			std::cout << "Enter the date of the task: ";
			std::cin >> day;
			std::cin.ignore();
		}
	}
	if (type == 1)
	{
		BusinessTask temp;
		temp.addTask(day, month, type);
		Task* tempp = new BusinessTask(temp);
		calendar.includeTask(day, month, tempp);
		delete tempp;
	}
	else if (type == 2)
	{
		UniTask temp;
		temp.addTask(day, month, type);
		Task* tempp = new UniTask(temp);
		calendar.includeTask(day, month, tempp);
		delete tempp;
	}
	else
	{
		FunTask temp;
		temp.addTask(day, month, type);
		temp.forecast();
		Task* tempp = new FunTask(temp);
		calendar.includeTask(day, month, tempp);
		delete tempp;
	}
}
void printTasks(Calendar& calendar)
{
	size_t day = 0;
	size_t month = 0;

	while (month < 1 || month>12)
	{
		std::cout << "Enter the number of the month: ";
		std::cin >> month;
	}
	if (month == 2)
	{
		while (day < 1 || day>28)
		{
			std::cout << "Enter the date: ";
			std::cin >> day;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		while (day < 1 || day>30)
		{
			std::cout << "Enter the date: ";
			std::cin >> day;
		}
	}
	else
	{
		while (day < 1 || day>31)
		{
			std::cout << "Enter the date: ";
			std::cin >> day;
			std::cin.ignore();
		}
	}
	calendar.printTasks(month, day);
}
void removeTask(Calendar& calendar)
{
	size_t day=0;
	size_t month=0;
	std::string taskName;
	while (month < 1 || month>12)
	{
		std::cout << "Enter the number of the month of the task: ";
		std::cin >> month;
	}
	if (month == 2)
	{
		while (day < 1 || day>28)
		{
			std::cout << "Enter the date of the task: ";
			std::cin >> day;
		}
	}
	else if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		while (day < 1 || day>30)
		{
			std::cout << "Enter the date of the task: ";
			std::cin >> day;
		}
	}
	else
	{
		while (day < 1 || day>31)
		{
			std::cout << "Enter the date: ";
			std::cin >> day;
			std::cin.ignore();
		}
	}
	std::cout << "Enter the name of the task: ";
	getline(std::cin, taskName);
	calendar.removeTask(month, day, taskName);
}