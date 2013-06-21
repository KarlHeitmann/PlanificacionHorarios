#include "TIndividuo.h"


class CandidatoHorario: public TIndividuo {
	public:
		CandidatoHorario();
		void Display(void);
		virtual void GenerarGenotipo(void);
};

