#ifndef EXERCISE_H
#define EXERCISE_H

class Screen;
class Keyboard;
class DataBase;

class Exercise {
	public:
		Exercise (Keyboard, Screen, DataBase);

		virtual ~Exercise () {}

		virtual void execute ();

	private:
		Screen screen;
		Keyboard keyboard;
		DataBase database;

		int displayPlayMenu (void);
		void practiceCards (int);
		int showFlashcard (FlashCard);
		int getAnswerQuality (void);
		void setPathInDatabase (int);
		float parseQuality (int);
		int parseLN (int, float);

};

#endif
