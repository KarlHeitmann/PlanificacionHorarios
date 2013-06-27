#include <AlgoritmoEvolutivo.h>


int main (int argc, char **argv) {
	//                    TamPob, N_Generaciones, ProbDeCruce
	AlgoritmoEvolutivo AE(10, 2, 0.5);
	AE.Run();
	return 0;
}


