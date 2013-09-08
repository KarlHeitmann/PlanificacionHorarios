#ifndef __CADMIN_WINDOW__
#define __CADMIN_WINDOW__
#include "CUserWindow.h"
class CAdminWindow: public CUserWindow {
	public:
		CAdminWindow(int, int);//{CUserWindow::max_row=r; CUserWindow::max_col=c;}
		virtual void Start(void);
	private:
		int max_row;
		int max_col;
};
#endif
