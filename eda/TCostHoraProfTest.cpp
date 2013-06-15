#include <iostream>
#include "TCostHoraProf.h"
#include <vector>

using namespace std;

int main (int argc, char **argv) {
	std::vector<TCostHoraProf> LCostHoraProf;
	const char *pchrtemp[argc];
	for (int i=0; i< argc; i++) {
		LCostHoraProf.push_back( TCostHoraProf(argv[i], i) );
	}
	for (unsigned i=1; i< argc; i++) {
		//cout << "Hola";
		pchrtemp[i]=LCostHoraProf[i].GetHorario();
		cout << i << " Horario: " << LCostHoraProf[i].GetHorario() << "\tCoste: " << LCostHoraProf[i].GetCoste() << "\n";
	}	
	for (unsigned i=1; i< (argc-0); i++)
		cout << i <<" Horario: " << pchrtemp[i] << "\n";
}

