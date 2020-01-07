#include <bits/stdc++.h>
#include "Modify.h"
#include "Screen.h"
#include "Keyboard.h"
#include "DataBase.h"
#include "FlashCard.h"
#include "Date.h"

using namespace std;

enum modifyOption {EXIT = 0, VOCABULARY, PHRASES};
enum actionOption {ADD = 1, RM};

Modify::Modify (Keyboard keyboard1, Screen screen1, DataBase database1)
	: keyboard (keyboard1),
	  screen (screen1),
	  database (database1)
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

FlashCard Modify::getFlashCardInfo(int option) {
	string name;
	string japanese, furigana, translation;

	screen.displayMessage("What is the card's name? ");
	name = keyboard.getAnswer();

	if (option == 1) {
		screen.displayMessage("Japanese word: ");
		japanese = keyboard.getAnswer();
		screen.displayMessage("Furigana: ");
		furigana = keyboard.getAnswer();
		screen.displayMessage("Translation: ");
		translation = keyboard.getAnswer();
	}

	else if (option == 2) {
		screen.displayMessage("Japanese phrase: ");
		japanese = keyboard.getLine();
		screen.displayMessage("Furigana: ");
		furigana = keyboard.getLine();
		screen.displayMessage("Translation: ");
		translation = keyboard.getLine();
	}

	//Summing 1 to de date so the card can be
	//reviwed one day after its adding
	FlashCard flashcard(name, getCurrentDate()+1, japanese, furigana, translation);

	return flashcard;
}

void Modify::addFlashCard (void) {
	int pasteMenuOption = getPasteMenu();
	bool didPasteSet = setPathInDatabase(pasteMenuOption);

	if (didPasteSet == false) return;

	FlashCard flashcard = getFlashCardInfo(pasteMenuOption);
	
	if (database.add(flashcard) == true) {
		screen.displayLineMessage("Flashcard added successfully.");
	}

	else {
		screen.displayLineMessage("Something went wrong. Try again.");
	}
}

void Modify::removeFlashCard (void) {
	bool didPasteSet = setPathInDatabase(getPasteMenu());

	string answer;

	if (didPasteSet == false) return;

	screen.displayMessage("Which card do you want to remove? ");
	answer = keyboard.getAnswer();

	if (database.rm(answer) == true) {
		screen.displayLineMessage("Card removed successfully.");
	}

	else {
		screen.displayLineMessage("Card not found.");
	}
}

