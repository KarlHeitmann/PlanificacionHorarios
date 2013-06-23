#include <vector>
#include "TIndividuo.h"
#include "eda/TAsignatura.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"

class CandidatoHorario: public TIndividuo {
		//int ChooseHorario(std::vector<TCostHoraProf> *pvCostHoraProf);
		int ChooseHorario(int intSize);
		std::vector<TGen> Cromosoma;
	public:
		CandidatoHorario();
		void Display(void);
		virtual void GenerarGenotipo(std::vector<TAula> *p1, std::vector<TProfesor> *p2, std::vector<TAsignatura> *p3 );
};

