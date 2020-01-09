#include <bits/stdc++.h>
#include <stdlib.h>
#include "DataBase.h"
#include "FlashCard.h"
#include "Date.h"

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
	string japanese = flashcard.getJapanese();
	string furigana = flashcard.getFurigana();
	string translation = flashcard.getTranslation();
	int LN = flashcard.getLN();
	float EF = flashcard.getEF();

	string cardPath = this->getPath().append(cardName);

	FILE *fileName;	

	fileName = fopen(cardPath.c_str(), "r");
	if (fileName != NULL) {
		fclose (fileName);
		return false;
	}
	
	fileName = fopen(cardPath.c_str(), "w+");
	fprintf(fileName, "%d\n%f\n%s\n%s\n%s\n", LN, EF, japanese.c_str(), furigana.c_str(), translation.c_str());

	fclose(fileName);
	
	appendToCardList(flashcard);

	return true;
}

void DataBase::appendToCardList (FlashCard flashcard) {
	string cardName = flashcard.getName();
	Date date = flashcard.getDate();
	int fcDay = date.getDay();
	int fcMonth = date.getMonth();
	int fcYear = date.getYear();

	string cardListPath = this->getPath().append("cardList"); 
	string tmpPath = this->getPath().append("tmp");

	FILE *cardList = fopen(cardListPath.c_str(), "a+");
	FILE *tmp = fopen(tmpPath.c_str(), "w+");

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

	if (isEmpty == true or (isEmpty == false and wasAdded == false)) {
			fprintf(tmp, "%s %d %d %d\n", cardName.c_str(), fcDay, fcMonth, fcYear);	
	}

	fclose(cardList);
	fclose(tmp);
	remove(cardListPath.c_str());
	rename(tmpPath.c_str(), cardListPath.c_str());
}

vector <FlashCard> DataBase::getTodaysCards (void) {
	string pathToPaste = getPath();
	string pathCardList = getPath().append("cardList");
	string pathTmpCard;

	Date today = getCurrentDate();
	int day, month, year;
	char *name;
	int LN;
	float EF;
	char *japanese, *furigana, *translation;

	FILE *cardList = fopen(pathCardList.c_str(), "a+");
	FILE *tmpFile;

	vector <FlashCard> flashCardVector;


	while (fscanf(cardList, " %ms %d %d %d", &name, &day, &month, &year) != EOF) {
		Date tmpDate(day, month, year);

		if (tmpDate > today) break;

		pathTmpCard = pathToPaste;
		pathTmpCard.append(string(name));
		tmpFile = fopen(pathTmpCard.c_str(), "r+");

		fscanf(tmpFile, "%d %f %ms %ms %ms", &LN, &EF, &japanese, &furigana, &translation);
		
		FlashCard flashcard(name, LN, EF, tmpDate, string(japanese), string(furigana), string(translation));
		flashCardVector.push_back(flashcard);
		fclose(tmpFile);
	}

	fclose(cardList);

	return flashCardVector;
}

void DataBase::updateFlashCard (FlashCard flashcard) {
	string name = flashcard.getName();
	rm(name);
	add(flashcard);
}
