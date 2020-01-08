#include <bits/stdc++.h>
#include <stdlib.h>
#include "DataBase.h"
#include "FlashCard.h"

using namespace std;


DataBase::DataBase() {
	path = "./database/";
}

void DataBase::setPath (string addPath) {
	path.append(addPath);
}

void DataBase::resetPath (void) {
	path = "./database/";
}

string DataBase::getPath (void) {
	return path;
}

bool DataBase::rm (string fileName) {
	string cardPath = this->getPath();
	string listPath = this->getPath();
	string tmpPath = this->getPath();

	char *card;
        int day;
	int month;
	int year;

	int wasRemoved;

	FILE *list;
	FILE *tmp;



	cardPath.append(fileName);
	listPath.append("cardList");
	tmpPath.append("tmp");

	wasRemoved = remove(cardPath.c_str());

	if (wasRemoved == -1) return false;

	list = fopen(listPath.c_str(), "a+");
	tmp = fopen(tmpPath.c_str(), "w+");

	while (fscanf(list, " %ms %d %d %d", &card, &day, &month, &year) != EOF) {
		if (fileName == string(card)) continue;
		fprintf(tmp, "%s %d %d %d\n", card, day, month, year);
	}

	free(card);

	fclose(list);
	fclose(tmp);

	remove(cardPath.c_str());
	remove(listPath.c_str());
	rename(tmpPath.c_str(), listPath.c_str());

	return true;
}

bool DataBase::add (FlashCard flashcard) {
	string cardName = flashcard.getName();
	string cardPath = this->getPath().append(cardName);
	string japanese = flashcard.getJapanese();
	string furigana = flashcard.getFurigana();
	string translation = flashcard.getTranslation();
	string cardListPath = this->getPath().append("cardList"); 
	string tmpPath = this->getPath().append("tmp");

	Date date = flashcard.getDate();

	int LN = flashcard.getLN();
	float EF = flashcard.getEF();
	int fcDay = date.getDay();
	int fcMonth = date.getMonth();
	int fcYear = date.getYear();

	FILE *fileName;	
	FILE *cardList;
	FILE *tmp;


	fileName = fopen(cardPath.c_str(), "r");
	if (fileName != NULL) {
		fclose (fileName);
		return false;
	}
	
	fileName = fopen(cardPath.c_str(), "w+");
	fprintf(fileName, "%d\n%f\n%s\n%s\n%s\n", LN, EF, japanese.c_str(), furigana.c_str(), translation.c_str());

	fclose(fileName);

	cardList = fopen(cardListPath.c_str(), "r+");
	tmp = fopen(tmpPath.c_str(), "w+");

	bool wasAdded = false;
	bool isEmpty = true;
	char *name;
	int day, month, year;

	while(fscanf(cardList, " %ms %d %d %d", &name, &day, &month, &year) != EOF) {
		Date tmpDate(day, month, year);

		if ((tmpDate == date or tmpDate > date) and wasAdded == false) {
			wasAdded = true;
			fprintf(tmp, "%s %d %d %d\n", cardName.c_str(), fcDay, fcMonth, fcYear);
		}

		fprintf(tmp, "%s %d %d %d\n", name, day, month, year);
		isEmpty = false;
	}

	if (isEmpty == true) {
			fprintf(tmp, "%s %d %d %d\n", cardName.c_str(), fcDay, fcMonth, fcYear);	
	}

	fclose(cardList);
	fclose(tmp);
	remove(cardListPath.c_str());
	rename(tmpPath.c_str(), cardListPath.c_str());

	return true;
}

vector <FlashCard> DataBase::getTodaysCards (void) {

}
