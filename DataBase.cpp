#include <bits/stdc++.h>
#include <stdlib.h>
#include "DataBase.h"

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
	int currentLN;
	float EF;
        int day;
	int month;
	int year;

	cardPath.append(fileName);
	listPath.append("cardList");
	tmpPath.append("tmp");

	FILE* file = fopen(cardPath.c_str(), "r");

	if (file == NULL) return false;

	fclose(file);

	FILE* list = fopen(listPath.c_str(), "a+");
	FILE* tmp = fopen(tmpPath.c_str(), "w+");

	while (fscanf(list, " %ms %d %f %d %d %d", &card, &currentLN, &EF, &day, &month, &year) != EOF) {
		if (fileName == string(card)) continue;
		fprintf(tmp, "%s %d %f %d %d %d\n", card, currentLN, EF, day, month, year);
	}

	free(card);

	fclose(list);
	fclose(tmp);

	remove(cardPath.c_str());
	remove(listPath.c_str());
	rename(tmpPath.c_str(), listPath.c_str());

	return true;
}
