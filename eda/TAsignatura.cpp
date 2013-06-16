 
#include <string>
#include "TAsignatura.h"

TAsignatura::TAsignatura(std::string _strNombre, int _intCodigo, int _intPosProf) {
	intPosProf=_intPosProf;
	intCodigo =_intCodigo ;
	strNombre =_strNombre ;
}
std::string GetNombre() {
	return strNombre;
}
int GetCodigo() {
	return intCodigo;
}
int GetPosProf() {
	return intPosProf;
}



