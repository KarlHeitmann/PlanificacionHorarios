#include <vector>
#include "TIndividuo.h"
#include "TGen.h"
#include "eda/TAsignatura.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"

class CandidatoHorario: public TIndividuo {
		//int ChooseHorario(std::vector<TCostHoraProf> *pvCostHoraProf);
#if 0
		virtual float floatAdaptacion;
		virtual float floatPuntuacion;
		virtual float floatPuntAcu;
#endif
		int ChooseHorario(int intSize);
		std::vector<TGen> Cromosoma;


	public:
		CandidatoHorario();
		void ActualizarAdaptacion();
		void Display(void);
		virtual void GenerarGenotipo(std::vector<TAula> *p1, std::vector<TProfesor> *p2, std::vector<TAsignatura> *p3 );
		virtual std::vector<TGen> GetCromosoma(void) { return Cromosoma; }
		virtual void ReproducirA(std::vector<TGen> Pareja); //XXX Aun no implementado
		virtual void ReproducirB(std::vector<TGen> Pareja); //XXX Aun no implementado
		virtual void ReproducirA(std::vector<TGen> Pareja, unsigned);
		virtual void ReproducirB(std::vector<TGen> Pareja, unsigned);
};

