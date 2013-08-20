#include <iostream>
#include "DataPackage.h"


void DataPackage::Individuos() {
	for (unsigned i=0; i<pvPoblacion->size(); i++) {
		//std::cout << "log individuo: " << i << "\n";
		std::cout << "Individuo " << i << " | Adaptacion: " << (*pvPoblacion)[i]->GetAdaptacion() << "\n";
	}
}
void DataPackage::SumAdaptacion() {
	std::cout << "Suma Adaptacion: " << *floatSumAdaptacion <<"\n";
}
