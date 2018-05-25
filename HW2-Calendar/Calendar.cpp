#pragma once
#include "stdafx.h"
#include "Calendar.h"

void Calendar::copy(const Calendar& other)
{
	this->description = new char[strlen(other.description) + 1];
	strcpy(this->description, other.description);
	this->months = new Month[12];
	for (int i = 0; i < 12; i++)
	{
		this->months[i] = other.months[i];
	}
}
void Calendar::erase()
{
	delete[] this->description;
	delete[] this->months;
}
Calendar::Calendar()
{
	this->months = new Month[12];

	this->description = nullptr;
	for (int i = 0; i < 12; i++)
	{ 
		if (i == 3 || i == 5 || i == 8 || i == 10)
		{
			Month temp(30);
			this->months[i] = temp;
		}
		else if (i == 1)
		{
			Month temp(28);
			this->months[i] = temp;
		}
		else
		{
			Month temp(31);
			this->months[i] = temp;
		}
	}
}
Calendar::Calendar(const Calendar& other)
{
	copy(other);
}
Calendar& Calendar::operator=(const Calendar& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
Calendar::~Calendar()
{
	erase();
}
 const Month Calendar::getMonthsAt(size_t i)const
{
	return this->months[i];
}
 void Calendar::includeTask(size_t day, size_t month, const Task* task)
 {
	 this->months[month].includeTask(day, task);
 }
 void Calendar::printTasks(size_t month, size_t day)
 {
	 this->months[month].printTasks(day);
 }
 void Calendar::removeTask(size_t month, size_t day, std::string name)
 {
	 this->months[month].removeTask(day, name);
 }
