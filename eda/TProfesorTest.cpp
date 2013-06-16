#include <string>
#include <vector>
#include <iostream>
#include "TProfesor.h"

int main (int argc, char **argv) {

	TProfesor Profesor("Heitmann", 1); 
	//TCostHoraProf *pCostHoraProf;
	
	std::string strTemp="";

	TCostAsigProf *pCostAsigProf;
	pCostAsigProf=new TCostAsigProf(69);	
	pCostAsigProf->GenAddCostHoraProf("M1", 2);
	pCostAsigProf->GenAddCostHoraProf("M2", 1);
	pCostAsigProf->GenAddCostHoraProf("M3", 0);
	pCostAsigProf->GenAddCostHoraProf("J1", 2);
	pCostAsigProf->GenAddCostHoraProf("J2", 0);
	pCostAsigProf->GenAddCostHoraProf("J3", 1);
	pCostAsigProf->GenAddCostHoraProf("V1", 2);
	pCostAsigProf->GenAddCostHoraProf("V2", 1);
	pCostAsigProf->GenAddCostHoraProf("V3", 0);
	Profesor.PutCostAsigProf(*pCostAsigProf);

	strTemp=Profesor.GetSummary();
	
	std::cout << strTemp ;

	return 0;

}


