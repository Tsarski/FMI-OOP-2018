#pragma once
#include "stdafx.h"
#include "BusinessTask.h"

void BusinessTask::addTask(size_t day, size_t month, int type)
{
	this->day = day;
	this->month = month;
	this->type = type;
	std::cout << "Enter name of the task: ";
	getline(std::cin, this->name);
	std::cout << "Enter task's description: ";
	getline(std::cin, this->description);
	size_t hhs=24;
	while(hhs>23)
	{ 
		std::cout << "Enter starting time: \n  Hours(0-23):";
		std::cin >> hhs;
	}
	size_t mms=60;
	while (mms > 59)
	{
		std::cout << "  Minutes(0-59):";
		std::cin >> mms;
	}
	std::cin.ignore();
	Time tempt(hhs, mms);
	this->start = tempt;
	size_t hhe=24;
	while (hhe > 23)
	{
		std::cout << "Enter ending time: \n  Hours(0-23):";
		std::cin >> hhe;
	}
	size_t mme=60;
	while (mme > 59)
	{
		std::cout << "  Minutes(0-59):";
		std::cin >> mme;
	}
	Time tempt2(hhe, mme);
	this->end = tempt2;
	std::cin.ignore();
	this->length = duration(this->start, this->end);
	std::cout << "Enter how many guest would be there: ";
	size_t guestNum;
	std::cin >> guestNum;
	std::cin.ignore();
	std::string tempName;
	Guests tempGuest;
	for (int i = 0; i < guestNum; i++)
	{
		std::cout << "Enter first name of guest " << i + 1<<": ";
		getline(std::cin, tempName);
		tempGuest.setFirstName(tempName);
		std::cout << "Enter last name of guest: " << i + 1<<": ";
		getline(std::cin, tempName);
		tempGuest.setLastName(tempName);
		this->guests.push_back(tempGuest);
	}
	std::cout << "Enter first name of the host: ";
	std::string tempHost;
	getline(std::cin, tempHost);
	this->host.setFirstName(tempHost);
	std::cout << "Enter last name of the host: ";
	getline(std::cin, tempHost);
	this->host.setLastName(tempHost);
	std::cout << "Enter location of the business task: ";
	getline(std::cin, this->location);
}
BusinessTask* BusinessTask::clone()const
{
	return new BusinessTask(*this);
}
void BusinessTask::print()
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
		<< "\nEnding time: " << this->end << "\nType: " << typeInText << "\nHost: " << this->host << "\nGuests: " << this->guests
		<< "\nDuration: " << this->length << std::endl;
}
const std::string BusinessTask::getName()const
{
	return this->name;
}