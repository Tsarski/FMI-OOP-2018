#include "stdafx.h"
#include <iostream>
#include <string>
#include "BusinessTask.h"
#include "Duration.h"
#include "TaskManagement.h"

void menu(Calendar& calendar)
{
	int action = 0;
	while (action < 1 || action>3)
	{
		std::cout << "What would you like to do? \n  Enter 1 to add new task \n  Enter 2 to remove existing task \n  Enter 3 to print tasks for certain day: " << std::endl;
		std::cin >> action;
	}
	if (action == 1)
	{
		newTask(calendar);
	}
	else if (action == 2)
	{
		removeTask(calendar);
	}
	else
	{
		printTasks(calendar);
	}
	std::cin.ignore();
	
}
int main()
{
	Calendar one;
	menu(one);
	menu(one);
	return 0;
}

