#include <iostream>
#include "TCostHoraProf.h"
#include <vector>

using namespace std;

int main (int argc, char **argv) {
	int i;
	std::vector<TCostHoraProf> LCostHoraProf;
	//TCostHoraProf CostHoraProf[argc];
	for (i=0; i< argc; i++) {
		LCostHoraProf.push_back( TCostHoraProf(argv[i], i) );
	}
	
}

