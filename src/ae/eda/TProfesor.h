#ifndef TPROFESOR_H
#define TPROFESOR_H

#include <string>
#include <vector>
#include "TCostAsigProf.h"

class TProfesor {
	private:
		std::string strNombre;
		int intCodigo;
		std::vector<TCostAsigProf> LCostAsigProf;
	public:
		TProfesor(std::string, int);
		TProfesor(const char*, int);
		void PutCostAsigProf(TCostAsigProf);
		std::string GetSummary();
		int GetCodProf();
		std::string GetNombre();
};

#endif
