#ifndef TASIGNATURA_H
#define TASIGNATURA_H

#include <string>
#include <vector>

class TAsignatura {
	private:
		std::string strNombre;
		int intCodigo;
		int intPosProf;
	public:
		TAsignaruta(std::string, int, int);
		std::string GetNombre();
		int GetCodigo();
		int GetPosProf();
};

#endif
