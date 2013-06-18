
//#include "TGen.h"
#include "TIndividuo.h"
#include <iostream>
TIndividuo::TIndividuo() {
#if 1
	floatAdaptacion=0.0;
	floatPuntuacion=0.0;
	floatPuntAcu=0.0;
#endif
#if 0
	floatAdaptacion=4.0;
	floatPuntuacion=2.2;
	floatPuntAcu=10.0;
#endif
}
TIndividuo::TIndividuo(float _floatAdaptacion, float _floatPuntuacion, float _floatPuntAcu) {
	floatAdaptacion=_floatAdaptacion;
	floatPuntuacion=_floatPuntuacion;
	floatPuntAcu=_floatPuntAcu;
}

void        TIndividuo::Display() {
	std::cout << floatAdaptacion <<"\n";
	std::cout << floatPuntuacion <<"\n";
	std::cout << floatPuntAcu    <<"\n";
}
