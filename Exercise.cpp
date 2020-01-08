#include <bits/stdc++.h>
#include "DataBase.h"
#include "Screen.h"
#include "Keyboard.h"
#include "Exercise.h"
#include "FlashCard.h"

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
		database.resetPath();

		switch (userMenuChoice) {
			case VOCABULARY:
			case PHRASES:
			case HIRAGANA:
			case KATAKANA:
				practiceCards(userMenuChoice);
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

void Exercise::practiceCards (int menuChoice) {
	vector <FlashCard> flashCardsVector;
	string answer = "Initializing";
	bool hadCards = false;
	
	switch (menuChoice) {
		case HIRAGANA:
			database.setPath("hiragana/");	
			break;

		case KATAKANA:
			database.setPath("katakana/");
			break;

		case VOCABULARY:
			database.setPath("vocabulary/");
			break;

		case PHRASES:
			database.setPath("phrases/");
			break;
	}	

	flashCardsVector = database.getTodaysCards();

	while (flashCardsVector.empty() == false and answer.empty() == false) {
		
	}

	if (flashCardsVector.empty() == true) {
		if (hadCards == true)
			screen.displayLineMessage("No more cards to review today.");
		else
			screen.displayLineMessage("No cards to review today.");
	}

	
}

