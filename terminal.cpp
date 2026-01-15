#include "terminal.h"
#include <ncurses.h>
#include <string>
#include "editor.h"

WINDOW *newWindow(char *name) {

    WINDOW *nwin=newwin(1, COLS, LINES-1, 0);
    init_pair(1, COLOR_MAGENTA, COLOR_WHITE);
    wbkgd(nwin, COLOR_PAIR(1));
    mvwprintw(nwin, 0, (COLS/2)-(static_cast<int>(sizeof(name))/2) ,name);
    mvwprintw(nwin, 0, COLS-18,"OrionEditor V 0.1");
    wrefresh(nwin);
    move(0,0);

    return nwin;
}


void initialize() {
    initscr();
    raw();
    keypad(stdscr, TRUE);
    noecho();
    refresh();
    start_color();
}

void resizeWindow(WINDOW *win, char *name) {
    int y,x;
    getyx(stdscr,y,x);
    refresh();
    wclear(win);
    wbkgd(win, COLOR_PAIR(0));
    wrefresh(win);
    wresize(win,1,COLS);
    mvwin(win,LINES-1,0);
    wbkgd(win, COLOR_PAIR(1));
    mvwprintw(win, 0, COLS/2-(static_cast<int>(sizeof(name))/2), name);
    mvwprintw(win, 0, COLS-18,"OrionEditor V 0.1");
    wrefresh(win);
    move(y,x);
}


void AppInit() {

    std::string filename = "A.txt";
    filename = "File: "+filename;
    char name[(size_t) filename.length()+1];
    strcpy(name,filename.c_str());

    initialize();

    WINDOW *win=newWindow(name);
    int ch, y,x;
    bool exit=false;

    while (not exit){
        resizeWindow(win, name);
        ch=getch();
        getyx(stdscr,y,x);
        processKey(ch,y,x, exit);



        refresh();
    }
    endwin();
}



