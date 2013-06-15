
#ifndef T_COST_ASIG_PROF_H
#define T_COST_ASIG_PROF_H

#include <vector>
#include "TCostHoraProf.h"
class TCostAsigProf {
	private:
		//TODO Cambiar a const int
		int intCodAsig;
		std::vector<TCostHoraProf> LCostHoraProf;
	public:
		TCostAsigProf(int);
		void PutTCostHoraProf(TCostHoraProf);
		int GetCodAsig();
};

#endif

