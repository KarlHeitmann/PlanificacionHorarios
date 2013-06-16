#include <string>
#include <vector>
#include "TAula.h"
TAula::TAula(std::string _strNombre) {
	strNombre=_strNombre;
}
void TAula::PutStrHorario(std::string strHorario) {
	vstrHorario.push_back(strHorario);
}
std::string TAula::GetSummary() {
	std::string strHorario="";

	for (int i=0; i<vstrHorario.size(); i++) {
		strHorario += vstrHorario[i] + "\n";
	}	
	return strHorario;
}


