#pragma once
#include <iostream>
#include "Room.h"

class DateClass
{
private:
	int day, month, hour, minutes;
public:
	DateClass() :day(0), month(0), hour(0), minutes(0) {};
	DateClass(int d, int m, int h, int min) : day(d), month(m), hour(h), minutes(min) {};

	int getDay() { return day; }
	int getMonth() { return month; }
	int getHour() { return hour; }
	int getMinutes() { return minutes; }
	string getStringDate();

};
