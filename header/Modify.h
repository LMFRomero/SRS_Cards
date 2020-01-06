#ifndef MODIFY_H
#define MODIFY_H

#include "DataBase.h"
#include "Keyboard.h"
#include "Screen.h"

class Modify {
	public:
		Modify (Keyboard, Screen, DataBase);

		virtual ~Modify () {}

		virtual void execute ();

	private:
		Screen screen;
		Keyboard keyboard;
		DataBase database;

		int displayModifyMenu (void);
		int displayActionMenu (void);
		int getPasteMenu (void);
		bool setPathInDatabase (int);
		void addFlashCard (void);
		void removeFlashCard (void);
};

#endif
