#ifndef COMPUTER_H
#define COMPUTER_H

#include "Keyboard.h"
#include "Screen.h"
#include "Database.h"

class Computer {
	public:
		void run(void);

	private:
		Screen screen;
		Keyboard keyboard;
		Database database;

		int displayMainMenu(void);
};

#endif
