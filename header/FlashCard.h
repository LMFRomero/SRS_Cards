#ifndef FLASHCARD_H
#define FLASHCARD_H

#include <string>
#include "Date.h"

using std::string;

class FlashCard {
	public:
		FlashCard(string, Date, string, string, string);
		string getName (void);
		Date getDate (void);
		int getLN (void);
		float getEF (void);
		string getJapanese (void);
		string getFurigana (void);
		string getTranslation (void);
	
	private:
		string name;
		int LN;
		float EF;
		Date date;
		string japanese;
		string furigana;
		string translation;
};

#endif
