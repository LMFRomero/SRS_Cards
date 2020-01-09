#include <iostream>
#include <stdlib.h>
#include "Keyboard.h"

using namespace std;

int Keyboard::getMenuOption(void) {
	char *answer;
	char *pEnd;

	fflush(stdin);
	fflush(stdout);

	if (scanf(" %[^\n\r]", answer) == EOF) { 
		freopen("/dev/tty", "r", stdin);
		return -1;
	}

	int number = static_cast<int> (strtol(answer, &pEnd, 10));

	return number;
}

string Keyboard::getAnswer(void) {
	string answer;
	char *answerPtr;

	if (scanf(" %ms", &answerPtr) == EOF) {
		freopen("/dev/tty", "r", stdin);
	      	return answer;
	}

	answer = string(answerPtr);

	return answer; 
}

string Keyboard::getLine(void) {
	string answer;

	getline(cin, answer);

	return answer;
}

int Keyboard::getChar(void) {
	fflush(stdin);
	int number = scanf("%*c%*c");

	if (number == EOF) {
		freopen("/dev/tty", "r", stdin);
	}

	return number;
}
