#pragma once
#include "stdafx.h"
#include <iostream>

class Time
{
private:
	size_t HH;
	size_t MM;
public:
	Time();
	Time(size_t, size_t);
	//friend std::istream& operator>>(std::istream& in, Time& time);
	friend std::ostream& operator<<(std::ostream& out, const Time& time);
	const size_t getHH()const;
	const size_t getMM()const;
	//bool enoghTime(const Time& start, const Time& end);
};
