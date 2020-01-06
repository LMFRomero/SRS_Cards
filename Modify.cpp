#include <bits/stdc++.h>
#include "Modify.h"
#include "Screen.h"
#include "Keyboard.h"
#include "DataBase.h"

using namespace std;

enum modifyOption {EXIT = 0, VOCABULARY, PHRASES};
enum actionOption {ADD = 1, RM};

Modify::Modify (Keyboard keyboard1, Screen screen1, DataBase database1)
	: keyboard (keyboard1), 
	  screen(screen1),
	  database(database1)
	  {}

void Modify::execute (void) {
	bool userExited = false;
	int userMenuChoice;
	
	while (!userExited) {
		userMenuChoice = displayActionMenu();
		database.resetPath();

		switch (userMenuChoice) {
			case ADD:
				addFlashCard();
				break;

			case RM:
				removeFlashCard();
				break;

			case EXIT:
				userExited = true;
				break;

			default:
				screen.displayLineMessage("Not a valid option. Try again.");
		}
	}	
}

int Modify::displayModifyMenu (void) {
	screen.displayLineMessage("\nWhat do you want to modify?");
	screen.displayLineMessage("1 - Vocabulary");
	screen.displayLineMessage("2 - Phrases");
	screen.displayLineMessage("0 - Exit");
	screen.displayMessage("Enter a choice: ");
	return keyboard.getMenuOption();
}

int Modify::displayActionMenu (void) {
	screen.displayLineMessage("\nWhat do you want to do?");
	screen.displayLineMessage("1 - Add Flashcards");
	screen.displayLineMessage("2 - Remove Flashcards");
	screen.displayLineMessage("0 - Exit");
	screen.displayMessage("Enter a choice: ");
	return keyboard.getMenuOption();
}


int Modify::getPasteMenu (void) {
	bool userExited = false;
	int userMenuChoice;

	while (!userExited) {
		userMenuChoice = displayModifyMenu();

		switch (userMenuChoice) {
			case VOCABULARY:
			case PHRASES:
			case EXIT:
				userExited = true;
				break;

			default:
				screen.displayLineMessage("Not a valid option. Try again.");
				break;
		}

	}

	return userMenuChoice;
}

bool Modify::setPathInDatabase (int pasteOption) {
	switch (pasteOption) {
		case VOCABULARY:
			database.setPath("vocabulary/");
			return true;
			break;

		case PHRASES:
			database.setPath("phrases/");
			return true;
			break;

		case EXIT:
			return false;

	}
	
	return false;
}

void Modify::addFlashCard (void) {
	bool didPasteSet = setPathInDatabase(getPasteMenu());

	if (didPasteSet == false) return;

}

void Modify::removeFlashCard (void) {
	bool didPasteSet = setPathInDatabase(getPasteMenu());

	string answer;

	if (didPasteSet == false) return;

	screen.displayMessage("Which card do you want to remove? ");
	answer = keyboard.getAnswer();

	if (database.rm(answer)) {
		screen.displayLineMessage("Card removed successfully.");
	}

	else {
		screen.displayLineMessage("Card not found.");
	}
}

