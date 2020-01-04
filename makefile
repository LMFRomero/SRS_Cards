all: screen keyboard computer database
	g++ *.o main.cpp -o prog

run: clean
	./prog

clean:
	rm -f *.o

screen:
	g++ -c Screen.cpp

keyboard:
	g++ -c Keyboard.cpp

computer:
	g++ -c Computer.cpp

database:
	g++ -c Database.cpp
