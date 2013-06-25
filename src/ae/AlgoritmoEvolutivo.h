#ifndef ALGORITMO_EVOLUTIVO_H
#define ALGORITMO_EVOLUTIVO_H
#include <vector>
#include "TIndividuo.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"
#include "eda/TAsignatura.h"
#include "GeneradorDatos.h"
class AlgoritmoEvolutivo {
	private:
		unsigned uintPoblacion;
		unsigned uintNGeneraciones;
		unsigned uintPosMejor;
		float floatAdapMejor;
		float floatSumAdaptacion;

		GeneradorDatos DataGen;
		std::vector<TIndividuo> *pvIndividuos;
		std::vector<TAula> *pvAulas;
		std::vector<TAsignatura> * pvAsignaturas;
		std::vector<TProfesor> * pvProfesores;
	public:
		AlgoritmoEvolutivo(unsigned);
		AlgoritmoEvolutivo(unsigned, unsigned);
		void Run(void);
		void Seleccion(std::vector<TIndividuo> *pvPoblacion);
		void Evaluacion(std::vector<TIndividuo> *pvPoblacion);
};



#endif
