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
}

