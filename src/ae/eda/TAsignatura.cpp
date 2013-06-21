 
#include <string>
#include "TAsignatura.h"

TAsignatura::TAsignatura(std::string _strNombre, int _intCodigo, int _intPosProf) {
	intPosProf=_intPosProf;
	intCodigo =_intCodigo ;
	strNombre =_strNombre ;
}
std::string TAsignatura::GetNombre() {
	return strNombre;
}
int TAsignatura::GetCodigo() {
	return intCodigo;
}
int TAsignatura::GetPosProf() {
	return intPosProf;
}



