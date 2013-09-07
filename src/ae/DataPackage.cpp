#include <iostream>
#include <ostream>
#include "DataPackage.h"


void DataPackage::Individuos() {
	for (unsigned i=0; i<pvPoblacion->size(); i++) {
		//std::cout << "log individuo: " << i << "\n";
		std::cout << "Individuo " << i << " | Adaptacion: " << (*pvPoblacion)[i]->GetAdaptacion() << "\n";
	}
}
std::ostream & operator<< (std::ostream &os, const DataPackage & dp) {
	os << "Suma Adaptacion: " << *dp.floatSumAdaptacion << "\n";
	return os;
}
void DataPackage::SumAdaptacion() {
	std::cout << "Suma Adaptacion: " << *floatSumAdaptacion <<"\n";
}
