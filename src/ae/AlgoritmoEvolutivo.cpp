#include <vector>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "AlgoritmoEvolutivo.h"
#include "TIndividuo.h"
#include "CandidatoHorario.h"
#include "TGen.h"
#include "GeneradorDatos.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"
#define AE_VERBOSE 0
#define RND (float)rand()/(float)RAND_MAX
AlgoritmoEvolutivo::AlgoritmoEvolutivo(unsigned _uintPoblacion, unsigned _uintNGeneraciones, float _floatProbabilidaDeCruce,
		float _floatTasaDeMutacion) {
	//srand(time(NULL));
	GeneradorDatos DataGen;
	pvAulas = DataGen.VectorTAula();
	pvAsignaturas = DataGen.VectorTAsignatura();
	pvProfesores = DataGen.VectorTProfesor();
	uintLargoCromosoma = (*pvAsignaturas).size();

	uintPoblacion = _uintPoblacion;
	uintNGeneraciones = _uintNGeneraciones;
	floatProbabilidaDeCruce = _floatProbabilidaDeCruce;
	floatTasaDeMutacion = _floatTasaDeMutacion;
	floatSumAdaptacion=0.0;
	uintPosMejor=0;
	floatAdapMejor = 1000.0;
	
	InitPob();
	EvaluacionFast();

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

//Coleccion metodos privados
std::vector<TIndividuo *> *AlgoritmoEvolutivo::InitPob(){
	//std::vector<TIndividuo *> *pvPoblacion;
	pvPoblacion=new std::vector<TIndividuo *>();
	
	CandidatoHorario *pCH;
	//Genera poblacion inicial
	//std::cout << "____Poblacion_INICIAL___\n";
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH=new CandidatoHorario;
		pCH->GenerarGenotipo(pvAulas, pvProfesores, pvAsignaturas);
		//std::cout << "Individuo " << i << " | Adaptacion: " << pCH->GetAdaptacion() << "\n";

		//std::cout << "__________________________\nIndividuo: " << i <<"\nAdaptacion: " << pCH->floatAdaptacion << "\n";
		floatSumAdaptacion += pCH->GetAdaptacion();
		//Se trata de un problema de minimizacion: la adaptacion mas baja es la
		//mejor
		if (floatAdapMejor > pCH->GetAdaptacion()) {
			uintPosMejor=i;
			floatAdapMejor=pCH->GetAdaptacion();
		}
		pvPoblacion->push_back(pCH);
	}
	return pvPoblacion;
}

//Coleccion metodos publicos
void AlgoritmoEvolutivo::Run() {
	//std::cout << "floatSumAdaptacion: " << floatSumAdaptacion << "\n";
	//std::cout << "Adap mejor: " << floatAdapMejor <<"\nPosicion mejor: " << uintPosMejor << "\n";
	//Entra al loop de evolucion
	//Evaluacion
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
		Seleccion();
		Reproduccion();
		Mutacion();
		Evaluacion();
		//std::cout << "floatSumAdaptacion: " << floatSumAdaptacion << "\n";
		//std::cout << "Adap mejor: " << floatAdapMejor <<"\nPosicion mejor: " << uintPosMejor << "\n";
		//std::cout << "**************************\n";
	}
	
}
void AlgoritmoEvolutivo::Seleccion () {
	std::vector<TIndividuo *> vPobAux;
	unsigned uintSelSuper[uintPoblacion];
	unsigned uintEscogido;
	float floatProb;
	vPobAux.reserve(uintPoblacion);
	//std::cout << "______SELECCION______\n";
	for (unsigned i=0; i<uintPoblacion; i++) {
		//std::cout << "Individuo " << i << " | Adaptacion: " << (*pvPoblacion)[i]->GetAdaptacion() << "\n";
		floatProb = RND;
		uintEscogido=0;
		while ((floatProb > (*pvPoblacion)[uintEscogido]->GetPuntAcum()) 
				&& (uintEscogido < (uintPoblacion-1)))
			uintEscogido++;
		uintSelSuper[i]=uintEscogido;
		//std::cout << "Individuo " << i <<" | Score: " << (*pvPoblacion)[i].GetPuntuacion() <<
		//	" | Seleccionado: " << uintEscogido << "\n";
	}
	for (unsigned i=0; i< uintPoblacion; i++) {
		vPobAux[i]=(*pvPoblacion)[uintSelSuper[i]];
	}
	for (unsigned i=0; i< uintPoblacion; i++) {
		(*pvPoblacion)[i]=vPobAux[i];
		//std::cout << "Individuo " << i <<" | Score: " << (*pvPoblacion)[i].GetPuntuacion() << "\n";
	}
}
void AlgoritmoEvolutivo::Reproduccion () {
	unsigned arrayuintSeleccionadoCruce[uintPoblacion];
	unsigned uintNumSeleccionados=0;
	unsigned uintPuntoCruce;
	std::vector<TGen> CromosomaAux1;
	std::vector<TGen> CromosomaAux2;
	TIndividuo *pCH;
	float floatRollDice;
	
	//Tira los dados para escoger los individuos a cruzar
	for (unsigned i=0; i<uintPoblacion; i++) {
		floatRollDice = RND;
		if (floatRollDice < floatProbabilidaDeCruce) {
			arrayuintSeleccionadoCruce[uintNumSeleccionados] = i;
			uintNumSeleccionados++;
		}
	}
	//Si se ha seleccionado un numero impar de individuos, se resta uno
	if ((uintNumSeleccionados % 2) == 1)
		uintNumSeleccionados--;

	//Se escoge un punto de cruce aleatorio
	uintPuntoCruce=(unsigned) rand() % uintLargoCromosoma ;
	//std::cout << "Punto de cruce: " << uintPuntoCruce << "\n";	
	//std::cout << "NumSeleccionados: " << uintNumSeleccionados << "\n\n";
	for (unsigned i=0; i<=(uintNumSeleccionados/2) ; i+=2) {
		//std::cout << "__________________________\nIndividuo: " << i <<"\nAdaptacion: " << (*pvPoblacion)[i]->floatAdaptacion << "\n";
		//std::cout << "__________________________\nIndividuo: " << i+1 <<"\nAdaptacion: " << (*pvPoblacion)[i+1]->floatAdaptacion << "\n";
		//std::cout << "\n.......Reproduccion.......\n\n";
		CromosomaAux1 = (*pvPoblacion)[i]->GetCromosoma();
		CromosomaAux2 = (*pvPoblacion)[i+1]->GetCromosoma();
		(*pvPoblacion)[i]->ReproducirA(CromosomaAux2, uintPuntoCruce);
		(*pvPoblacion)[i+1]->ReproducirB(CromosomaAux1, uintPuntoCruce);
		//std::cout << "Individuo: " << i <<"\nAdaptacion: " << (*pvPoblacion)[i]->floatAdaptacion << "\n";
		//std::cout << "__________________________\nIndividuo: " << i+1 <<"\nAdaptacion: " << (*pvPoblacion)[i+1]->floatAdaptacion << "\n";
		//std::cout << "<<<<<<SIGUIENTE PAREJA>>>>>>>>\n";
	}
}

