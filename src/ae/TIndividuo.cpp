
//#include "TGen.h"
#include "TIndividuo.h"
#include <iostream>
//#include <string>
TIndividuo::TIndividuo() {
	floatAdaptacion=0.0;
	floatPuntuacion=0.0;
	floatPuntAcu=0.0;
}
TIndividuo::TIndividuo(float _floatAdaptacion, float _floatPuntuacion, float _floatPuntAcu) {
	floatAdaptacion=_floatAdaptacion;
	floatPuntuacion=_floatPuntuacion;
	floatPuntAcu=_floatPuntAcu;
}
void TIndividuo::GenerarGenotipo() {
	;
}
void        TIndividuo::Display() {
	std::cout << floatAdaptacion <<"\n";
	std::cout << floatPuntuacion <<"\n";
	std::cout << floatPuntAcu    <<"\n";
}