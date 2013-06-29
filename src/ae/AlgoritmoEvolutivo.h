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
		float floatProbabilidaDeCruce;
		float floatTasaDeMutacion;

		unsigned uintLargoCromosoma;
		GeneradorDatos DataGen;
		std::vector<TIndividuo *> *pvPoblacion;
		std::vector<TAula> *pvAulas;
		std::vector<TAsignatura> * pvAsignaturas;
		std::vector<TProfesor> * pvProfesores;

		//Metodos privados
		std::vector<TIndividuo *> *InitPob(void);
	public:
		AlgoritmoEvolutivo(unsigned);
		AlgoritmoEvolutivo(unsigned, unsigned, float, float);
		void Run(void);
		void Seleccion(void);
		void Evaluacion(void);
		void EvaluacionFast(void);
		void Reproduccion(void);
		void Mutacion(void);
};



#endif
