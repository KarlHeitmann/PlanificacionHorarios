#include <iostream>
#include "TIndividuo.h"


int main (int argc, char **argv) {
	
	TIndividuo Individuo(5.5, 2.5, 3.0);
	//std::cout << TIndividuo.Display();
	Individuo.Display();
	TIndividuo Indiv2;
	Indiv2.Display();
	return 0;
}

