#include <string>
#include "TCostHoraProf.h"

TCostHoraProf :: TCostHoraProf (const char *_pchrHorario, int _intCoste) {
	//this->pchrHorario=_pchrHorario;
	strHorario=_pchrHorario;
	this->intCoste=_intCoste;
}
TCostHoraProf :: TCostHoraProf (std::string _strHorario, int _intCoste) {
	//this->pchrHorario=_pchrHorario;
	strHorario=_strHorario;
	this->intCoste=_intCoste;
}
int TCostHoraProf :: GetCoste () {
	return intCoste;
}
//const char * TCostHoraProf :: GetHorario() {
//	return pchrHorario;
//}
std::string  TCostHoraProf :: GetHorario() {
	return strHorario;
}

