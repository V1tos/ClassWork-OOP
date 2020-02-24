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

