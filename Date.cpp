#include <bits/stdc++.h>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <time.h>
#include "Date.h"

using namespace std;

Date::Date(int day, int month, int year) {
	//there is no need for any validations since the Date Class
	//will not be used by users
	
	setMonth(month);
	setDay(day);
	setYear(year);
}

void Date::setDay(int Day) {
	day = Day;
}

void Date::setMonth(int Month) {	
	month = Month;
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

bool Date::operator < (Date date) {
	if (this->year < date.getYear()) return true;
	else if (this->year == date.getYear() and this->month < date.getMonth()) return true;
	else if (this->year == date.getYear() and this->month == date.getMonth() and this->day < date.getDay()) return true;
	return false;
}

bool Date::operator == (Date date) {
	if (this->year == date.getYear() and this->month == date.getMonth() and this->day == date.getDay()) return true;
	return false;
}

bool Date::operator > (Date date) {
	if (this->year > date.getYear()) return true;
	else if (this->year == date.getYear() and this->month > date.getMonth()) return true;
	else if (this->year == date.getYear() and this->month == date.getMonth() and this->day > date.getDay()) return true;
	return false;
}

Date Date::operator + (int Days) {
	//this operator sums days to a date
	
	short unsigned int Year = year, Month = month, Day = day;
	boost::gregorian::date dateObj {Year, Month, Day};
	boost::gregorian::days daysObj (Days);
	dateObj += daysObj;

	Date result(dateObj.day(), dateObj.month(), dateObj.year());

	return result;
}

Date getCurrentDate() {
    time_t now = time(0);
    struct tm timeStruct;
    timeStruct = *localtime(&now);

	Date date(timeStruct.tm_mday, timeStruct.tm_mon+1, timeStruct.tm_year+1900);

    return date;
}
