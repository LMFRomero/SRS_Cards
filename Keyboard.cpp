#ifdef __unix__
	#define STDINPATH "/dev/tty"

#elif defined(_WIN32) || defined(WIN32)
	#define STDINPATH "con:"

#endif

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
		freopen(STDINPATH, "r", stdin);
	      	return answer;
	}

	answer = string(answerPtr);

	return answer; 
}

string Keyboard::getLine(void) {
	string answer;
	char *answerPtr;

	if (scanf(" %m[^\r\n]", &answerPtr) == EOF) {
		freopen(STDINPATH, "r", stdin);
	      	return answer;
	}

	answer = string(answerPtr);

	return answer; 
}

int Keyboard::getChar(void) {
	fflush(stdin);
	char flag;

	int number = scanf("%*c%c", &flag);

	if ((int) flag != 10) {
		number = scanf("%*s");
	}

	if (number == EOF) {
		freopen(STDINPATH, "r", stdin);
	}

	return number;
}
