#ifndef DATABASE_H
#define DATABASE_H

#include <string>
using namespace std;

class FlashCard;

class DataBase{
	public:
		DataBase();

		void setPath (string);
		void resetPath (void);
		string getPath (void);
		bool add (FlashCard);
		bool rm (string);

	private:
		string path;
};

#endif
