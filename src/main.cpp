//#include <ncurses.h>
#include <sqlite3.h>

#include <stdio.h>
#include "CMainWindow.h"
#define TEST_SQLITE3 0
#if TEST_SQLITE3 > 0
static int callback(void *NotUsed, int argc, char **argv, char **azColName){
	int i;
	for(i=0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
#endif
      
int main(int argc, char **argv)
{	
	CUserWindow * pUW;
#if TEST_SQLITE3 > 0
	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;
    printf(argv[2]); 
	if( argc!=3 ){
		//printf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
		printf("Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
		return(1);
	}
	rc = sqlite3_open(argv[1], &db);
	if( rc ){
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return(1);
	}
	rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
	if( rc!=SQLITE_OK ){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	sqlite3_close(db);
	return 0;
#endif
#if 0
	initscr();			/* Start curses mode 		  */
	printw("Hello World !!!");	/* Print Hello World		  */
	refresh();			/* Print it on to the real screen */
	getch();			/* Wait for user input */
	endwin();			/* End curses mode		  */

	return 0;
#endif
#if 1
	CMainWindow win;
	pUW=win.MainMenu();
	
	win.Finish();
#endif
}
 



