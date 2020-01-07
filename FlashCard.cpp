#include <bits/stdc++.h>
#include "FlashCard.h"

FlashCard::FlashCard (string fcName, Date fcDate, string Jap, string Fur, string Tra) : date(fcDate) {
	name = fcName;
	japanese = Jap;
	furigana = Fur;
	translation = Tra;
	LN = 0;
	EF = 2.5;
}

string FlashCard::getName (void) {
	return name;
}

Date FlashCard::getDate (void) {
	return date;
}

int FlashCard::getLN (void) {
	return LN;
} 

float FlashCard::getEF (void) {
	return EF;
}

string FlashCard::getJapanese (void) {
	return japanese;
}

string FlashCard::getFurigana (void) {
	return furigana;
}

string FlashCard::getTranslation (void) {
	return translation;
}

