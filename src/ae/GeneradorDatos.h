#ifndef GENERADOR_DATOS_H
#define GENERADOR_DATOS_H
#include <vector>
#include <string>
#include "eda/TAula.h"
#include "eda/TProfesor.h"
#include "eda/TAsignatura.h"
#include "eda/TCostAsigProf.h"
#include "eda/TCostHoraProf.h"
class GeneradorDatos {
	private:
		//std::vector<TProfesor> vProfesores;
		//std::vector<TAula> vAulas;
		TCostAsigProf *GenpCostAsigProf(std::string, int, int);
		std::vector<TAsignatura> vAsignaturas;

	public:
		GeneradorDatos();
		std::vector<TAula> *VectorTAula(void);
		std::vector<TProfesor> *VectorTProfesor(void);
		std::vector<TAsignatura> * VectorTAsignatura(void);
};


#endif

