#include <iostream>
#include "TIndividuo.h"
#include "CandidatoHorario.h"

CandidatoHorario::CandidatoHorario():TIndividuo() {
	;
}
void CandidatoHorario::Display() {
	TIndividuo::Display();
	std::cout << "Soy un candidato";
}
void CandidatoHorario::GenerarGenotipo() {
	std::cout << "Esta es el metodo virtual GenerarGenotipo";
}


