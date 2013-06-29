#include <AlgoritmoEvolutivo.h>


int main (int argc, char **argv) {
	//                    TamPob, N_Generaciones, ProbDeCruce
	AlgoritmoEvolutivo AE(10, 9, 0.5, 0.01);
	AE.Run();
	return 0;
}


