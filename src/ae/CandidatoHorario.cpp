#include <iostream>
#include <stdlib.h>
#include <vector>
//#include <random>
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
int CandidatoHorario::ChooseHorario(int intSize) {
	return 0;
}
void CandidatoHorario::GenerarGenotipo(std::vector<TAula> *pvAulas, 
		std::vector<TProfesor> *pvProfesores, std::vector<TAsignatura> *pvAsignaturas) {
	unsigned uintPosProf;
	unsigned uintPosAsig;
	int intCodAsig;
	int intTamanioTemp;
	std::vector<TCostHoraProf> *pvCostHoraProf;
	
	//std::default_random_engine generator;
    //std::uniform_int_distribution<int> distribution(0,9);
    

	for (unsigned i=0; i<pvAsignaturas->size(); i++) {
		uintPosProf = (unsigned) (*pvAsignaturas)[i].GetPosProf();
		intCodAsig = (*pvAsignaturas)[i].GetCodigo();
		uintPosAsig = (*pvProfesores)[uintPosProf].FindAsigPos(intCodAsig);
		
		intTamanioTemp = (*pvProfesores)[uintPosProf].GetHorarioDisponibleDeAsignaturaSize(uintPosAsig);
		std::cout << "________________________________________________________\n";
		std::cout << "Horarios disponibles del profesor " << (*pvProfesores)[uintPosProf].GetNombre()<<"\n";
		std::cout << "Asignatura: " << intCodAsig << "\n";
		std::cout << "Posicion de la asignatura dentro del profesor: " << uintPosAsig << "\n";
		std::cout << "Cantidad de horarios disponibles: " << intTamanioTemp << "\n";
	}

#if 0
	int largo=3;
	TGen *pGen;
	for (unsigned i=0; i<largo;i++) {
		//pGen=new TGen(1, i, "L"+i);
		//pGen=new TGen(1, i, std::string("L"));
		pGen=new TGen(1, i, "L");
		vGenes.push_back(*pGen);
	}	
	
	for (unsigned i=0; i<largo; i++) {
		std::cout << "Gen: "<< i << "\n";
		std::cout << "Coste: " << vGenes[i].GetCoste()<<"\n";
		std::cout << "Codigo Asignatura: " << vGenes[i].GetCodAsig()<<"\n";
		std::cout << "Horario: " << vGenes[i].GetHorario()<<"\n";

	}

	//std::cout << "Esta es el metodo virtual GenerarGenotipo";
#endif
}


