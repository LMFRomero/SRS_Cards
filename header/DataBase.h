#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "FlashCard.h"
using namespace std;


class DataBase{
	public:
		DataBase();

		void setPath (string);
		void resetPath (void);
		string getPath (void);
		bool add (FlashCard);
		bool rm (string);
		vector <FlashCard> getTodaysCards (void);
		void updateFlashCard (FlashCard);

	private:
		void appendToCardList (FlashCard);
		string path;
};

#endif
