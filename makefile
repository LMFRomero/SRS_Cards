test: screen keyboard computer dataBase date exercise modify
	g++ test.cpp -o test *.o; ./test -I ./header

all: screen keyboard computer dataBase date exercise modify
	g++ *.o main.cpp -o prog -I ./header

run: clean
	./prog

clean:
	rm -f *.o

screen:
	g++ -c Screen.cpp -I ./header

keyboard:
	g++ -c Keyboard.cpp -I ./header

computer:
	g++ -c Computer.cpp -I ./header

dataBase:
	g++ -c DataBase.cpp -I ./header

date:
	g++ -c Date.cpp -I ./boost -I ./header

exercise:
	g++ -c Exercise.cpp -I ./header

modify:
	g++ -c Modify.cpp -I ./header
