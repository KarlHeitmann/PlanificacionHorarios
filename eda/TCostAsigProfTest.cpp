#include "TCostAsigProf.h"
#include "TCostHoraProf.h"
#include <vector>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
	TCostHoraProf *pCostHoraProf;
	std::vector<TCostAsigProf> LCostAsigProf;

	std::string strTemp="";

	for (int i=0; i<argc; i++) {
		LCostAsigProf.push_back( TCostAsigProf(i*5) );
		strTemp=argv[i];
		pCostHoraProf=new TCostHoraProf(strTemp,i);
		//pCostHoraProf=new TCostHoraProf(argv[i],i);
		LCostAsigProf[(unsigned) i].PutTCostHoraProf(*pCostHoraProf);
	}

	for (unsigned i=0; i<argc; i++) {
		std::cout << i << " Codigo Asignatura: " << LCostAsigProf[i].GetCodAsig() << "\n";
		//std::cout << " Codigo Asignatura: " << LCostAsigProf[i].GetCodAsig() << "\n";
	}
}



