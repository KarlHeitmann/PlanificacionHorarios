#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "TIndividuo.h"
#include "CandidatoHorario.h"
#include "TGen.h"
#include "eda/TCostHoraProf.h"
#define IND_VERBOSE 0
#define RND (float)rand()/(float)RAND_MAX
CandidatoHorario::CandidatoHorario():TIndividuo() {
	srand(time(NULL));	
}

void CandidatoHorario::ActualizarAdaptacion() {
	floatAdaptacion=0;
	//Calculo de adaptacion basico
	for (unsigned i=0; i<Cromosoma.size(); i++) {
		floatAdaptacion+=(float) Cromosoma[i].GetCoste();
#if IND_VERBOSE
		std::cout << "Contenido del cromosoma\n";
		std::cout << "Cromosoma: " << i <<"\n";
		std::cout << "Codigo asignatura: " << Cromosoma[i].GetCodAsig() <<"\n";
		std::cout << "Coste: " << Cromosoma[i].GetCoste() <<"\n";
		std::cout << "Horario: " << Cromosoma[i].GetHorario() <<"\n";
#endif
	}
#if IND_VERBOSE
	std::cout << "Adaptacion del Individuo: " << floatAdaptacion << "\n";
#endif
	
}

void CandidatoHorario::Display() {
	TIndividuo::Display();
	std::cout << "Soy un candidato\n";
}
int CandidatoHorario::ChooseHorario(int intSize) {
	return 0;
}
void CandidatoHorario::GenerarGenotipo(std::vector<TAula> *pvAulas, 
		std::vector<TProfesor> *pvProfesores, std::vector<TAsignatura> *pvAsignaturas) {
	unsigned uintPosProf;
	unsigned uintPosAsig;
	int intCodAsig;
	TGen *pGen;
	TCostHoraProf *pCostHoraProf;
	for (unsigned i=0; i<pvAsignaturas->size(); i++) {
		//Posicion del profesor lo saca del atributo del objeto TAsignatura
		uintPosProf = (unsigned) (*pvAsignaturas)[i].GetPosProf();
		//Codigo de asignatura lo saca del att del objeto TAsignatura
		intCodAsig = (*pvAsignaturas)[i].GetCodigo();
		//Con complejidad O(n), busca la posicion de la asignatura dentro de las 
		//asignaturas impartidas por el profesor
		uintPosAsig = (*pvProfesores)[uintPosProf].FindAsigPos(intCodAsig);
		
		//pCostHoraProf almacena una hora aleatoria dentro de las horas
		//disponibles para la asignatura
		//uintEleccion = (*pvProfesores)[uintPosProf].EscogeHorarioDisplonibleDeAsignatura(uintPosAsig);
		pCostHoraProf = (*pvProfesores)[uintPosProf].EscogeCostHoraProf(uintPosAsig);
		//              CodAsig, Coste, NombreHorario
		//pGen = new TGen(intCodAsig,(int) uintEleccion, "asd");
		pGen = new TGen(intCodAsig, pCostHoraProf->GetCoste(), pCostHoraProf->GetHorario());
		Cromosoma.push_back(*pGen);
		delete pGen;
#if IND_VERBOSE > 0
		std::cout << "________________________________________________________\n";
		std::cout << "Horarios disponibles del profesor " << (*pvProfesores)[uintPosProf].GetNombre()<<"\n";
		std::cout << "Asignatura: " << intCodAsig << "\n";
		std::cout << "Posicion de la asignatura dentro del profesor: " << uintPosAsig << "\n";
		std::cout << "Cantidad de horarios disponibles: " << uintEleccion << "\n";
#endif
	}
	ActualizarAdaptacion();
	
}
void CandidatoHorario::ReproducirA(std::vector<TGen> Pareja) {
	;//unsigned uintPuntoCruce = ;
	//for (unsigned i=0; );
}

void CandidatoHorario::ReproducirB(std::vector<TGen> Pareja) {
	;
}

void CandidatoHorario::ReproducirA(std::vector<TGen> Pareja, unsigned uintPuntoCruce) {
	//Este tipo de reproduccion reemplaza a los padres, no importa como resulte
	//el individuo hijo
	for (unsigned i=0; i<uintPuntoCruce; i++) {
		Cromosoma[i]=Pareja[i];
	}
	ActualizarAdaptacion();
}

void CandidatoHorario::ReproducirB(std::vector<TGen> Pareja, unsigned uintPuntoCruce) {
	//std::cout << "Reproduciendo!\n";
	for (unsigned i=uintPuntoCruce; i<Pareja.size(); i++) {
		Cromosoma[i]=Pareja[i];
	}
	ActualizarAdaptacion();
	
}
void CandidatoHorario::Mutar(float floatTasaDeMutacion, std::vector<TAula> *pvAulas,
		std::vector<TProfesor> *pvProfesores, std::vector<TAsignatura> *pvAsignaturas) {
	//std::cout << "Mutando...\n";
	//bool HaMutado=false;
	float floatRollDice;
	unsigned uintPosProf; int intCodAsig; unsigned uintPosAsig;
	TCostHoraProf *pCostHoraProf;
	TGen *pGen;
	for (unsigned i=0; i<Cromosoma.size(); i++) {
		//floatRollDice=(unsigned) rand() % Cromosoma.size();
		floatRollDice=RND;
		if (floatRollDice <= floatTasaDeMutacion) {
			//std::cout << "Adaptacion antes de mutar: " << floatAdaptacion <<"\n";
			uintPosProf = (unsigned) (*pvAsignaturas)[i].GetPosProf();
			intCodAsig = (*pvAsignaturas)[i].GetCodigo();
			uintPosAsig = (*pvProfesores)[uintPosProf].FindAsigPos(intCodAsig);
			pCostHoraProf = (*pvProfesores)[uintPosProf].EscogeCostHoraProf(uintPosAsig);
			pGen = new TGen(intCodAsig, pCostHoraProf->GetCoste(), pCostHoraProf->GetHorario());
			Cromosoma[i]=*pGen;
			delete pGen;
			ActualizarAdaptacion();
			//std::cout << "Muto!\n"; 
			//std::cout << "Adaptacion despues de mutar: " << floatAdaptacion <<"\n>>>>>>><<<<<<<\n";
			break;
		}
	}
}
