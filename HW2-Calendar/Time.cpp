#pragma once
#include "stdafx.h"
#include "Time.h"
#include <cassert>

Time::Time()
{
	this->HH = 0;
	this->MM = 0;
}
Time::Time(size_t hh, size_t mm)
{
	assert(hh < 24 && mm < 60);
	this->HH = hh;
	this->MM = mm;
}
const size_t Time::getHH()const
{
	return this->HH;
}
const size_t Time::getMM()const
{
	return this->MM;
}
std::ostream& operator<<(std::ostream& out, const Time& time)
{
	if (time.HH < 10 && time.MM<10)
	{
		out << "0" << time.getHH() << ":" << "0" << time.getMM();
	}
	else if (time.HH >= 10 && time.MM < 10)
	{
		out << time.getHH() << ":" << "0" << time.getMM();
	}
	else if (time.HH < 10 && time.MM >= 10)
	{
		out << "0" << time.getHH() << ":" << time.getMM();
	}
	else
	{
		out<< time.getHH() << ":"<< time.getMM();
	}
	return out;
}
