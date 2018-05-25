#pragma once
#include "stdafx.h"
#include "FunTask.h"
#pragma warning(disable : 4996)

void FunTask::copy(const FunTask& other)
{
	this->location = new char[strlen(other.location) + 1];
	strcpy(this->location, other.location);
	this->activity = other.activity;
	this->day = other.day;
	this->month = other.month;
	this->description = other.description;
	this->start = other.start;
	this->end = other.end;
	this->name = other.name;
}
FunTask::FunTask()
{
	this->location = 0;
}
FunTask::FunTask(const FunTask& other)
{
	copy(other);
}
FunTask& FunTask::operator=(const FunTask& other)
{
	if (this != &other)
	{
		delete[]location;
		copy(other);
	}
	return *this;
}
FunTask::~FunTask()
{
	delete[] this->location;
}
void FunTask::addTask(size_t day, size_t month, int type)
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
	std::cout << "Enter the type of activity: ";
	getline(std::cin, this->activity);
	std::cout << "Enter the location of the task/activity: ";
	char temp[50];
	std::cin.getline(temp, 49);
	this->location = new char[strlen(temp) + 1];
	strcpy(this->location, temp);
}
FunTask* FunTask::clone()const
{
	return new FunTask(*this);
}
void FunTask::forecast()
{
	char* first = "start chrome  https://www.sinoptik.bg/search?q={";
	char* link = new char[strlen(first) + strlen(this->location) + 2];
	strcpy(link, first);
	strcat(link, this->location);
	strcat(link, "}");
	system (link);
	delete[]link;
}
void FunTask::print()
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
		<< "\nEnding time: " << this->end << "\nType: " << typeInText << "\nLocation: " << this->location
		<< "\nActivity: " << this->activity << std::endl;
}
const std::string FunTask::getName()const
{
	return this->name;
}
