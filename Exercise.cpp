#include <bits/stdc++.h>
#include "DataBase.h"
#include "Screen.h"
#include "Keyboard.h"
#include "Exercise.h"

using namespace std;

enum menuOption {EXIT = 0, VOCABULARY, PHRASES, HIRAGANA, KATAKANA};

Exercise::Exercise (Keyboard keyboard1, Screen screen1, DataBase database1)
	: keyboard (keyboard1), 
	  screen(screen1),
	  database(database1)
	  {}

void Exercise::execute (void) {
	bool userExited = false;
	int userMenuChoice;

	while (!userExited) {
		userMenuChoice = displayPlayMenu();

		switch (userMenuChoice) {
			case VOCABULARY:
			case PHRASES:
			case HIRAGANA:
			case KATAKANA:
				//exercise(userMenuChoice);
				break;

			case EXIT:
				userExited = true;
				break;

			default:
				screen.displayLineMessage("Not a valid option. Try again.");
		}
	}
}

int Exercise::displayPlayMenu (void) {
	screen.displayLineMessage("\nWhat do you want to exercise?");
	screen.displayLineMessage("1 - Vocabulary");
	screen.displayLineMessage("2 - Phrases");
	screen.displayLineMessage("3 - Hiragana");
	screen.displayLineMessage("4 - Katakana");
	screen.displayLineMessage("0 - Exit");
	screen.displayMessage("Enter a choice: ");
	return keyboard.getMenuOption();
}
