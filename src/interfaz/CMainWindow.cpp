
#include <ncurses.h>

#include "CMainWindow.h"

CMainWindow :: CMainWindow () {
	initscr();
	getmaxyx(stdscr,max_row,max_col);

	//printw("Hello World !!!");

}
void CMainWindow :: Welcome () {
	//move(5,5);
	//mvprintw(5, 5, "Algoritmo Evolutivo.");
	//mvprintw(6, 2, "Planificación de Horarios.");
	mvprintw(max_row/2, max_col/2, "Algoritmo Evolutivo.");
	mvprintw(max_row/2+1, max_col/2-2, "Planificación de Horarios.");
	
	refresh();
	getch();
	endwin();
}
