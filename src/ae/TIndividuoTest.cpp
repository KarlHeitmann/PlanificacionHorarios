#include <iostream>
#include <vector>
#include "TIndividuo.h"
#include "CandidatoHorario.h"
#include "GeneradorDatos.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"
/////////////////////////////////////
//                                 //
// MACROS DEFINEN PRUEBAS A CORRER //
//                                 //
#define TINDIVIDUO_SIMPLE 0
#define TINDIVIDUO_HEREDADO_EN_CANDIDATO 0
#define HERENCIA_CANDIDATO_VECTOR_ARREGLO 0
#define GENERADOR_INDIVIDUOS 1
int main (int argc, char **argv) {
#if TINDIVIDUO_SIMPLE > 0
	TIndividuo Individuo(5.5, 2.5, 3.0);
	//std::cout << TIndividuo.Display();
	Individuo.Display();
	TIndividuo Indiv2;
	Indiv2.Display();
#endif
#if TINDIVIDUO_HEREDADO_EN_CANDIDATO > 0
	TIndividuo *CH;
	std::cout << "Test CandidatoHorario:\n";
	CH=new CandidatoHorario;
	//CH->Display();
	CH->GenerarGenotipo();
#endif

#if HERENCIA_CANDIDATO_VECTOR_ARREGLO > 0
	TIndividuo *pCH;
	std::cout << "Test CandidatoHorario:\n";
	CH=new CandidatoHorario;
	//CH->Display();
	CH->GenerarGenotipo();
	
#endif
#if GENERADOR_INDIVIDUOS > 0
	GeneradorDatos DataGen;
#endif
	return 0;
}

