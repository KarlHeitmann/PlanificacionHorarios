#include <iostream>
#include "TCostHoraProf.h"
#include <vector>

using namespace std;

int main (int argc, char **argv) {
	std::vector<TCostHoraProf> LCostHoraProf;
	//TCostHoraProf CostHoraProf[argc];
	for (int i=0; i< argc; i++) {
		LCostHoraProf.push_back( TCostHoraProf(argv[i], i) );
	}
	for (unsigned i=1; i< argc; i++) {
		//cout << "Hola";
		cout << i << " Horario: " << LCostHoraProf[i].GetHorario() << "\tCoste: " << LCostHoraProf[i].GetCoste() << "\n";
	}	
}

