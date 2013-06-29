#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include <vector>
#include "TIndividuo.h"
class DataPackage {
	private:
		std::vector <TIndividuo *> *pvPoblacion;
	public:
		DataPackage(void){;}
		void AjustarPoblacion(std::vector<TIndividuo *> *pvPoblacionExaminar) {pvPoblacion=pvPoblacionExaminar;}
		void Individuos(void);
		//DataPackage(float, float, float)
		//std::vector<TGen> *Cromosoma;
		//float floatAdaptacion;
		//float floatPuntuacion;
		//float floatSumAdaptacion;
};

#endif

