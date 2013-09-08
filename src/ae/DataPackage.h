#ifndef DATA_PACKAGE_H
#define DATA_PACKAGE_H

#include <vector>
#include <ostream>
#include "TIndividuo.h"
class DataPackage {
	private:
		std::vector <TIndividuo *> *pvPoblacion;
		float *floatSumAdaptacion;
	public:
		friend std::ostream & operator << (std::ostream & os, const DataPackage & dp);
		/*
		ostream & operator << (ostream & os, const DataPackage & dp) {
			os << '(' << ',' <<')';
			return os;
		};
		*/
		DataPackage(void){;}
		void AjustarPoblacion(std::vector<TIndividuo *> *pvPoblacionExaminar) {pvPoblacion=pvPoblacionExaminar;}
		void AjustarPoblacion(std::vector<TIndividuo *> *pvPoblacionExaminar, float *fSumAdap) {
			pvPoblacion=pvPoblacionExaminar; floatSumAdaptacion=fSumAdap; }
		void Individuos(void);
		void SumAdaptacion(void);
		//DataPackage(float, float, float)
		//std::vector<TGen> *Cromosoma;
		//float floatAdaptacion;
		//float floatPuntuacion;
		//float floatSumAdaptacion;
};

#endif

