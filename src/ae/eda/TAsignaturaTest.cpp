#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include "TAsignatura.h"

int main (int argc, char **argv) {
	
	srand(time(NULL));
	std::vector<TAsignatura> vAsignaruta;
	TAsignatura Asignatura("POO", 329, 2);

	std::cout << Asignatura.GetNombre() <<"\n";
	std::cout << Asignatura.GetCodigo() <<"\n";
	std::cout << Asignatura.GetPosProf() <<"\n";


	return 0;
}
