#include <bits/stdc++.h>
#include "Date.h"

using namespace std;

Date::Date(int day, int month, int year) {
	cout << day << endl;
	setDay(day);
	setMonth(month);
	setYear(year);
}

void Date::setDay(int Day) {
	day = Day;
}

void Date::setMonth(int Month) {	
	month = Month%12;
}

void Date::setYear(int Year) {
	year = Year;
}

int Date::getDay() {
	return day;
}

int Date::getMonth() {
	return month;
}

int Date::getYear() {
	return year;
}

bool Date::lessThan(Date date) {
	if (this->year < date.getYear()) return true;
	else if (this->year == date.getYear() and this->month < date.getMonth()) return true;
	if (this->year == date.getYear() and this->getMonth() == date.getMonth() and this->day < date.getDay()) return true;
	return false;
}

bool Date::equal(Date date) {
	if (this->year == date.getYear() and this->month == date.getMonth() and this->day == date.getDay()) return true;
	return false;
}

bool Date::greaterThan(Date date) {
	if (this->year > date.getYear()) return true;
	else if (this->year == date.getYear() and this->month > date.getMonth()) return true;
	if (this->year == date.getYear() and this->month == date.getMonth() and this->day > date.getDay()) return true;
	return false;
}

