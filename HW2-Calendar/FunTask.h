#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Task.h"

class FunTask : public Task
{
private:
	std::string activity;
	char* location;
	void copy(const FunTask&);
public:
	FunTask();
	FunTask(const FunTask&);
	FunTask& operator=(const FunTask&);
	~FunTask();
	void addTask(size_t, size_t, int);
	void forecast();
	FunTask* clone()const;
	void print();
	const std::string getName()const;
};