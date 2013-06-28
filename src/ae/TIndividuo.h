#ifndef TINDIVIDUO_H
#define TINDIVIDUO_H

#include <vector>
#include <string>
#include <iostream>
#include "TGen.h"
#include "eda/TAsignatura.h"
#include "eda/TAula.h"
#include "eda/TProfesor.h"

class TIndividuo {
#if 0
	private:
		float floatAdaptacion;
		float floatPuntuacion;
		float floatPuntAcu;
#endif
	public:
		//std::vector<TGen> vGenes;
		TIndividuo();
		TIndividuo(float, float, float);
		virtual void Display(void);
		virtual void ActualizarAdaptacion(void) {;}
		float GetAdaptacion(void);
		void SetPuntuacionAcumulada(float);
		void SetPuntuacion(float);
		float GetPuntuacion() {return floatPuntuacion; }
		float GetPuntAcum() {return floatPuntAcu; }
		
		// Atributos
		float floatAdaptacion;
		float floatPuntuacion;
		float floatPuntAcu;

		//Metodos stub
		virtual void GenerarGenotipo(std::vector<TAula> *p1, std::vector<TProfesor> *p2, std::vector<TAsignatura> *p3) {;}
		virtual std::vector<TGen> GetCromosoma(void) {;}
		virtual void ReproducirA(std::vector<TGen> Pareja) {std::cout << "Soy clase base reproducir A!";}
		virtual void ReproducirB(std::vector<TGen> Pareja) {std::cout << "Soy clase base reproducir B!";}
		virtual void ReproducirA(std::vector<TGen> Pareja, unsigned) {std::cout << "Soy clase base reproducir A!";}
		virtual void ReproducirB(std::vector<TGen> Pareja, unsigned) {std::cout << "Soy clase base reproducir B!";}
};

#endif

