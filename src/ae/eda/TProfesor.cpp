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
unsigned TProfesor::FindAsigPos(int intSearchTerm){
	unsigned uintIndex=0;
	for (unsigned i=0; i<LCostAsigProf.size(); i++) {
		if (LCostAsigProf[i].GetCodAsig() == intSearchTerm) {
			uintIndex=i;
			return uintIndex;
		}
	}
	return (unsigned) 0;
}
std::string TProfesor::GetSummary() {
	std::string strTemp="Profesor: " + strNombre + "\n";
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

unsigned TProfesor::EscogeHorarioDisplonibleDeAsignatura(unsigned pos) {
	return LCostAsigProf[pos].ChooseHorario();
}

