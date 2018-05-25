#pragma once
#include "stdafx.h"
#include <iostream>
#include <string.h>
#include "Time.h"
//#include "Calendar.h"

class Task
{
protected:
	std::string name;
	std::string description;
	size_t day;
	size_t month;
	Time start;
	Time end;
	static size_t count;
	int type;
public:
	virtual void addTask(size_t, size_t, int) =0;
	virtual void print() = 0;
	virtual Task* clone()const = 0;
	virtual const std::string getName()const = 0;
	Task();
	~Task();
};
