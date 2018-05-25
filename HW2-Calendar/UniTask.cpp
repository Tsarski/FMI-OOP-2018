#pragma once
#include "stdafx.h"
#include "UniTask.h"

void UniTask::addTask(size_t day, size_t month, int type)
{
	this->day = day;
	this->month = month;
	this->type = type;
	std::cout << "Enter name of the task: ";
	getline(std::cin, this->name);
	std::cout << "Enter task's description: ";
	getline(std::cin, this->description);
	size_t hhs = 24;
	while (hhs>23)
	{
		std::cout << "Enter starting time: \n  Hours(0-23):";
		std::cin >> hhs;
	}
	size_t mms = 60;
	while (mms > 59)
	{
		std::cout << "  Minutes(0-59):";
		std::cin >> mms;
	}
	std::cin.ignore();
	Time tempt(hhs, mms);
	this->start = tempt;
	size_t hhe = 24;
	while (hhe > 23)
	{
		std::cout << "Enter ending time: \n  Hours(0-23):";
		std::cin >> hhe;
	}
	size_t mme = 60;
	while (mme > 59)
	{
		std::cout << "  Minutes(0-59):";
		std::cin >> mme;
	}
	Time tempt2(hhe, mme);
	this->end = tempt2;
	std::cin.ignore();
	std::cout << "Enter subject of the university task: ";
	getline(std::cin, this->subject);
	std::cout << "Enter materials for the task: ";
	getline(std::cin, this->materials);
}
UniTask* UniTask::clone()const
{
	return new UniTask(*this);
}
void UniTask::print()
{
	std::string typeInText;
	if (this->type == 1)
	{
		typeInText = "Business Task";
	}
	else if (this->type == 2)
	{
		typeInText = "University Task";
	}
	else
	{
		typeInText = "Entertainment task";
	}
	std::cout << "Name of the task: " << this->name << "\nDescription of the task: " << this->description
		<< "\nDay: " << this->day << "\nMonth: " << this->month << "\nStarting time: " << this->start
		<< "\nEnding time: " << this->end << "\nType: " << typeInText << "\nSubject " << this->subject
		<< "\nMaterials to read: " << this->materials << std::endl;
}
const std::string UniTask::getName()const
{
	return this->name;
}

