#include <vector>
#include <iostream>
#include "AlgoritmoEvolutivo.h"
#include "TIndividuo.h"
#include "CandidatoHorario.h"
#include "GeneradorDatos.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"
#define AE_VERBOSE 0
AlgoritmoEvolutivo::AlgoritmoEvolutivo(unsigned _uintPoblacion) {
	GeneradorDatos DataGen;
	pvAulas = DataGen.VectorTAula();
	pvAsignaturas = DataGen.VectorTAsignatura();
	pvProfesores = DataGen.VectorTProfesor();
	uintPoblacion = _uintPoblacion;
}

void AlgoritmoEvolutivo::Run() {
	pvIndividuos = new std::vector<TIndividuo>();	
	TIndividuo *pCH;
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH=new CandidatoHorario;
		pCH->GenerarGenotipo(pvAulas, pvProfesores, pvAsignaturas);
		std::cout << "__________________________\nIndividuo: " << i <<"\nAdaptacion: " << pCH->floatAdaptacion << "\n";
		pvIndividuos->push_back(*pCH);
		delete pCH;
	}	
#if AE_VERBOSE > 0
	std::cout << "---Recorriendo vector Aulas---\n";
	for (unsigned i=0; i<pvAulas->size(); i++) {
		std::cout << (*pvAulas)[i].GetSummary();
	}
	std::cout << "---Recorriendo vector Profesores---\n";
	for (unsigned i=0; i<pvProfesores->size(); i++) {
		std::cout << (*pvProfesores)[i].GetSummary();
	}
	std::cout << "---Recorriendo vector Asignaturas---\n";
	for (unsigned i=0; i<pvAsignaturas->size(); i++) {
		std::cout << (*pvAsignaturas)[i].GetNombre() << "\n";
	}
#endif
}
