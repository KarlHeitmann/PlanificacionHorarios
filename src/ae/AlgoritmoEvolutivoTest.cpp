#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "AlgoritmoEvolutivo.h"
#include "DataPackage.h"


int main (int argc, char **argv) {
	
	DataPackage DP;
	srand(time(NULL));
	//                    TamPob, N_Generaciones, ProbDeCruce
	AlgoritmoEvolutivo AE(10, 9, 0.5, 0.01);
	//AE.Run();
	AE.AmarrarDP(&DP);
	for (unsigned i=0; i<5; i++) {
		std::cout << "\n<<<< Generacion " << i << " >>>>\n";
#if 1
		std::cout << "--->Antes de seleccion\n";
		DP.Individuos();
		std::cout << DP;
#endif
		//AE.Log();
		AE.Seleccion();
#if 0
		std::cout << "<---Despues de seleccion\n";
		DP.Individuos();
#endif
		AE.Reproduccion();
		AE.Mutacion();
		AE.Evaluacion();
#if 1
		std::cout << "<---Despues de seleccion\n";
		DP.Individuos();
		std::cout << DP;
#endif
	}
	//AE.Log();
	return 0;
}


