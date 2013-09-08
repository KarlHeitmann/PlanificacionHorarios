#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <string>
class CMainWindow {
	public:
		CMainWindow();

		void Welcome(void );
	private:
		int max_row, max_col;
		std::string Account;

};

#endif

