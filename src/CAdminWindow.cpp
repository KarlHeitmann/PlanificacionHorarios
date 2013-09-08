#include <ncurses.h>
#include <string>
#include <stdlib.h>
#include "ae/AlgoritmoEvolutivo.h"
#include "CUserWindow.h"
#include "CAdminWindow.h"
#define HALF_ROW max_row / 2
#define HALF_COL max_col / 2
CAdminWindow::CAdminWindow (int r, int c)  {
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
	
	mvprintw(1, 2, "Definicion de parámetros para el algoritmo");
	mvprintw(3, 1, "Tamaño de la población: ");
	mvprintw(4, 1, "Número de Generaciones: ");
	mvprintw(5, 1, "Probabilidad de cruce_: ");
	mvprintw(6, 1, "Tasa de mutacion______: ");
	//TODO Usar restricciones (Pedir a usuario que ingrese parámetros válidos)
	move(3, 1+24);
	getstr(chrTemp); uintPoblacion = (uint) atoi(chrTemp);
	move(4, 1+24);
	getstr(chrTemp); uintNGeneraciones = (uint) atoi(chrTemp);
	move(5, 1+24);
	getstr(chrTemp); floatProbabilidaDeCruce = (float) atof(chrTemp);
	move(6, 1+24);
	getstr(chrTemp); floatTasaDeMutacion = (float) atof(chrTemp);

	getch();
}
CAdminWindow::~CAdminWindow() {
	delete pAE;
}
