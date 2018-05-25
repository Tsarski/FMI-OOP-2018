#pragma once
#include "stdafx.h"
#include "Duration.h"

Time duration(const Time& start, const Time& end)
{
	Time duration;
	size_t startTemp = start.getHH() * 60 + start.getMM();
	size_t endTemp = end.getHH() * 60 + end.getMM();
	int durationMin = endTemp - startTemp;
	if (durationMin < 0)
	{
		Time time((24 + durationMin / 60), (-durationMin) % 60);
		duration = time;
	}
	else
	{
		Time time((durationMin / 60), (durationMin % 60));
		duration = time;
	}
	return duration;
}
