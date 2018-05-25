#pragma once
#include "stdafx.h"
#include <iostream>
#include "Llist.h"
#include "Task.h"

class Day
{
private:
	Task** tasks;
	size_t size;
	size_t capacity;
	void copy(const Day&);
	void erase();
	void resize();
public:
	Day();
	Day(const Day&);
	Day& operator=(const Day&);
	~Day();
	void includeTask(const Task*);
	void printTasks();
	void removeTask(std::string);
};
