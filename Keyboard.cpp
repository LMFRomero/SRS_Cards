#include <iostream>
#include <stdlib.h>
#include "Keyboard.h"

using namespace std;

int Keyboard::getMenuOption(void) {
	char *answer;
	char *pEnd;

	fflush(stdin);
	fflush(stdout);

	scanf(" %[^\n\r]", answer);
	int number = static_cast<int> (strtol(answer, &pEnd, 10));

	return number;
}

string Keyboard::getAnswer(void) {
	string answer;
	char *answerPtr;

	if (scanf(" %ms", &answerPtr) == EOF) return answer;

	answer = string(answerPtr);

	return answer; 
}

string Keyboard::getLine(void) {
	string answer;

	getline(cin, answer);

	return answer;
}