void AlgoritmoEvolutivo::Mutacion () {
	for (unsigned i=0; i<uintPoblacion; i++) {
		(*pvPoblacion)[i]->Mutar(floatTasaDeMutacion, pvAulas, pvProfesores, pvAsignaturas);
	}
}

void AlgoritmoEvolutivo::Evaluacion () {
	TIndividuo *pCH;
	float floatPuntAcu=0.0;
	float floatPuntuacion;
	floatSumAdaptacion=0.0;
	for (unsigned i=0; i<uintPoblacion; i++) {
		floatSumAdaptacion+=(*pvPoblacion)[i]->GetAdaptacion();
	}
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH = (*pvPoblacion)[i];
		floatPuntuacion = pCH->GetAdaptacion() / floatSumAdaptacion;
		floatPuntAcu += floatPuntuacion;
		pCH->SetPuntuacionAcumulada(floatPuntAcu);
		pCH->SetPuntuacion(floatPuntuacion);
	}
#if 0
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH = &(*pvPoblacion)[i];
		std::cout << "________________\nIndividuo " << i 
			<< "\nAdaptacion: " << pCH->GetAdaptacion() 
			<< "\nPuntuacion: " << pCH->GetPuntuacion() 
			<< "\nPuntuacion Acumulada: " << pCH->GetPuntAcum() <<  "\n";
	}
#endif	
}
void AlgoritmoEvolutivo::EvaluacionFast () {
	TIndividuo *pCH;
	float floatPuntAcu=0.0;
	float floatPuntuacion;
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH = (*pvPoblacion)[i];
		floatPuntuacion = pCH->GetAdaptacion() / floatSumAdaptacion;
		floatPuntAcu += floatPuntuacion;
		pCH->SetPuntuacionAcumulada(floatPuntAcu);
		pCH->SetPuntuacion(floatPuntuacion);
	}
#if 0
	for (unsigned i=0; i<uintPoblacion; i++) {
		pCH = &(*pvPoblacion)[i];
		std::cout << "________________\nIndividuo " << i 
			<< "\nAdaptacion: " << pCH->GetAdaptacion() 
			<< "\nPuntuacion: " << pCH->GetPuntuacion() 
			<< "\nPuntuacion Acumulada: " << pCH->GetPuntAcum() <<  "\n";
	}
#endif	
}
void AlgoritmoEvolutivo::Log() {
	std::cout << "floatSumAdaptacion: " << floatSumAdaptacion << "\n";
	//std::cout << "Adap mejor: " << floatAdapMejor <<"\nPosicion mejor: " << uintPosMejor << "\n";
	std::cout << "**************************\n"; 
}

void AlgoritmoEvolutivo::AmarrarDP (DataPackage *pDP) {
	pDP->AjustarPoblacion(pvPoblacion);

}

