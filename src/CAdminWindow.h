#ifndef __CADMIN_WINDOW__
#define __CADMIN_WINDOW__
#include "CUserWindow.h"
#include "ae/AlgoritmoEvolutivo.h"
class CAdminWindow: public CUserWindow {
	public:
		CAdminWindow(int, int);//{CUserWindow::max_row=r; CUserWindow::max_col=c;}
		~CAdminWindow();
		virtual void Start(void);
	private:
		
		AlgoritmoEvolutivo *pAE;
		int max_row;
		int max_col;
};
#endif
