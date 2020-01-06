#include <bits/stdc++.h>
#include "Computer.h"

using namespace std;


enum menuOption {EXIT = 0, FLASHCARDS, STUDY, MODIFY};


void Computer::run (void) {
	bool userExited = false;
	int mainMenuChoice;

	while (!userExited) {
		mainMenuChoice = displayMainMenu();

		switch (mainMenuChoice) {
			case FLASHCARDS:
				screen.displayLineMessage("Coming Soon...");
				break;

			case STUDY:
				screen.displayLineMessage("Coming Soon...");
				break;

			case MODIFY:
				screen.displayLineMessage("Coming Soon...");
				break;

			case EXIT:
				userExited = true;
				screen.displayLineMessage("Thank you!");
				break;

			default:
				screen.displayLineMessage("Not a valid option. Try again.");
				break;
		}
	}
}

int Computer::displayMainMenu (void) {
	screen.displayLineMessage("\nMain Menu:");
	screen.displayLineMessage("1 - Play FlashCards");
	screen.displayLineMessage("2 - Study");
	screen.displayLineMessage("3 - Modify");
	screen.displayLineMessage("0 - Exit");
	screen.displayMessage("Enter a choice: ");
	return keyboard.getMenuOption();

}

