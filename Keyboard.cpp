#include <iostream>
#include "Keyboard.h"

using namespace std;

int Keyboard::getMenuOption(void) {
	int answer;

	fflush(stdin);
	fflush(stdout);

	scanf("%d", &answer);

	return answer;
}

string Keyboard::getAnswer(void) {
	string answer;

	cin >> answer;

	return answer; 
}

string Keyboard::getLine(void) {
	string answer;

	getline(cin, answer);

	return answer;
}
