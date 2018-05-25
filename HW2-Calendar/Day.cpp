#pragma once
#include "stdafx.h"
#include "Day.h"

void Day::copy(const Day& other)
{
	this->capacity = other.capacity;
	this->size = other.size;
	this->tasks = new Task*[other.capacity];
	for (int i = 0; i < other.size; i++)
	{
		this->tasks[i] = other.tasks[i]->clone();
	}
}
void Day::erase()
{
	for (int i = 0; i < this->size; i++)
	{
		delete this->tasks[i];
	}
	delete[] this->tasks;
}
Day::Day()
{
	this->capacity = 5;
	this->tasks = new Task*[this->capacity];
	this->size = 0;
}
Day::Day(const Day& other)
{
	copy(other);
}
Day& Day::operator=(const Day& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}
	return *this;
}
Day::~Day()
{
	erase();
}
void Day::includeTask(const Task* other) {
	if (this->size >= this->capacity);
	{
		resize();
	}
	this->tasks[size] = other->clone();
	this->size++;
}
void Day::resize()
{
	Task** temp = new Task*[this->capacity * 2];
	for (int i = 0; i < this->size; i++)
	{
		temp[i] = this->tasks[i]->clone();
	}
	erase();
	this->capacity = this->capacity * 2;
	this->tasks = temp;
}
void Day::printTasks()
{
	if (this->size == 0)
	{
		std::cout << "\nNo tasks for that day" << std::endl;
	}
	for (int i = 0; i < this->size; i++)
	{
		std::cout << std::endl;
		this->tasks[i]->print();
	}
}
void Day::removeTask(std::string name)
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->tasks[i]->getName() == name)
		{
			delete this->tasks[i];
			this->size--;
		}
	}
}
