#include <iostream>
#include <vector>
#include "TIndividuo.h"
#include "CandidatoHorario.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"
/////////////////////////////////////
//                                 //
// MACROS DEFINEN PRUEBAS A CORRER //
//                                 //
#define TINDIVIDUO_SIMPLE 0
#define TINDIVIDUO_HEREDADO_EN_CANDIDATO 1
#define HERENCIA_CANDIDATO_VECTOR_ARREGLO 0
#define SUBCARPETA_TEST 1

int main (int argc, char **argv) {

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
#if SUBCARPETA_TEST > 0
	std::vector<TAula> vAulas;
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

	vAulas.push_back(*pAula);
	
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

	vAulas.push_back(*pAula);
	for (unsigned i=0; i< vAulas.size(); i++)
		std::cout << vAulas[i].GetSummary();
	std::cout << "----------TProfesor---------\n";
	TProfesor Profesor("Heitmann", 1); 
	TCostHoraProf *pCostHoraProf;
	
	std::string strTemp="";

	TCostAsigProf *pCostAsigProf;
	pCostAsigProf=new TCostAsigProf(69);	
	pCostAsigProf->GenAddCostHoraProf("M1", 2);
	pCostAsigProf->GenAddCostHoraProf("M2", 1);
	pCostAsigProf->GenAddCostHoraProf("M3", 0);
	pCostAsigProf->GenAddCostHoraProf("J1", 2);
	pCostAsigProf->GenAddCostHoraProf("J2", 0);
	pCostAsigProf->GenAddCostHoraProf("J3", 1);
	pCostAsigProf->GenAddCostHoraProf("V1", 2);
	pCostAsigProf->GenAddCostHoraProf("V2", 1);
	pCostAsigProf->GenAddCostHoraProf("V3", 0);
	Profesor.PutCostAsigProf(*pCostAsigProf);
	
	pCostAsigProf=new TCostAsigProf(79);	
	pCostAsigProf->GenAddCostHoraProf("L1", 2);
	pCostAsigProf->GenAddCostHoraProf("L2", 1);
	pCostAsigProf->GenAddCostHoraProf("L3", 0);
	pCostAsigProf->GenAddCostHoraProf("M1", 2);
	pCostAsigProf->GenAddCostHoraProf("M2", 0);
	pCostAsigProf->GenAddCostHoraProf("M3", 1);
	pCostAsigProf->GenAddCostHoraProf("S1", 2);
	pCostAsigProf->GenAddCostHoraProf("S2", 1);
	pCostAsigProf->GenAddCostHoraProf("S3", 0);
	Profesor.PutCostAsigProf(*pCostAsigProf);

	strTemp=Profesor.GetSummary();
	
	std::cout << strTemp ;
#endif

#if HERENCIA_CANDIDATO_VECTOR_ARREGLO > 0
	TIndividuo *pCH;
	
#endif
	return 0;
}

