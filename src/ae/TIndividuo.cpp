
//#include "TGen.h"
#include "TIndividuo.h"
#include <iostream>
//#include <string>
TIndividuo::TIndividuo() {
#if 1
	floatAdaptacion=0.0;
	floatPuntuacion=0.0;
	floatPuntAcu=0.0;
#endif
}
#if 1
TIndividuo::TIndividuo(float _floatAdaptacion, float _floatPuntuacion, float _floatPuntAcu) {
	floatAdaptacion=_floatAdaptacion;
	floatPuntuacion=_floatPuntuacion;
	floatPuntAcu=_floatPuntAcu;
}
#endif
void TIndividuo::GenerarGenotipo(std::vector<TAula> *pvAulas, 
		std::vector<TProfesor> *pvProfesores, std::vector<TAsignatura> *pvAsignaturas) {
	;
}
void        TIndividuo::Display() {
	std::cout << floatAdaptacion <<"\n";
	std::cout << floatPuntuacion <<"\n";
	std::cout << floatPuntAcu    <<"\n";
}
float TIndividuo::GetAdaptacion() {
	return floatAdaptacion;
}
