#ifndef SCREEN_H
#define SCREEN_H

class screen
{
    public:
        screen(int width, int height);
        ~screen();
		int init();
        void setCharacterAt(int x, int y, char character);
        char getCharacterAt(int x, int y);
        void draw();
        void clear(char space);
        void print(char* string, int length);
	int getTypedCharacter();
    private:
        char** grid;
        int width;
        int height;
        char* debug;
        int debuglength;
}
;

#endif
