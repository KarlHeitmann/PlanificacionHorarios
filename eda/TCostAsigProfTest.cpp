#include "TCostAsigProf.h"
#include "TCostHoraProf.h"
#include <vector>
#include <iostream>

int main (int argc, char **argv) {
	TCostHoraProf *pCostHoraProf;
	std::vector<TCostAsigProf> LCostAsigProf;
	for (int i=0; i<argc; i++) {
		LCostAsigProf.push_back( TCostAsigProf(i*5) );
		pCostHoraProf=new TCostHoraProf(argv[i],i);
		LCostAsigProf[(unsigned) i].PutTCostHoraProf(*pCostHoraProf);
	}

	for (unsigned i=0; i<argc; i++) 
		std::cout << i << " Codigo Asignatura: " << LCostAsigProf[i].GetCodAsig() << "\n";

}



