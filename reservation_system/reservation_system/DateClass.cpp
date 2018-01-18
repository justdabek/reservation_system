#pragma once
#include "DateClass.h"


string DateClass::getStringDate()
{
	string temp;
	int sday = this->day;
	int smonth = this->month;
	int shour = this->hour;
	int sminutes = this->minutes;

	

	temp = to_string(sday) + "." + to_string(smonth) + " " + to_string(shour) + ":" + to_string(sminutes) +"\n";
	
	return temp;
}