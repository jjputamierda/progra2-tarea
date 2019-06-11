#ifndef ALGORITMODRAGONBASICO
#define ALGORITMODRAGONBASICO
#include "Poblacion.h"
#include "Algoritmo.h"
#include<ctime>
#define PROBABILIDAD_MUTUACION 15
class DragonBasico: public Algoritmo {
	public:
	   DragonBasico();
       Poblacion * evolucionar( Poblacion * );
};

#endif
