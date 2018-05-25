#pragma once
#include "stdafx.h"
#include "Task.h"
#include "Llist.h"
#include "Duration.h"
#include <string>
#include "Guests.h"

class BusinessTask : public Task
{
private:
	Guests host;
	std::string location;
	Llist<Guests> guests;
	Time length;
public:
	void addTask(size_t, size_t, int);
	BusinessTask* clone()const;
	void print();
	const std::string getName()const;
	//Task* taski = taski2->clone();
};
