#include <vector>
#include <iostream>
#include "AlgoritmoEvolutivo.h"
#include "TIndividuo.h"
#include "CandidatoHorario.h"
#include "GeneradorDatos.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"
#define AE_VERBOSE 0
AlgoritmoEvolutivo::AlgoritmoEvolutivo(unsigned _uintPoblacion, unsigned _uintNGeneraciones) {
	GeneradorDatos DataGen;
	pvAulas = DataGen.VectorTAula();
	pvAsignaturas = DataGen.VectorTAsignatura();
	pvProfesores = DataGen.VectorTProfesor();
	uintPoblacion = _uintPoblacion;
	uintNGeneraciones = _uintNGeneraciones;
	floatSumAdaptacion=0.0;
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

void AlgoritmoEvolutivo::Run() {
	pvIndividuos = new std::vector<TIndividuo>();	
	TIndividuo *pCH;
	//Genera poblacion inicial
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH=new CandidatoHorario;
		pCH->GenerarGenotipo(pvAulas, pvProfesores, pvAsignaturas);
		std::cout << "__________________________\nIndividuo: " << i <<"\nAdaptacion: " << pCH->floatAdaptacion << "\n";
		floatSumAdaptacion += pCH->GetAdaptacion();
		pvIndividuos->push_back(*pCH);
		delete pCH;
	}
	std::cout << "floatSumAdaptacion: " << floatSumAdaptacion << "\n";
	//Entra al loop de evolucion
	//Evaluacion
	Evaluacion(pvIndividuos);
	for (unsigned i=0; i<uintNGeneraciones; i++) {
		//Seleccion (Pob, paramentros) 
		//Selecciona a los supervivientes de la poblacion
		//Genera una poblacion del mismo tamanio, pero solo con individuos
		//seleccionados
		//
		//Reproduccion (Pob, tam_pob, lcrom, prob_mut)
		//Toma los individuos seleccionados y selecciona aleatoriamente parejas
		//a cruzar. Genera nueva poblacion
		//
		//Mutacion (pob, tam_pob, lcrom, prob_mut)
		//Selecciona algunos individuos de la poblacion actual y les aplica
		//pequenias mutaciones
		//
		//Evaluacion (pob, tam_pob, lcrom, prob_mut)
		//Evalua la nueva poblacion generada
		Seleccion(pvIndividuos);
	}
	
}
void AlgoritmoEvolutivo::Seleccion (std::vector<TIndividuo> *pvPoblacion) {
	for (unsigned i=0; i<uintPoblacion; i++) {
		;
	}
}
void AlgoritmoEvolutivo::Evaluacion (std::vector<TIndividuo> *pvPoblacion) {
	;
}
