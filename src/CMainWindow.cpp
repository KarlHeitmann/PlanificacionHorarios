
#include <ncurses.h>

#include "CMainWindow.h"
#define ROOT "root"
#define PASS "hackme"
#define HALF_ROW max_row / 2
#define HALF_COL max_col / 2

CMainWindow :: CMainWindow () {
	initscr();
	getmaxyx(stdscr,max_row,max_col);

	char AccountTmp[10];
	char Tmp[20];
	std::string PasswordTmp;
	mvprintw(HALF_ROW, HALF_COL-8, "Algoritmo Evolutivo.");
	mvprintw(HALF_ROW+1, HALF_COL-11, "Planificación de Horarios.");
	
	mvprintw(HALF_ROW+3,HALF_COL-5, "Account: ");
	mvprintw(HALF_ROW+4,HALF_COL-5, "Password: ");
	
	move(HALF_ROW+3, HALF_COL+5);
	getstr(AccountTmp);
	move(HALF_ROW+4, HALF_COL+5);
	noecho();
	getstr(Tmp);
	echo();
	
	refresh();
	Account=AccountTmp;
	PasswordTmp=Tmp;
	clear();
	if ((PasswordTmp == PASS) && (Account == ROOT)) {
		mvprintw(HALF_ROW, HALF_COL-7, "Bienvenido Jefe!");

	} else {
		mvprintw(HALF_ROW, HALF_COL-15, "Login de profes en construccion...");
	}

	refresh();
	getch();
	endwin();

}
void CMainWindow :: MainMenu () {
	
}
