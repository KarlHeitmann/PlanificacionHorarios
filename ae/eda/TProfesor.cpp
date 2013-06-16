#include <string>
#include <vector>
#include "TProfesor.h"

TProfesor::TProfesor(std::string _strNombre, int _intCodigo) {
	intCodigo = _intCodigo;
	strNombre = _strNombre;
}
TProfesor::TProfesor(const char* _pchrNombre, int _intCodigo) {
	intCodigo = _intCodigo;
	strNombre = _pchrNombre;
}
void TProfesor::PutCostAsigProf (TCostAsigProf CostAsigProf) {
	LCostAsigProf.push_back(CostAsigProf);
}
std::string TProfesor::GetSummary() {
	std::string strTemp="";
	for (unsigned i=0; i<LCostAsigProf.size(); i++) {
		strTemp+=LCostAsigProf[i].Show()+"\n";
	}
	return strTemp;
}	
int TProfesor::GetCodProf() {
	return intCodigo;
}
std::string TProfesor::GetNombre() {
	return strNombre;
}


