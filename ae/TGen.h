#ifndef TGEN_H
#define TGEN_H

#include <string>

class TGen {
	private:
		int intCodAsig;
		int intCoste;
		std::string strHorario;
	public:
		TGen(int, int, std::string);
		int GetCoste();
		int GetCodAsig();
		std::string GetHorario();
}



#endif



