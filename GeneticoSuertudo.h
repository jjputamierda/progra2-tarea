#ifndef ALGORITMOGENETICOSUERTUDO
#define ALGORITMOGENETICOSUERTUDO
#include "Poblacion.h"
#include "Algoritmo.h"
#include<ctime>
//#define PROBABILIDAD_MUTUACION 15
class GeneticoSuertudo: public Algoritmo {
	public:
	   GeneticoSuertudo();
       Poblacion * evolucionar( Poblacion * );
};

#endif