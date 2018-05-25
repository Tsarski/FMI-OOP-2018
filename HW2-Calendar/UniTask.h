#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Task.h"

class UniTask : public Task
{
private:
	std::string subject;
	std::string materials;
public:
	void addTask(size_t, size_t, int);
	UniTask* clone()const;
	void print();
	const std::string getName()const;
	
};
