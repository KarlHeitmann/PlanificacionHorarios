#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "TCostAsigProf.h"
#include "TCostHoraProf.h"
#include <vector>
#include <iostream>
#include <string>

int main (int argc, char *argv[]) {
	TCostHoraProf *pCostHoraProf;
	//std::vector<TCostAsigProf> LCostAsigProf;
	TCostAsigProf CostAsigProf(69);
	std::string strTemp="";

	srand(time(NULL));
	for (int i=0; i<argc; i++) {
		//LCostAsigProf.push_back( TCostAsigProf(i*5) );
		strTemp=argv[i];//+"   |";
		strTemp+="    |";
		pCostHoraProf=new TCostHoraProf(strTemp,i);

		CostAsigProf.PutCostHoraProf(*pCostHoraProf);

		//pCostHoraProf=new TCostHoraProf(argv[i],i);
		//LCostAsigProf[(unsigned) i].PutTCostHoraProf(*pCostHoraProf);
	}

		std::cout << "Codigo Asignatura: " << CostAsigProf.GetCodAsig() 
			<< "\n";
		std::cout << "Horarios disponibles:\n " << CostAsigProf.Show() << "\n";
}



