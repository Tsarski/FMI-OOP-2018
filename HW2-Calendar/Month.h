#pragma once
#include "stdafx.h"
#include <iostream>
#include "Day.h"
 
class Month
{
private:
	size_t numberOfDays;
	Day* days;
	
	void copy(const Month&);
	void erase();
public:
	Month();
	Month(size_t);
	Month(const Month&);
	Month& operator=(const Month&);
	~Month();
	const Day getDaysAt(size_t)const;
	void includeTask(size_t, const Task*);
	void printTasks(size_t);
	void removeTask(size_t, std::string);
};
