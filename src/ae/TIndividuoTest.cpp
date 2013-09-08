#include <time.h>
#include <stdlib.h>
#include <stdio.h>
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
	srand(time(NULL));
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
	pCH=new CandidatoHorario;
	//pCH->Display();
	pCH->GenerarGenotipo();
	
#endif
#if GENERADOR_INDIVIDUOS > 0
	GeneradorDatos DataGen;
	//std::cout << "Prueba de metodos\n";
	std::vector<TAula> *pvAulas;
	pvAulas=DataGen.VectorTAula();
	std::vector<TProfesor> *pvProfesores;
	pvProfesores=DataGen.VectorTProfesor();
	std::vector<TAsignatura> * pvAsignaturas;
	pvAsignaturas=DataGen.VectorTAsignatura();	
#if 0
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
#if 1
	//DataGen.VectorTAula();
	TIndividuo *pCandidatoHorario;
	pCandidatoHorario=new CandidatoHorario;
	pCandidatoHorario->GenerarGenotipo(pvAulas, pvProfesores, pvAsignaturas);
#endif
#endif
	return 0;
}

