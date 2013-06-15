#include "TCostAsigProf.h"
#include <vector>

TCostAsigProf :: TCostAsigProf (int _intCodAsig) {
	intCodAsig = _intCodAsig;
}
void TCostAsigProf :: PutTCostHoraProf(TCostHoraProf CostHoraProf) {
	LCostHoraProf.push_back(CostHoraProf);
}
int TCostAsigProf :: GetCodAsig() {
	return intCodAsig;
}


