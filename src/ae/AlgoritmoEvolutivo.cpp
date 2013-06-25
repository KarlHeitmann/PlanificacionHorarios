#include <vector>
#include <iostream>
#include "AlgoritmoEvolutivo.h"
#include "TIndividuo.h"
#include "CandidatoHorario.h"
#include "GeneradorDatos.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"
#define AE_VERBOSE 0
AlgoritmoEvolutivo::AlgoritmoEvolutivo(unsigned _uintPoblacion, unsigned _uintNGeneraciones) {
	GeneradorDatos DataGen;
	pvAulas = DataGen.VectorTAula();
	pvAsignaturas = DataGen.VectorTAsignatura();
	pvProfesores = DataGen.VectorTProfesor();
	uintPoblacion = _uintPoblacion;
	uintNGeneraciones = _uintNGeneraciones;
	floatSumAdaptacion=0.0;
	uintPosMejor=0;
	floatAdapMejor = 1000.0;
#if AE_VERBOSE > 0
	std::cout << "---Recorriendo vector Aulas---\n";
	for (unsigned i=0; i<pvAulas->size(); i++) {
		std::cout << (*pvAulas)[i].GetSummary();
	}
	std::cout << "---Recorriendo vector Profesores---\n";
	for (unsigned i=0; i<pvProfesores->size(); i++) {
		std::cout << (*pvProfesores)[i].GetSummary();
	}
	std::cout << "---Recorriendo vector Asignaturas---\n";
	for (unsigned i=0; i<pvAsignaturas->size(); i++) {
		std::cout << (*pvAsignaturas)[i].GetNombre() << "\n";
	}
#endif
}

void AlgoritmoEvolutivo::Run() {
	pvIndividuos = new std::vector<TIndividuo>();	
	TIndividuo *pCH;
	//Genera poblacion inicial
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH=new CandidatoHorario;
		pCH->GenerarGenotipo(pvAulas, pvProfesores, pvAsignaturas);
		std::cout << "__________________________\nIndividuo: " << i <<"\nAdaptacion: " << pCH->floatAdaptacion << "\n";
		floatSumAdaptacion += pCH->GetAdaptacion();
		//Se trata de un problema de minimizacion: la adaptacion mas baja es la
		//mejor
		if (floatAdapMejor > pCH->GetAdaptacion()) {
			uintPosMejor=i;
			floatAdapMejor=pCH->GetAdaptacion();
		}
		pvIndividuos->push_back(*pCH);
		delete pCH;
	}
	std::cout << "floatSumAdaptacion: " << floatSumAdaptacion << "\n";
	std::cout << "Adap mejor: " << floatAdapMejor <<"\nPosicion mejor: " << uintPosMejor << "\n";
	//Entra al loop de evolucion
	//Evaluacion
	Evaluacion(pvIndividuos);
	for (unsigned i=0; i<uintNGeneraciones; i++) {
		//Seleccion (Pob, paramentros) 
		//Selecciona a los supervivientes de la poblacion
		//Genera una poblacion del mismo tamanio, pero solo con individuos
		//seleccionados
		//
		//Reproduccion (Pob, tam_pob, lcrom, prob_mut)
		//Toma los individuos seleccionados y selecciona aleatoriamente parejas
		//a cruzar. Genera nueva poblacion
		//
		//Mutacion (pob, tam_pob, lcrom, prob_mut)
		//Selecciona algunos individuos de la poblacion actual y les aplica
		//pequenias mutaciones
		//
		//Evaluacion (pob, tam_pob, lcrom, prob_mut)
		//Evalua la nueva poblacion generada
		Seleccion(pvIndividuos);
	}
	
}
void AlgoritmoEvolutivo::Seleccion (std::vector<TIndividuo> *pvPoblacion) {
	;
}
void AlgoritmoEvolutivo::Evaluacion (std::vector<TIndividuo> *pvPoblacion) {
	TIndividuo *pCH;
	float floatPuntAcu=0.0;
	float floatPuntuacion;
	//std::cout << "---------------------------\n";	
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH = &(*pvPoblacion)[i];
		floatPuntuacion = pCH->GetAdaptacion() / floatSumAdaptacion;
		floatPuntAcu += floatPuntuacion;
		pCH->SetPuntuacionAcumulada(floatPuntAcu);
		pCH->SetPuntuacion(floatPuntuacion);
		//std::cout << "Individuo " << i << " |Adaptacion: " << pCH->GetAdaptacion()<<"\n";
	}
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH = &(*pvPoblacion)[i];
		std::cout << "________________\nIndividuo " << i 
			<< "\nAdaptacion: " << pCH->GetAdaptacion() 
			<< "\nPuntuacion: " << pCH->GetPuntuacion() 
			<< "\nPuntuacion Acumulada: " << pCH->GetPuntAcum() <<  "\n";
	}	
}
