#include "TCostHoraProf.h"

TCostHoraProf :: TCostHoraProf (const char *_pchrHorario, int _intCoste) {
	this->pchrHorario=_pchrHorario;
	this->intCoste=_intCoste;
}
TCostHoraProf :: TCostHoraProf (const std::string _pchrHorario, int _intCoste) {
	this->pchrHorario=_pchrHorario;
	this->intCoste=_intCoste;
}
int TCostHoraProf :: GetCoste () {
	return intCoste;
}
const char * TCostHoraProf :: GetHorario() {
	return pchrHorario;
}

