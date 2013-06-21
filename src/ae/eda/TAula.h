#ifndef TAULA_H
#define TAULA_H

#include <string>
#include <vector>

class TAula {
	private:
		std::string strNombre;
		std::vector<std::string> vstrHorario;
	public:
		TAula(std::string);
		void PutStrHorario(std::string);
		std::string GetSummary();
};

#endif
