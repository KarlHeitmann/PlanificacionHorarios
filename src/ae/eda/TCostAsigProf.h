
#ifndef T_COST_ASIG_PROF_H
#define T_COST_ASIG_PROF_H

#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "TCostHoraProf.h"
class TCostAsigProf {
	private:
		//TODO Cambiar a const int
		int intCodAsig;
		std::vector<TCostHoraProf> LCostHoraProf;
	public:
		TCostAsigProf(int);
		void PutCostHoraProf(TCostHoraProf);
		void GenAddCostHoraProf(std::string, int);
		void GenAddCostHoraProf(const char*, int);
		//Metodos simples para mostrar
		int GetCodAsig();
		std::string Show();
		
		int GetHorarioDisponibleSize();
		unsigned ChooseHorario();
};

#endif

