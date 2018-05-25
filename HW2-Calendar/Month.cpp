#pragma once
#include "stdafx.h"
#include "Month.h"

void Month::copy(const Month& other)
{
	this->numberOfDays = other.numberOfDays;
	this->days = new Day[other.numberOfDays];
	for (int i = 0; i < other.numberOfDays; i++)
	{
		this->days[i] = other.days[i];
	}
}
void Month::erase()
{
	delete[] this->days;
}
Month::Month()
{
	//this->days = nullptr;
	this->numberOfDays = 0;
	this->days = 0;
}
Month::Month(size_t dayNum)
{
	this->numberOfDays = dayNum;
	this->days = new Day[dayNum];
}
Month::Month(const Month& other)
{
	copy(other);
}
Month& Month::operator=(const Month& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
Month::~Month()
{
	erase();
}
const Day Month::getDaysAt(size_t i)const
{
	return this->days[i];
}
void Month::includeTask(size_t day, const Task* task)
{
	this->days[day].includeTask(task);
}
void Month::printTasks(size_t day)
{
	this->days[day].printTasks();
}
void Month::removeTask(size_t day, std::string name)
{
	this->days[day].removeTask(name);
}