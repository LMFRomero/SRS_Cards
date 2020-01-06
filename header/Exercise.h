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

		int displayPlayMenu ();
};

#endif
