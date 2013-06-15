#include "TCostAsigProf.h"
#include <vector>
#include <iostream>

int main (int argc, char **argv) {
	std::vector<TCostAsigProf> LCostAsigProf;
	for (int i=0; i<argc; i++) {
		LCostAsigProf.push_back( TCostAsigProf(i*5) );
	}

	for (unsigned i=0; i<argc; i++) 
		std::cout << i << " Codigo Asignatura: " << LCostAsigProf[i].GetCodAsig() << "\n";

}



