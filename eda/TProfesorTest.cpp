#include <string>
#include <vector>
#include <iostream>
#include "TProfesor.h"

int main (int argc, char **argv) {

	TProfesor Profesor("Heitmann", 1); 
	//TCostHoraProf *pCostHoraProf;
	
	std::string strTemp="";

	TCostAsigProf CostAsigProf(69);	
	CostAsigProf.GenAddCostHoraProf("M1", 2);
	CostAsigProf.GenAddCostHoraProf("M2", 1);
	CostAsigProf.GenAddCostHoraProf("M3", 0);
	CostAsigProf.GenAddCostHoraProf("J1", 2);
	CostAsigProf.GenAddCostHoraProf("J2", 0);
	CostAsigProf.GenAddCostHoraProf("J3", 1);
	CostAsigProf.GenAddCostHoraProf("V1", 2);
	CostAsigProf.GenAddCostHoraProf("V2", 1);
	CostAsigProf.GenAddCostHoraProf("V3", 0);
	Profesor.PutCostAsigProf(CostAsigProf);

	strTemp=Profesor.GetSummary();
	
	std::cout << strTemp ;

	return 0;

}


