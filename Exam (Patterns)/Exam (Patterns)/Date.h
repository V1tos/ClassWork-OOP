#pragma once
#include <iostream>
#include <string>
using namespace std;

const short DAYS_IN_MONTH = 31;
const short MONTHS_IN_YEAR = 12;
const short MIN_YEAR = 2020;
const short MAX_YEAR = 2100;

class Date
{
	short day;
	short month;
	short year;
public:
	Date();
	Date(short day, short month, short year);
	void SetDate(short day, short month, short year);
	Date GetDate();
	void ShowDate();
	~Date();
};
