#pragma once
#include "stdafx.h"
#include <iostream>
#include <string>

class Guests
{
private:
	std::string firstName;
	std::string lastName;
public:
	const std::string getFirstName()const;
	const std::string getLastName()const;
	void setFirstName(std::string);
	void setLastName(std::string);
	friend std::ostream& operator<<(std::ostream&, const Guests&);
};