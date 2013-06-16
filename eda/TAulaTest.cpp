
#include <string>
#include <vector>
#include <iostream>
#include "TAula.h"
int main (int argc, char **argv) {
#if 0
	TAula Aula("B201");
	Aula.PutStrHorario("L1");
	Aula.PutStrHorario("L2");
	Aula.PutStrHorario("L3");
	Aula.PutStrHorario("M1");
	Aula.PutStrHorario("M2");
	Aula.PutStrHorario("M3");
	Aula.PutStrHorario("S1");
	Aula.PutStrHorario("S2");
	Aula.PutStrHorario("S3");

	std::cout << Aula.GetSummary();
	
	std::vector<TAula> vAula;

	vAula.push_back(Aula);
	TAula *pAula;

	pAula=new TAula("B201");
	pAula->PutStrHorario("L1");
	pAula->PutStrHorario("L2");
	pAula->PutStrHorario("L3");
	pAula->PutStrHorario("M1");
	pAula->PutStrHorario("M2");
	pAula->PutStrHorario("M3");
	pAula->PutStrHorario("S1");
	pAula->PutStrHorario("S2");
	pAula->PutStrHorario("S3");

	vAula.push_back(*pAula);

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

	vAula.push_back(*pAula);
#endif
#if 1
	std::vector<TAula> vAula;

	TAula *pAula;

	pAula=new TAula("B201");
	pAula->PutStrHorario("L1");
	pAula->PutStrHorario("L2");
	pAula->PutStrHorario("L3");
	pAula->PutStrHorario("M1");
	pAula->PutStrHorario("M2");
	pAula->PutStrHorario("M3");
	pAula->PutStrHorario("S1");
	pAula->PutStrHorario("S2");
	pAula->PutStrHorario("S3");

	vAula.push_back(*pAula);
	
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

	vAula.push_back(*pAula);
	for (unsigned i=0; i< vAula.size(); i++)
		std::cout << vAula[i].GetSummary();
#endif

	return 0;
}



