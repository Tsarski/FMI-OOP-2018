#pragma once
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include "Llist.h"
#include "Month.h"

class Calendar
{
private:
	char* description;
	Month* months;// = new Month[12]
	void copy(const Calendar&);
	void erase();
public:
	Calendar();
	Calendar(const Calendar&);
	Calendar& operator= (const Calendar&);
	~Calendar();
	const Month getMonthsAt(size_t)const;
	void includeTask(size_t, size_t, const Task*);
	void printTasks(size_t, size_t);
	void removeTask(size_t, size_t, std::string);
};
