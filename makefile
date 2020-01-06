test: screen keyboard computer database date
	g++ test.cpp -o test *.o; ./test -I ./header

all: screen keyboard computer database date
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

database:
	g++ -c Database.cpp -I ./header

date:
	g++ -c Date.cpp -I ./boost -I ./header
