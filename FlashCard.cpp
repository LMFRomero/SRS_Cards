#include <bits/stdc++.h>
#include "FlashCard.h"

FlashCard::FlashCard (string fcName, int ln, float ef, Date fcDate, string Jap, string Fur, string Tra) : date(fcDate) {
	name = fcName;
	japanese = Jap;
	furigana = Fur;
	translation = Tra;
	LN = ln;
	EF = ef;
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

void FlashCard::setLN (int ln) {
	LN = ln;
}

void FlashCard::setEF (int ef) {
	EF = ef;
}

void FlashCard::setDate (Date fcDate) {
	date = fcDate;
}
