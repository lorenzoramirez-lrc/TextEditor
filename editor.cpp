#include "editor.h"

#include <cstdlib>
#include <ncurses.h>



void processKey(int ch, int y,int x, bool &exit) {

    switch (ch) {
        case 17:
            exit=true;
            break;
        case KEY_LEFT:
            move(y,x-1);
            break;
        case KEY_RIGHT:
            move(y,x+1);
            break;
        case KEY_UP:
            move(y-1,x);
            break;
        case KEY_DOWN:
            move(y+1,x);
             break;
        case KEY_BACKSPACE:
            break;
        default:
            printw("%c",ch);
            break;
    }
}


