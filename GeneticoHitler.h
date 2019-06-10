#ifndef ALGORITMOGENETICOHITLER
#define ALGORITMOGENETICOHITLER
#include "Poblacion.h"
#include "Algoritmo.h"
#include<ctime>
#define PROBABILIDAD_MUTUACION 15
class GeneticoHitler: public Algoritmo {
	public:
	   GeneticoHitler();
       Poblacion * evolucionar( Poblacion * );
};

#endif