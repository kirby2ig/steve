#ifndef SCREEN_H
#define SCREEN_H

#include "string.h"

class screen
{
    public:
        screen(int width, int height);
        ~screen();
		int init();
        void setCharacterAt(int x, int y, char character);
        char getCharacterAt(int x, int y);
        void draw();
        void printText(char* text, int length, int x, int y);
        void clear(char space);
        void print(char* string, int length);
	int getTypedCharacter();
    private:
        char** grid;
        int width;
        int height;
}
;

#endif
