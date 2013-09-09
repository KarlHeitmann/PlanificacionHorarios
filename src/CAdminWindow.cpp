#include <ncurses.h>
#include <string>
#include <stdlib.h>
#include "ae/AlgoritmoEvolutivo.h"
#include "CUserWindow.h"
#include "CAdminWindow.h"
#include "CMainWindow.h"
#include "Misc.h"

#define PEDIR_PARAMETROS_ENABLE 1
#define HALF_ROW max_row / 2
#define HALF_COL max_col / 2

CAdminWindow::CAdminWindow (CMainWindow * _pMW, int r, int c)  {
	pMW = _pMW;
	max_row=r;
	max_col=c;
}
void CAdminWindow::PedirParametros () {
	//En este metodo se piden los parametros para el algoritmo evolutivo
	char chrTemp[10];
	std::string strTemp;
	unsigned uintPoblacion, uintNGeneraciones;
	float floatProbabilidaDeCruce, floatTasaDeMutacion;
	clear();
	curs_set(2);
#if PEDIR_PARAMETROS_ENABLE > 0
	mvprintw(1, 2, "Definicion de parámetros para el algoritmo");
	mvprintw(3, 1, "Tamaño de la población:");
	mvprintw(4, 1, "Número de generaciones:");
	mvprintw(5, 1, "Probabilidad de cruce_:");
	mvprintw(6, 1, "Tasa de mutacion______:");
	//TODO Usar restricciones (Pedir a usuario que ingrese parámetros válidos)
	move(3, 1+26);
	getstr(chrTemp); strTemp=chrTemp;
	uintPoblacion = FromString<uint> (strTemp);

	move(4, 1+26);
	getstr(chrTemp); strTemp=chrTemp; 
	uintNGeneraciones = FromString<uint> (strTemp);
	move(5, 1+26);
	getstr(chrTemp); strTemp=chrTemp; 
	floatProbabilidaDeCruce = FromString<float> (strTemp);
	move(6, 1+26);
	getstr(chrTemp); strTemp=chrTemp;
   	floatTasaDeMutacion = FromString<float> (strTemp);

#else
	uintPoblacion = 10
	move(4, 1+24);
	uintNGeneraciones = 20
	move(5, 1+24);
	floatProbabilidaDeCruce = 0.5
	move(6, 1+24);
	floatTasaDeMutacion = 0.01
#endif
	
	strTemp = ToString(floatTasaDeMutacion);
	mvprintw(8, 1, "Tasa mutacion: ");
	mvprintw(8, 26, strTemp.c_str());
	strTemp = ToString(floatProbabilidaDeCruce);
	mvprintw(9, 1, "Probabilidad de cruce: ");
	mvprintw(9, 26, strTemp.c_str());
	strTemp = ToString(uintNGeneraciones);
	mvprintw(10, 1, "Número de generaciones: ");
	mvprintw(10, 26, strTemp.c_str());
	strTemp = ToString(uintPoblacion);
	mvprintw(11, 1, "Tamaño de población: ");
	mvprintw(11, 27, strTemp.c_str());
	curs_set(0);
	pAE = new AlgoritmoEvolutivo(uintPoblacion, uintNGeneraciones, floatProbabilidaDeCruce, floatTasaDeMutacion);

	getch();
}
CAdminWindow::~CAdminWindow() {
	delete pAE;
}
