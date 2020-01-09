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
	bool hadCards = false;
	int quality;

	int LN;
	float EF;
	Date todayDate = getCurrentDate();

	setPathInDatabase (menuChoice);
	
	flashCardsVector = database.getTodaysCards();

	while (flashCardsVector.empty() == false) {
		hadCards == true;
		
		FlashCard flashcard = flashCardsVector.back();
		LN = flashcard.getLN();
		EF = flashcard.getEF();
		
		quality = showFlashcard(flashcard);	
		
		if (quality == EOF) {
			fflush(stdin);
			break;
		}

		EF = parseQuality(quality, EF);
		LN = parseLN(LN, EF);
		Date date = todayDate + LN;

		flashcard.setLN(LN);
		flashcard.setEF(EF);
		flashcard.setDate(date);

		database.updateFlashCard(flashcard);

		flashCardsVector.pop_back();
	}

	if (flashCardsVector.empty() == true) {
		if (hadCards == true)
			screen.displayLineMessage("No more cards to review today.");
		else
			screen.displayLineMessage("No cards to review today.");
	}	
}

int Exercise::showFlashcard (FlashCard flashcard) {
	string japanese = flashcard.getJapanese();
	string furigana = flashcard.getFurigana();
	string translation = flashcard.getTranslation();
	
	screen.displayLineMessage("\nCtrl+D to stop.");
	screen.displayMessage("Japanese: ");
	screen.displayLineMessage(japanese);

	if (japanese != furigana) {
		screen.displayMessage("Furigana: ");
		screen.displayLineMessage(furigana);
	}

	screen.displayLineMessage("Type ENTER to show translation.");

	if (keyboard.getChar() == EOF)  {
		return EOF;
	}
		
	screen.displayMessage("Translation: ");
	screen.displayLineMessage(translation);

	return getAnswerQuality();
}

int Exercise::getAnswerQuality (void) {
	screen.displayLineMessage("\nHow do you classify your answer?");
	screen.displayLineMessage("0 - Total forgot");
	screen.displayLineMessage("1 - Incorrect answer where the correct one is remembered");
	screen.displayLineMessage("2 - Incorrect answer where the correct one is easy remembered");
	screen.displayLineMessage("3 - Correct answer with serious difficulty");
	screen.displayLineMessage("4 - Correct answer with hesitation");
	screen.displayLineMessage("5 - Correct answer");
	screen.displayMessage("Enter a choice: ");
	return keyboard.getMenuOption();
}

void Exercise::setPathInDatabase (int menuChoice) {
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
}

float Exercise::parseQuality (int q, float oldEF) {
	float EF = oldEF + (0.1 - (5 - q) * (0.08 + (5 - q) * 0.02));
	return (EF < 1.3 ? 1.3 : EF);
}

int Exercise::parseLN (int LN, float EF) {
		switch (LN) {
			case 0:
				LN = 1;
				break;

			case 1:
				LN = 6;
				break;

			default:
				LN = roundf(LN*EF);
				break;
		}

		return LN;
}
