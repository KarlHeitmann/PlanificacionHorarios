#include <ncurses.h>
#include "ae/AlgoritmoEvolutivo.h"
#include "CUserWindow.h"
#include "CAdminWindow.h"
CAdminWindow::CAdminWindow (int r, int c)  {
	max_row=r;
	max_col=c;
}
void CAdminWindow::Start () {
	printw("Soy el admin empezando!");
}
CAdminWindow::~CAdminWindow() {
	delete pAE;
}
