CC=g++
CFLAGS=
LINK=-lncurses -lm
steve: main.o game.o player.o entity.o wall.o screen.o
	$(CC) $(CFLAGS) -o steve main.o game.o player.o wall.o entity.o screen.o $(LINK)
main.o: main.cpp game.h screen.h
	$(CC) $(CFLAGS) -c main.cpp 
game.o: game.cpp game.h screen.h player.h entity.h wall.h
	$(CC) $(CFLAGS) -c game.cpp 
player.o: player.cpp player.h entity.h screen.h game.h wall.h
	$(CC) $(CFLAGS) -c player.cpp
wall.o: wall.cpp wall.h entity.h screen.h game.h
	$(CC) $(CFLAGS) -c wall.cpp
entity.o: entity.cpp entity.h screen.h
	$(CC) $(CFLAGS) -c entity.cpp 
screen.o: screen.cpp screen.h
	$(CC) $(CFLAGS) -c screen.cpp 
clean:
	rm *.o steve
