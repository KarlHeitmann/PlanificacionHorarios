
#include <ncurses.h>

#include "CMainWindow.h"
#include "CUserWindow.h"
#include "CAdminWindow.h"

//////////////////////
//                  //
//    PARAMETROS    //
//                  //
#define ROOT "root"
#define PASS "hackme"
#define HALF_ROW max_row / 2
#define HALF_COL max_col / 2

//////////////////////
//                  //
//   MACROS DEBUG   //
//                  //

#define SKIP_AUT 1  //Si esta seteado, se salta autenticacion y se loguea como root

CMainWindow :: CMainWindow () {
	initscr();
	getmaxyx(stdscr,max_row,max_col);


}
CUserWindow * CMainWindow :: MainMenu () {
	char AccountTmp[10];
	char Tmp[20];
	CUserWindow *pUW;
	std::string PasswordTmp;
#if SKIP_AUT > 0
	mvprintw(HALF_ROW, HALF_COL-7, "Bienvenido Jefe!");
	pUW = new CAdminWindow(max_row, max_col);
#else
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
		pUW = new CAdminWindow(max_row, max_col);
		//pUW->Start();
	} else {
		mvprintw(HALF_ROW, HALF_COL-15, "Login de profes en construccion...");
		//TODO lanzar error
		return 0;
	}
#endif
	refresh();
	getch();
	return pUW;
}
void CMainWindow::Finish() {
	endwin();
}
