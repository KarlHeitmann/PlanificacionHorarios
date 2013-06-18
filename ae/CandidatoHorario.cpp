#include <iostream>
#include <vector>
#include "TIndividuo.h"
#include "CandidatoHorario.h"
#include "TGen.h"

CandidatoHorario::CandidatoHorario():TIndividuo() {
	;
}
void CandidatoHorario::Display() {
	TIndividuo::Display();
	std::cout << "Soy un candidato";
}
void CandidatoHorario::GenerarGenotipo() {
	int i;
	TGen Gen(1, 69, "foo");
	i=Gen.GetCoste();
#if 0
	int largo=3;
	TGen *pGen;
	for (unsigned i=0; i<largo;i++) {
		pGen=new TGen(1, i, "L"+i);
		vGenes.push_back(*pGen);
	}	
#endif

	std::cout << "Esta es el metodo virtual GenerarGenotipo";
}


