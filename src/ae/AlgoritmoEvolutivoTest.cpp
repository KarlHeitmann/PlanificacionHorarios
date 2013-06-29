#include <AlgoritmoEvolutivo.h>


int main (int argc, char **argv) {
	//                    TamPob, N_Generaciones, ProbDeCruce
	AlgoritmoEvolutivo AE(10, 9, 0.5, 0.01);
	//AE.Run();
	for (unsigned i=0; i<9; i++) {
		AE.Log();
		AE.Seleccion();
		AE.Reproduccion();
		AE.Mutacion();
		AE.Evaluacion();
	}
	AE.Log();
	return 0;
}


