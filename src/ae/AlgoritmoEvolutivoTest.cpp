#include <AlgoritmoEvolutivo.h>


int main (int argc, char **argv) {
	DataPackage DP;
	//                    TamPob, N_Generaciones, ProbDeCruce
	AlgoritmoEvolutivo AE(10, 9, 0.5, 0.01);
	//AE.Run();
	AE.AmarrarDP(&DP);
	for (unsigned i=0; i<2; i++) {
		std::cout << "<<<< Generacion " << i << " >>>>\n";
#if 0
		std::cout << "--->Antes de seleccion\n";
		DP.Individuos();
#endif
		//AE.Log();
		AE.Seleccion();
		AE.Reproduccion();
		AE.Mutacion();
		AE.Evaluacion();
#if 0
		std::cout << "<---Despues de seleccion\n";
		DP.Individuos();
#endif
	}
	//AE.Log();
	return 0;
}


