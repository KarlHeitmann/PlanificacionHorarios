#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <string>
#include "CUserWindow.h"
class CMainWindow {
	public:
		CMainWindow();
		CUserWindow * MainMenu(void );
		void Finish(void);
	private:
		int max_row, max_col;
		std::string Account;

};

#endif

