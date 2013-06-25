#include <iostream>
#include <stdlib.h>
#include <vector>
//#include <random>
#include "TIndividuo.h"
#include "CandidatoHorario.h"
#include "TGen.h"
#include "eda/TCostHoraProf.h"
#define IND_VERBOSE 0
CandidatoHorario::CandidatoHorario():TIndividuo() {
	;
}
void CandidatoHorario::Display() {
	TIndividuo::Display();
	std::cout << "Soy un candidato";
}
int CandidatoHorario::ChooseHorario(int intSize) {
	return 0;
}
void CandidatoHorario::GenerarGenotipo(std::vector<TAula> *pvAulas, 
		std::vector<TProfesor> *pvProfesores, std::vector<TAsignatura> *pvAsignaturas) {
	unsigned uintPosProf;
	unsigned uintPosAsig;
	int intCodAsig;
	int intTamanioTemp;
	unsigned uintEleccion;
	std::vector<TCostHoraProf> *pvCostHoraProf;
	TGen *pGen;
	TCostHoraProf *pCostHoraProf;
	for (unsigned i=0; i<pvAsignaturas->size(); i++) {
		uintPosProf = (unsigned) (*pvAsignaturas)[i].GetPosProf();
		intCodAsig = (*pvAsignaturas)[i].GetCodigo();
		//O(n)
		uintPosAsig = (*pvProfesores)[uintPosProf].FindAsigPos(intCodAsig);
		
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


