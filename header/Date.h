#ifndef DATE_H
#define DATE_H

class Date {
	public:
		Date(int, int, int);
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		int getDay(void);
		int getMonth(void);
		int getYear(void);
		bool operator < (Date);
		bool operator = (Date);
		bool operator > (Date);
		Date operator + (int);
	private:
		int day;
		int month;
		int year;		
};

#endif
