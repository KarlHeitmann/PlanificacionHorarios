#ifndef TINDIVIDUO_H
#define TINDIVIDUO_H

#include <vector>
#include <string>
#include "TGen.h"
#include "eda/TAsignatura.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"

class TIndividuo {
	private:
		float floatAdaptacion;
		float floatPuntuacion;
		float floatPuntAcu;
	public:
		//std::vector<TGen> vGenes;
		TIndividuo();
		TIndividuo(float, float, float);
		void Display(void);
		virtual void GenerarGenotipo(std::vector<TAula> *p1, std::vector<TProfesor> *p2, std::vector<TAsignatura> *p3);
};

#endif

