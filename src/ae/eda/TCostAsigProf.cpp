#include "TCostAsigProf.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
TCostAsigProf :: TCostAsigProf (int _intCodAsig) {
	intCodAsig = _intCodAsig;
}
void TCostAsigProf :: PutCostHoraProf(TCostHoraProf CostHoraProf) {
	LCostHoraProf.push_back(CostHoraProf);
}
void TCostAsigProf::GenAddCostHoraProf(std::string strHorario, int intCoste){
	TCostHoraProf CostHoraProf(strHorario, intCoste);
	LCostHoraProf.push_back(CostHoraProf);
}
void TCostAsigProf::GenAddCostHoraProf(const char* pchrHorario, int intCoste){
	TCostHoraProf CostHoraProf(pchrHorario, intCoste);
	LCostHoraProf.push_back(CostHoraProf);
}
int TCostAsigProf :: GetCodAsig() {
	return intCodAsig;
}
std::string TCostAsigProf::Show() {
	std::string strDisplay="";
	std::stringstream ss;
	//ss<<intCodAsig;
	//strDisplay=ss;
	for (int i=0; i< LCostHoraProf.size(); i++) {
		strDisplay+=LCostHoraProf[i].GetHorario() ;
		strDisplay+="-";
	}
	
	//std::cout<< "Codigo asignatura: "
	return strDisplay;	
}
int TCostAsigProf::GetHorarioDisponibleSize() {
	return LCostHoraProf.size();
}

