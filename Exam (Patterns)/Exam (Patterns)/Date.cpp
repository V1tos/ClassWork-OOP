#include "Date.h"



Date::Date()
{
}

Date::Date(short day, short month, short year) {
	this->day = day;
	this->month = month;
	this->year = year;
}

void Date::SetDate(short day, short month, short year) {

}

Date Date::GetDate() {
	return *this;
}

void Date::ShowDate() {
	cout << day << "." << month << "." << year << endl;
}

Date::~Date()
{
}


bool CheckDate(short inputDay, short inputMonth, short inputYear) {
	return (inputDay <= DAYS_IN_MONTH && inputMonth <= MONTHS_IN_YEAR && inputYear >= MIN_YEAR && inputYear <= MAX_YEAR);
}