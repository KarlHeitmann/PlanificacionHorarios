#ifndef TINDIVIDUO_H
#define TINDIVIDUO_H

#include <vector>
#include <string>
#include "TGen.h"
#include "eda/TAsignatura.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"

class TIndividuo {
#if 0
	private:
		float floatAdaptacion;
		float floatPuntuacion;
		float floatPuntAcu;
#endif
	public:
		//std::vector<TGen> vGenes;
		TIndividuo();
		TIndividuo(float, float, float);
		void Display(void);
		float GetAdaptacion(void);
		void SetPuntuacionAcumulada(float);
		void SetPuntuacion(float);
		float GetPuntuacion() {return floatPuntuacion; }
		float GetPuntAcum() {return floatPuntAcu; }
		virtual void GenerarGenotipo(std::vector<TAula> *p1, std::vector<TProfesor> *p2, std::vector<TAsignatura> *p3);
		float floatAdaptacion;
		float floatPuntuacion;
		float floatPuntAcu;
};

#endif

