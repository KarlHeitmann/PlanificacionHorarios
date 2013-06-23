
#include <ncurses.h>

#include "CMainWindow.h"

CMainWindow :: CMainWindow () {
	initscr();
	//printw("Hello World !!!");

}
void CMainWindow :: Welcome () {
	printw("Hello World !!!");
	refresh();
	getch();
	endwin();
}
