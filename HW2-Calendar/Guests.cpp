#pragma once
#include "stdafx.h"
#include "Guests.h"

const std::string Guests::getFirstName()const
{
	return this->firstName;
}
const std::string Guests::getLastName()const
{
	return this->lastName;
}
void Guests::setFirstName(std::string fname)
{
	this->firstName = fname;
}
void Guests::setLastName(std::string lname)
{
	this->lastName = lname;
}
std::ostream& operator<<(std::ostream& out, const Guests& name)
{
	out << name.firstName << " " << name.lastName;
	return out;
}