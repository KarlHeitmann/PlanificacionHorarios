#ifndef TPROFESOR_H
#define TPROFESOR_H

#include <string>
#include <vector>
#include "TCostAsigProf.h"
#include "TCostHoraProf.h"

class TProfesor {
	private:
		std::string strNombre;
		int intCodigo;
		std::vector<TCostAsigProf> LCostAsigProf;
	public:
		//Nombre Profe, CodigoProfe
		TProfesor(std::string, int);
		TProfesor(const char*, int);
		//Coloca objeto CostAsigProf en su lista
		void PutCostAsigProf(TCostAsigProf);
		//Busca el codigo de la asignatura dentro de la lista que tiene
		unsigned FindAsigPos(int intCodAsig);
		//Muestra informacion simple completa
		std::string GetSummary();
		int GetCodProf();
		std::string GetNombre();

		//int GetHorarioDisponibleDeAsignaturaSize(unsigned);
		unsigned EscogeHorarioDisplonibleDeAsignatura(unsigned);
		TCostHoraProf *EscogeCostHoraProf(unsigned);
};

#endif
