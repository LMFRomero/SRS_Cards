#ifndef COMPUTER_H
#define COMPUTER_H

#include "Keyboard.h"
#include "Screen.h"
#include "DataBase.h"

class Computer {
	public:
		void run(void);

	private:
		Screen screen;
		Keyboard keyboard;
		DataBase database;

		int displayMainMenu(void);
};

#endif
