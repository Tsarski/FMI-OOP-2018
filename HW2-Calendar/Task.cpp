#pragma once
#include "stdafx.h"
#include "Task.h"

size_t Task::count = 0;
Task::Task()
{
	this->count++;
	this->type = 0;
}
Task::~Task()
{
	this->count--;
}