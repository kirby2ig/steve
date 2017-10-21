#TODO create makefile
CC=g++
LINK=-lncurses
steve: main.o game.o entity.o screen.o
	$(CC) -o steve main.o game.o entity.o screen.o $(LINK)
main.o: main.cpp game.h screen.h
	$(CC) -c main.cpp $(LINK)
game.o: game.cpp game.h screen.h
	$(CC) -c game.cpp $(LINK)
entity.o: entity.cpp entity.h screen.h
	$(CC) -c entity.cpp $(LINK)
screen.o: screen.cpp screen.h
	$(CC) -c screen.cpp $(LINK)
clean:
	rm *.o steve
