#include <string>
#include "TGen.h"


TGen::TGen(int _intCodAsig, int _intCoste, std::string strHorario) {
	intCodAsig=_intCodAsig;
	intCoste=_intCoste;
	strHorario=strHorario;
}
int TGen::GetCoste() {
	return intCoste;
}
int TGen::GetCodAsig() {
	return intCodAsig;
}
std::string TGen::GetHorario() {
	return strHorario;
}


