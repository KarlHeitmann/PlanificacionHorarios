#include <ncurses.h>
#include "interfaz/CMainWindow.h"
int main()
{	
#if 0
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
#endif

	CMainWindow win;
	win.Welcome();
}
 



