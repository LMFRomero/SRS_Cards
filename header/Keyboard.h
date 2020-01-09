#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <string>

using namespace std;

class Keyboard {
	public:
		int getMenuOption(void);
		string getAnswer(void);
		string getLine(void);
		int getChar (void);
};

#endif
