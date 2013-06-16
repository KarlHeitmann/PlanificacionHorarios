#include "TCostAsigProf.h"
#include <vector>
#include <string>


TCostAsigProf :: TCostAsigProf (int _intCodAsig) {
	intCodAsig = _intCodAsig;
}
void TCostAsigProf :: PutTCostHoraProf(TCostHoraProf CostHoraProf) {
	LCostHoraProf.push_back(CostHoraProf);
}
int TCostAsigProf :: GetCodAsig() {
	return intCodAsig;
}
std::string TCostAsigProf::Show() {
	std::string strDisplay="";
	for (int i=0; i< LCostHoraProf.size(); i++) {
		strDisplay+=LCostHoraProf[i].GetHorario() + "\n";
	}

	return strDisplay;	
}


