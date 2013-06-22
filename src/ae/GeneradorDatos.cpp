#include <vector>
#include <string>
#include <iostream>
#include "eda/TAula.h"
#include "eda/TProfesor.h"
#include "eda/TAsignatura.h"
#include "eda/TCostAsigProf.h"
#include "eda/TCostHoraProf.h"
#include "GeneradorDatos.h"

GeneradorDatos::GeneradorDatos() {
	;
}
TCostAsigProf *GeneradorDatos::GenpCostAsigProf(std::string nombre, int intCod, int intSize) {
	TCostAsigProf *pCostAsigProf;
	std::string temp;
	char id='0';
	pCostAsigProf = new TCostAsigProf(intCod);
	for (int i=0; i<intSize; i++) {
		temp = nombre + ' ' + id;
		id++;
		pCostAsigProf->GenAddCostHoraProf(temp, i);
	}

	return pCostAsigProf;

}	
std::vector<TProfesor> *GeneradorDatos::VectorTProfesor() {
	//std::cout << "----------TProfesor---------\n";
	std::vector<TProfesor> *pvProfesores;
	pvProfesores=new std::vector<TProfesor>();

	TProfesor *pProfesor;
	pProfesor = new TProfesor("Heitmann", 1); 

	TCostHoraProf *pCostHoraProf;
	
	std::string strTemp="";

	TCostAsigProf *pCostAsigProf;
	pCostAsigProf=GenpCostAsigProf("MI", 69, 5);
	pProfesor->PutCostAsigProf(*pCostAsigProf);
	
	pCostAsigProf=GenpCostAsigProf("JU", 79, 4);
	pProfesor->PutCostAsigProf(*pCostAsigProf);

	pvProfesores->push_back(*pProfesor);
	//strTemp=Profesor.GetSummary();
	
	//std::cout << strTemp ;
	return pvProfesores;	
}
std::vector<TAula> *GeneradorDatos::VectorTAula() {
	std::vector<TAula> *pvAulas;
	pvAulas = new std::vector<TAula>();
	//pvAulas=new std::vector<TAula>();
	TAula *pAula;
	pAula = new TAula("B201");
	pAula->PutStrHorario("L1");
	pAula->PutStrHorario("L2");
	pAula->PutStrHorario("L3");
	pAula->PutStrHorario("M1");
	pAula->PutStrHorario("M2");
	pAula->PutStrHorario("M3");
	pAula->PutStrHorario("S1");
	pAula->PutStrHorario("S2");
	pAula->PutStrHorario("S3");

	pvAulas->push_back(*pAula);
	
	pAula=new TAula("B225");
	pAula->PutStrHorario("M1");
	pAula->PutStrHorario("M2");
	pAula->PutStrHorario("M3");
	pAula->PutStrHorario("J1");
	pAula->PutStrHorario("J2");
	pAula->PutStrHorario("J3");
	pAula->PutStrHorario("V1");
	pAula->PutStrHorario("V2");
	pAula->PutStrHorario("V3");

	pvAulas->push_back(*pAula);
	/*
	for (unsigned i=0; i< pvAulas->size(); i++){
		std::cout << (*pvAulas)[i].GetSummary();
	}
	*/
	//std::cout << (*pvAulas)[0].GetSummary();
	return pvAulas;
}




