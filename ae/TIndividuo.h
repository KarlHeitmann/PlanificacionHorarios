#ifndef TINDIVIDUO_H
#define TINDIVIDUO_H

#include <vector>
#include <string>
//#include "TGen.h"

class TIndividuo {
	private:
		//std::vector<TGen> vGenes();
		float floatAdaptacion;
		float floatPuntuacion;
		float floatPuntAcu;
	public:
		TIndividuo();
		TIndividuo(float, float, float);
		void Display(void);
		virtual void GenerarGenotipo(void);
};

#endif

